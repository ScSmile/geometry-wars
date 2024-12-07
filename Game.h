#pragma once

#include "Entity.h"
#include "EntityManager.h"

#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <format>
#include <ranges>

const float PI = 3.141592f;

struct WindowConfig { short W, H, Fl, FS; };
struct FontConfig { int S, R, G, B; std::string N; };
struct PlayerConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S; };
struct EnemyConfig { int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI; float SMIN, SMAX; };
struct BulletConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L; float S; };

struct SystemFlags { bool M = true, ES = true, C = true, UI = true, GUI = true, L = true, R = true; };

class Game
{
private:
	sf::RenderWindow m_window;
	EntityManager m_entities;
	std::shared_ptr<Entity> m_player;
	sf::Font m_font;
	sf::Text m_text;	// score
	WindowConfig m_winConfig;
	FontConfig m_fontConfig;
	PlayerConfig m_playerConfig;
	EnemyConfig m_enemyConfig;
	BulletConfig m_bulletConfig;
	SystemFlags m_flags;
	sf::Clock m_deltaClock;
	int m_score = 0;
	int m_currentFrame = 0;
	int m_lastEnemySpawnTime = 0;
	bool m_running = true;
	bool m_paused = false;

	void init(const std::string& path);
	void initConfig(std::ifstream&& fin);
	void spawnPlayer();
	void spawnEnemy();
	void spawnSmallEnemies(std::shared_ptr<Entity> e);
	void spawnBullet(std::shared_ptr<Entity> e, const Vec2& target);
	void updateScore(int score);
	void boundsCollision(std::shared_ptr<Entity> e) const;

	void sMovement();
	void sLifespan();
	void sCollision();
	void sEnemySpawner();
	void sGUI();
	void sRender();
	void sUserInput();

public:
	Game(const std::string& config);
	void run();
};