#include "character_entity.hpp"
#include "base_entity.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/property_tree/ptree.hpp>



using namespace boost::uuids;
using namespace mud::entities;
using boost::property_tree::ptree;

CharacterEntity::CharacterEntity(uuid id, BaseRoom* location, string* name, string* description) : BaseEntity(id, location, name, description)
{
  this->maxHealth = 0;
  this->currentHealth = 0;
}

CharacterEntity::CharacterEntity(uuid id, BaseRoom* location, string* name, string* description, int maxHealth) : BaseEntity(id, location, name, description)
{
  this->maxHealth = maxHealth;
  this->currentHealth = maxHealth;
}

CharacterEntity::CharacterEntity(uuid id, BaseRoom* location, string* name, string* description, int maxHealth, int currentHealth) : BaseEntity(id, location, name, description)
{
  this->maxHealth = maxHealth;
  this->currentHealth = currentHealth;
}

void CharacterEntity::doDamage(int damage) {
  currentHealth -= damage;
  if(currentHealth < 0)
  {
    currentHealth = 0;
  }
}

void CharacterEntity::doHeal(int healing)
{
  currentHealth += healing;
  if(currentHealth > maxHealth)
  {
    currentHealth = maxHealth;
  }
}

bool CharacterEntity::isAlive()
{
  return currentHealth > 0;
}

// template<class Archive>
// void CharacterEntity::serialize(Archive& archive, const unsigned int version)
// {
//   archive & boost::serialization::base_object<BaseEntity>(*this);
//   archive & maxHealth;
//   archive & currentHealth;
// }

void CharacterEntity::toJson(json::object& obj)
{
  this->BaseEntity::toJson(obj);
  obj.insert_or_assign("class", "mud::entities::CharacterEntity");
  obj.insert_or_assign("maxHealth", this->maxHealth);
  obj.insert_or_assign("currentHealth", this->currentHealth);
}
