#ifndef CLASS_ENTITY_MANAGER
#define CLASS_ENTITY_MANAGER
#include <map>
#include <string>
#include <boost/uuid/uuid.hpp>
#include "entity.hpp"
#include <utility>

using namespace std;

namespace mud::entities
{
  template<typename T> Entity * createEntityType() { return new T(); }
  class EntityManager
  {
    typedef std::map<std::string, Entity*(*)()> map_type;
    private:
      static std::map<boost::uuids::uuid, Entity*> entities;
      static map_type* entityTypes;
    
    public:
      static void loadEntites(string entitiesFilePath);
      static Entity* createEntityInstance(std::string const& entityType); 
      static map_type * getEntityTypesMap();
  };
  
  template<typename T>
  class EntityManagerRegister : EntityManager {
    public:
      EntityManagerRegister(std::string const& entityType) { 
          getEntityTypesMap()->insert(std::make_pair(entityType, &createEntityType<T>));
      }
  };
}
#endif
