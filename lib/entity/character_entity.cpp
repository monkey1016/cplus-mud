#include "character_entity.hpp"

CharacterEntity::CharacterEntity(int id, BaseRoom* location) : BaseEntity(id, location)
{}

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