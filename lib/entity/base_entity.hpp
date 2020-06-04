#ifndef CLASS_BASE_ENTITY
#define CLASS_BASE_ENTITY

#include <string>
#include "lib/geo/rooms/base_room.h"
#include <boost/uuid/uuid.hpp>
#include "boost/json.hpp"
#include <boost/log/sources/severity_feature.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include "entity_manager.hpp"


using namespace std;
using namespace boost::uuids;
namespace src = boost::log::sources;
namespace json = boost::json;


namespace mud::entities
{
  enum severity_level
  {
    debug,
    info,
    warn,
    error,
    fatal
  };

  class BaseEntity : public Entity {
    public:
      BaseEntity();
      BaseEntity(uuid id);
      BaseEntity(uuid id, BaseRoom* location, string* name, string* description);
      BaseEntity(uuid id, BaseRoom* location);
      string* getName();
      string* getDescription();
      string toString() const;
      friend ostream& operator <<(ostream& outputStream, const BaseEntity& b);
      uuid getId();

      void setName(string* name);
      void setDescription(string* description);
      bool saveEntity();
      // virtual BaseEntity* loadEntity(FILE* entityFile);
      json::string toJsonString();

    // private:
    //   friend class boost::serialization::access;

    protected:
      string* description;
      string* name;
      uuid id;
      BaseRoom* location;
      src::severity_logger<severity_level> logger;

      virtual void toJson(json::object& jsonValue);
    
    private:
      static EntityManagerRegister<BaseEntity> registration;//("mud::entities::BaseEntity");
  };
}
#endif