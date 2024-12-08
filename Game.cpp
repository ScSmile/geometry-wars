#include "Game.hpp"

Game::Game(const std::string& config)
{
	init(config);
}

void Game::init(const std::string& path)
{
	initConfig(std::ifstream(path));

	//sf::Style::Fullscreen = 8, sf::Style::Default = 7 -> style = 7 + m_winConfig.FS
	m_window.create(sf::VideoMode(m_winConfig.W, m_winConfig.H), "Geometry Wars", 7 + m_winConfig.FS);

	m_window.setFramerateLimit(m_winConfig.Fl);

	if (!m_font.loadFromFile(m_fontConfig.N))
	{
		std::cerr << "Could not load font!\n";
		exit(-1);
	}

	spawnPlayer();

	m_text = sf::Text("Score: 0", m_font, m_fontConfig.S);
	m_text.setFillColor(sf::Color(m_fontConfig.R, m_fontConfig.G, m_fontConfig.B));
	m_text.setPosition(5, 5);
	ImGui::SFML::Init(m_window);
}

void Game::initConfig(std::ifstream&& fin)
{
	std::string next;

	fin >> next >> m_winConfig.W >> m_winConfig.H >> m_winConfig.Fl >> m_winConfig.FS;
	fin >> next >> m_fontConfig.N >> m_fontConfig.S >> m_fontConfig.R >> m_fontConfig.G >> m_fontConfig.B;
	fin >> next >> m_playerConfig.SR >> m_playerConfig.CR >> m_playerConfig.S
		>> m_playerConfig.FR >> m_playerConfig.FG >> m_playerConfig.FB
		>> m_playerConfig.OR >> m_playerConfig.OG >> m_playerConfig.OB
		>> m_playerConfig.OT >> m_playerConfig.V;
	fin >> next >> m_enemyConfig.SR >> m_enemyConfig.CR >> m_enemyConfig.SMIN >> m_enemyConfig.SMAX
		>> m_enemyConfig.OR >> m_enemyConfig.OG >> m_enemyConfig.OB >> m_enemyConfig.OT
		>> m_enemyConfig.VMIN >> m_enemyConfig.VMAX >> m_enemyConfig.L >> m_enemyConfig.SI;
	fin >> next >> m_bulletConfig.SR >> m_bulletConfig.CR >> m_bulletConfig.S
		>> m_bulletConfig.FR >> m_bulletConfig.FG >> m_bulletConfig.FB
		>> m_bulletConfig.OR >> m_bulletConfig.OG >> m_bulletConfig.OB
		>> m_bulletConfig.OT >> m_bulletConfig.V >> m_bulletConfig.L;
}

void Game::run()
{
	while (m_running)
	{
		ImGui::SFML::Update(m_window, m_deltaClock.restart());

		if (!m_paused)
		{
			m_entities.update();

			if (m_flags.ES) sEnemySpawner();
			if (m_flags.M) sMovement();
			if (m_flags.C) sCollision();
			if (m_flags.L) sLifespan();
		}
		if (!m_player->isActive())
		{
			spawnPlayer();
		}
		if (m_flags.UI) sUserInput();
		if (m_flags.GUI) sGUI();
		if (m_flags.R) sRender();

		ImGui::SFML::Render(m_window);
		m_window.display();

		++m_currentFrame ;
	}
}


void Game::spawnPlayer()
{
	auto entity = m_entities.addEntity("player");

	entity->cTransform = std::make_shared<CTransform>(
		Vec2(m_winConfig.W / 2.0f, m_winConfig.H / 2.0f), 
		Vec2(0.0f, 0.0f), 0.5f
	);
  
	entity->cShape = std::make_shared<CShape>(
		m_playerConfig.SR , 
		m_playerConfig.V, 
		sf::Color(m_playerConfig.FR, m_playerConfig.FG, m_playerConfig.FB),
		sf::Color(m_playerConfig.OR, m_playerConfig.OG, m_playerConfig.OB),
		m_playerConfig.OT
	);
	
	entity->cInput = std::make_shared<CInput>();

	entity->cCollision = std::make_shared<CCollision>(m_playerConfig.CR);

	entity->cScore = std::make_shared<CScore>(0);

	m_player = entity;
}

void Game::spawnEnemy()
{
	using namespace std::chrono;
	srand(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());

	auto enemy = m_entities.addEntity("enemy");
	float angle = (rand() / (float)RAND_MAX) * 2 * PI;
	int verticies = m_enemyConfig.VMIN + rand() % (m_enemyConfig.VMAX - m_enemyConfig.VMIN + 1);

	enemy->cTransform = std::make_shared<CTransform>(
		Vec2(
			(float)(m_enemyConfig.SR + rand() % (m_winConfig.W - 2 * m_enemyConfig.SR + 1)),
			(float)(m_enemyConfig.SR + rand() % (m_winConfig.H - 2 * m_enemyConfig.SR + 1))),
		Vec2(
			m_enemyConfig.SMIN + rand() % ((int)m_enemyConfig.SMAX - (int)m_enemyConfig.SMIN + 1),
			0).rotate(angle),
		angle
		);
	enemy->cShape = std::make_shared<CShape>(
		m_enemyConfig.SR,
		verticies,
		sf::Color(rand() % 256, rand() % 256, rand() % 256),
		sf::Color(m_enemyConfig.OR, m_enemyConfig.OG, m_enemyConfig.OB),
		m_enemyConfig.OT);
	enemy->cCollision = std::make_shared<CCollision>(m_enemyConfig.CR);
	enemy->cScore = std::make_shared<CScore>(100 * verticies);

	m_lastEnemySpawnTime = m_currentFrame;
}

void Game::spawnSmallEnemies(std::shared_ptr<Entity> e)
{
	sf::CircleShape& e_circle = e->cShape->circle;
	Vec2 e_velocity(e->cTransform->velocity.x, e->cTransform->velocity.y);

	if (e_velocity.length() == 0)
	{
		e_velocity = Vec2(1.0f, 0.0f);
	}
	else
	{
		e_velocity.normalize();
	}

	std::shared_ptr<Entity> s_enemy = 0;
	auto shape = std::make_shared<CShape>(
		e_circle.getRadius() / 2,
		e_circle.getPointCount(),
		e_circle.getFillColor(),
		e_circle.getOutlineColor(),
		e_circle.getOutlineThickness() / 2
	);
	auto collision = std::make_shared<CCollision>(e->cCollision->radius / 2);
	auto score = std::make_shared<CScore>(e->cScore->score * 2);

	size_t verticies = e_circle.getPointCount();
	for (size_t i = 0; i < verticies; ++i)
	{
		s_enemy = m_entities.addEntity("enemy");
		s_enemy->cTransform = std::make_shared<CTransform>(
			e->cTransform->pos,
			e_velocity,
			e->cTransform->angle
		);
		s_enemy->cShape = shape;
		s_enemy->cLifespan = std::make_shared<CLifespan>(120);
		s_enemy->cCollision = collision;
		s_enemy->cScore = score;

		e_velocity.rotate(2 * PI / verticies);
	}
}

void Game::spawnBullet(std::shared_ptr<Entity> e, const Vec2& target)
{
	auto entity = m_entities.addEntity("bullet");

	entity->cTransform = std::make_shared<CTransform>(
		Vec2(e->cTransform->pos.x, e->cTransform->pos.y),
		Vec2(
			target.x - e->cTransform->pos.x, 
			target.y - e->cTransform->pos.y).normalize() * m_bulletConfig.S,
		0.0f);

	entity->cShape = std::make_shared<CShape>(
		m_bulletConfig.SR,
		m_bulletConfig.V,
		sf::Color(m_bulletConfig.FR, m_bulletConfig.FG, m_bulletConfig.FB), 
		sf::Color(m_bulletConfig.OR, m_bulletConfig.OG, m_bulletConfig.OB),
		m_bulletConfig.OT
	);
	entity->cLifespan = std::make_shared<CLifespan>(m_bulletConfig.L);
	entity->cCollision = std::make_shared<CCollision>(m_bulletConfig.CR);
}

void Game::boundsCollision(std::shared_ptr<Entity> e) const
{
	if (e->cTransform->pos.x - e->cCollision->radius < 0)
	{
		e->cTransform->velocity.x *= -1;
		e->cTransform->pos.x = e->cCollision->radius;
	}
	if (e->cTransform->pos.x + e->cCollision->radius > m_winConfig.W)
	{
		e->cTransform->velocity.x *= -1;
		e->cTransform->pos.x = m_winConfig.W - e->cCollision->radius;
	}
	if (e->cTransform->pos.y - e->cCollision->radius < 0)
	{
		e->cTransform->velocity.y *= -1;
		e->cTransform->pos.y = e->cCollision->radius;
	}
	if (e->cTransform->pos.y + e->cCollision->radius > m_winConfig.H)
	{
		e->cTransform->velocity.y *= -1;
		e->cTransform->pos.y = m_winConfig.H - e->cCollision->radius;
	}
}

void Game::updateScore(int score) {
	if(m_player) m_player->cScore->score = score;
	m_text.setString("Score: " + std::to_string(score));
}

void Game::sMovement()
{
	std::shared_ptr<CInput> input = m_player->cInput;

	m_player->cTransform->pos += Vec2(
		(float)(input->right - input->left),
		(float)(input->down - input->up)).normalize() * m_playerConfig.S;

	for (auto& e : m_entities.getEntities())
	{
		if (e->cTransform)
		{
			e->cTransform->pos.x += e->cTransform->velocity.x;
			e->cTransform->pos.y += e->cTransform->velocity.y;
		}
	}
}

void Game::sLifespan()
{
	const sf::Color *fill = 0, *outline = 0;

	for (auto& e : m_entities.getEntities())
	{
		if (e->cLifespan)
		{
			if (--(e->cLifespan->remaining) > 0)
			{
				fill = &(e->cShape->circle.getFillColor());

				e->cShape->circle
					.setFillColor(
					sf::Color(
						fill->r, fill->g, fill->b,
						255 * (e->cLifespan->remaining) / (e->cLifespan->total)));

				outline = &(e->cShape->circle.getOutlineColor());

				e->cShape->circle
					.setOutlineColor(
					sf::Color(
						outline->r, outline->g, outline->b,
						255 * (e->cLifespan->remaining) / (e->cLifespan->total)));
			}
			else e->destroy();
		}
	}
}

void Game::sCollision()
{
	float dist = 0.0f;
	for (auto& e : m_entities.getEntities("enemy"))
	{
		for (auto& b : m_entities.getEntities("bullet"))
		{
			dist = Vec2(
				b->cTransform->pos.x, 
				b->cTransform->pos.y).dist(
				   Vec2(
				e->cTransform->pos.x, 
				e->cTransform->pos.y));

			if ((b->cCollision->radius + e->cCollision->radius) > dist)
			{
				b->destroy();
				e->destroy();

				if (!e->cLifespan) spawnSmallEnemies(e);

				updateScore(m_player->cScore->score + e->cScore->score);
			}
		}

		if (!m_player->isActive()) continue;

		dist = Vec2(
			m_player->cTransform->pos.x, 
			m_player->cTransform->pos.y).dist(
			   Vec2(
			e->cTransform->pos.x, 
			e->cTransform->pos.y));

		if ((m_player->cCollision->radius + e->cCollision->radius) > dist)
		{
			updateScore(0);
			m_player->destroy();

			e->destroy();
		}

	}
	for (auto& e : m_entities.getEntities("enemy"))
	{
		boundsCollision(e);
	}
	if (m_player->isActive()) 
	{
		boundsCollision(m_player);
	}
}

void Game::sEnemySpawner()
{
	if (m_currentFrame - m_lastEnemySpawnTime >= m_enemyConfig.SI)
	{
		spawnEnemy();
	}
}

void Game::sGUI()
{
	int i = 0;
	ImGui::Begin("Geometry Wars");

	if (ImGui::BeginTabBar("##tab"))
	{
		if (ImGui::BeginTabItem("Systems"))
		{
			ImGui::Checkbox("Movement", &m_flags.M);
			ImGui::Checkbox("Lifespan", &m_flags.L);
			ImGui::Checkbox("Collision", &m_flags.C);
			ImGui::Checkbox("Render", &m_flags.R);
			ImGui::Checkbox("Enemy Spawn", &m_flags.ES);
			ImGui::SliderInt("Spawn Interval", &m_enemyConfig.SI, 0, 1000);
			if (ImGui::Button("Manual Spawn")) 
			{
				spawnEnemy();
			}
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Entity Manager"))
		{
			ImGui::PushItemWidth(-1);
			if (ImGui::CollapsingHeader("Entities") && ImGui::BeginListBox("##entities"))
			{
				for (auto& e : m_entities.getEntities())
				{
					if (ImGui::SmallButton(std::format("D##{}", i++).c_str())) 
					{
						e->destroy();
					}
					ImGui::SameLine();
					ImGui::Text(std::to_string(e->id()).c_str());
					ImGui::SameLine();
					ImGui::Text(e->tag().c_str());
					ImGui::SameLine();
					ImGui::Text(std::format("({},{})", 
							  (int)e->cShape->circle.getPosition().x, 
							  (int)e->cShape->circle.getPosition().y).c_str());
				}
				ImGui::EndListBox();
			}

			if (ImGui::CollapsingHeader("Entities by Tag"))
			{
				auto tab_it = std::views::keys(m_entities.getEntityMap());
				std::vector<std::string> tags = { tab_it.begin(), tab_it.end() };

				for (auto& tag : tags)
				{
					ImGui::PushItemWidth(-1);
					if (ImGui::CollapsingHeader(tag.c_str()) 
						&& ImGui::BeginListBox(std::format("##{}", tag).c_str()))
					{
						for (auto& e : m_entities.getEntityMap().at(tag))
						{
							if (ImGui::SmallButton(std::format("D##{}", i++).c_str())) 
							{
								e->destroy();
							}
							ImGui::SameLine();
							ImGui::Text(std::to_string(e->id()).c_str());
							ImGui::SameLine();
							ImGui::Text(e->tag().c_str());
							ImGui::SameLine();
							ImGui::Text(std::format("({},{})", 
								(int)e->cShape->circle.getPosition().x,
								(int)e->cShape->circle.getPosition().y).c_str());
						}
						ImGui::EndListBox();
					}
				}
			}
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();
}

void Game::sRender()
{
	m_window.clear();

	for (auto& e : m_entities.getEntities())
	{
		e->cShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);
		e->cTransform->angle += 1.0f;
		e->cShape->circle.setRotation(e->cTransform->angle);

		m_window.draw(e->cShape->circle);
	}
	m_window.draw(m_text);
}

void Game::sUserInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(m_window, event);

		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}

		if (event.type == sf::Event::KeyPressed && m_player)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				m_player->cInput->up = true;
				break;
			case sf::Keyboard::A:
				m_player->cInput->left = true;
				break;
			case sf::Keyboard::S:
				m_player->cInput->down = true;
				break;
			case sf::Keyboard::D:
				m_player->cInput->right = true;
				break;
			case sf::Keyboard::P:
				m_paused = !m_paused;
				break;
			case sf::Keyboard::Escape:
				m_running = false;
				break;
			default:
				break;
			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				m_player->cInput->up = false;
				break;
			case sf::Keyboard::A:
				m_player->cInput->left = false;
				break;
			case sf::Keyboard::S:
				m_player->cInput->down = false;
				break;
			case sf::Keyboard::D:
				m_player->cInput->right = false;
				break;
			default:
				break;
			}
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (ImGui::GetIO().WantCaptureMouse) { continue; }

			if (event.mouseButton.button == sf::Mouse::Left)
			{
				m_player->cInput->shoot = true;

				spawnBullet(m_player, Vec2(
					float(event.mouseButton.x), 
					float(event.mouseButton.y)));
			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				std::cout << "Right Mouse button Cliced at (" 
					<< event.mouseButton.x << "," << event.mouseButton.y << ")" << '\n';
				// TODO
			}
		}
	}
}