#ifndef CLASS_PLAYER_ENTITY
#define CLASS_PLAYER_ENTITY

#include <string>
#include "character_entity.hpp"
#include <boost/uuid/uuid.hpp>

using namespace boost::uuids;

class PlayerEntity : public CharacterEntity {
  public:
    PlayerEntity(uuid id, BaseRoom* location, string* name, string* description, int experience, int level);
    PlayerEntity(uuid id, BaseRoom* location, int maxHealth, int experience, int level);
    PlayerEntity(uuid id, BaseRoom* location);
    void levelUp();
    void addExp(int exp);

  protected:
    int experience;
    int level;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& archive, const unsigned int version);
};

#endif