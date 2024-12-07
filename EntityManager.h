#pragma once

#include "Entity.h"
#include <vector>
#include <map>
#include <algorithm>

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager
{
	EntityVec m_entities;
	EntityVec m_entitiesToAdd;
	EntityMap m_entityMap;
	size_t m_totalEntities = 0;

public:

	EntityManager();

	void removeDeadEntities(EntityVec& vec);

	void update();

	std::shared_ptr<Entity> addEntity(const std::string& tag);

	const EntityVec& getEntities() const;
	const EntityVec& getEntities(const std::string& tag) const;
	const std::map<std::string, EntityVec>& getEntityMap() const;
};