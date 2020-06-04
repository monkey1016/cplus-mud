#ifndef CLASS_PLAYER_ENTITY
#define CLASS_PLAYER_ENTITY

#include <string>
#include "character_entity.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace boost::uuids;
using boost::property_tree::ptree;

namespace mud::entities
{
  class PlayerEntity : public CharacterEntity {
    public:
      PlayerEntity(uuid id, BaseRoom* location, string* name, string* description, int experience, int level);
      PlayerEntity(uuid id, BaseRoom* location, int maxHealth, int experience, int level);
      PlayerEntity(uuid id, BaseRoom* location);
      void levelUp();
      void addExp(int exp);

    protected:
      int experience = 0;
      int level = 1;

      friend class boost::serialization::access;
      // template<class Archive>
      // void serialize(Archive& archive, const unsigned int version);
      // void toJson(ptree& pt);
      virtual void toJson(json::object& jsonValue);
  };
}
#endif