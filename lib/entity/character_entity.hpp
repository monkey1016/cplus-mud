#ifndef CLASS_CHARACTER_ENTITY
#define CLASS_CHARACTER_ENTITY

#include <string>
#include "base_entity.hpp"

using namespace std;

class CharacterEntity : public BaseEntity {
  private:
    int currentHealth;
    int maxHealth;
  public:
    CharacterEntity(int id, BaseRoom* location);
    void doDamage(int damage);
    void doHeal(int healing);
    bool isAlive();
};

#endif