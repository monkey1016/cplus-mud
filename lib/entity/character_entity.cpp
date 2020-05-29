#include "character_entity.hpp"
#include "base_entity.hpp"
#include <boost/uuid/uuid.hpp>


using namespace boost::uuids;

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

template<class Archive>
void CharacterEntity::serialize(Archive& archive, const unsigned int version)
{
  archive & boost::serialization::base_object<BaseEntity>(*this);
  archive & maxHealth;
  archive & currentHealth;
}