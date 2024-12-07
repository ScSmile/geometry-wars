#include "EntityManager.h"

EntityManager::EntityManager() 
{
	m_entityMap["player"];
	m_entityMap["enemy"];
	m_entityMap["bullet"];
}

void EntityManager::update() 
{
	for (auto e : m_entitiesToAdd)
	{
		m_entities.push_back(e);
		m_entityMap[e->tag()].push_back(e);
	}
	m_entitiesToAdd.clear();

	removeDeadEntities(m_entities);

	for (auto& [tag, entityVec] : m_entityMap)
	{
		removeDeadEntities(entityVec);
	}
}

void EntityManager::removeDeadEntities(EntityVec& vec)
{
	EntityVec::iterator it = std::remove_if(vec.begin(), vec.end(), [](std::shared_ptr<Entity> e) { return !e->isActive(); });
	vec.erase(it, vec.end());
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
	m_entitiesToAdd.push_back(entity);
	return entity;
}

const EntityVec& EntityManager::getEntities() const
{
	return m_entities;
}

const EntityVec& EntityManager::getEntities(const std::string& tag) const
{
	return m_entityMap.at(tag);
}

const std::map<std::string, EntityVec>& EntityManager::getEntityMap() const
{
	return m_entityMap;
}

