#ifndef CLASS_CHARACTER_ENTITY
#define CLASS_CHARACTER_ENTITY

#include <string>
#include "base_entity.hpp"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/uuid/uuid.hpp>

using namespace boost::uuids;

class CharacterEntity : public BaseEntity {
  public:
    CharacterEntity(uuid id, BaseRoom* location, string* name, string* description);
    CharacterEntity(uuid id, BaseRoom* location, string* name, string* description, int maxHealth, int currentHealth);
    CharacterEntity(uuid id, BaseRoom* location, string* name, string* description, int maxHealth);
    void doDamage(int damage);
    void doHeal(int healing);
    bool isAlive();

  private:
    friend class boost::serialization::access;

  protected:
    int currentHealth;
    int maxHealth;

    template<class Archive>
    void serialize(Archive& archive, const unsigned int version);
};

#endif