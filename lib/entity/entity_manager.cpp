#include "entity_manager.hpp"
#include "entity.hpp"

extern string APPLICATION_DIRECTORY;

// EntityManager::~EntityManager()
// {
//   // Save all the entities to JSON files
//   for(auto const& [key, value] : entities)
//   {
//     value->saveEntity();
//   }
// }

using namespace mud::entities;
typedef std::map<std::string, Entity*(*)()> map_type;
map_type* EntityManager::entityTypes = nullptr;

void EntityManager::loadEntites(string entitiesFilePath)
{

}

map_type* EntityManager::getEntityTypesMap()
{
  if(entityTypes == nullptr)
  {
    entityTypes = new map_type;
  }
  return entityTypes;
}

Entity* EntityManager::createEntityInstance(std::string const& entityType)
{
  map_type::iterator it = getEntityTypesMap()->find(entityType);
  if(it == getEntityTypesMap()->end())
    return nullptr;
  return it->second();
}