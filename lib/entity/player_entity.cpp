#include "player_entity.hpp"
#include "character_entity.hpp"
#include <boost/uuid/uuid.hpp>


using namespace boost::uuids;

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

template<class Archive>
void PlayerEntity::serialize(Archive& archive, const unsigned int version)
{
  archive & boost::serialization::base_object<CharacterEntity>(*this);
  archive & experience;
  archive & level;
}