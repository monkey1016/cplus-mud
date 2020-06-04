#include "player_entity.hpp"
#include "character_entity.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace boost::uuids;
using namespace mud::entities;
using boost::property_tree::ptree;

PlayerEntity::PlayerEntity(uuid id, BaseRoom* location, string* name, string* description, int experience, int level) : CharacterEntity(id, location, name, description)
{
  this->experience = experience;
  this->level = level;
}

PlayerEntity::PlayerEntity(uuid id, BaseRoom* location, int maxHealth, int experience, int level) : CharacterEntity(id, location, name, description, maxHealth)
{
  this->experience = experience;
  this->level = level;
}

// template<class Archive>
// void PlayerEntity::serialize(Archive& archive, const unsigned int version)
// {
//   archive & boost::serialization::base_object<CharacterEntity>(*this);
//   archive & experience;
//   archive & level;
// }

void PlayerEntity::toJson(json::object& obj)
{
  this->CharacterEntity::toJson(obj);
  obj.insert_or_assign("class", "mud::entities::PlayerEntity");
  obj.insert_or_assign("experience", this->experience);
  obj.insert_or_assign("level", this->level);
}
