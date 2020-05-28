#ifndef CLASS_PLAYER_ENTITY
#define CLASS_PLAYER_ENTITY

#include <string>
#include "character_entity.hpp"

using namespace std;

class PlayerEntity : public CharacterEntity {
  private:
    int experience;
    int level;
  
  public:
    PlayerEntity(int id, BaseRoom* location, int experience, int level); //: BaseEntity(id, location);
    void levelUp();
    void addExp(int exp);
};

#endif