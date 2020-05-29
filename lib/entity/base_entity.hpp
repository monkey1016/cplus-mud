#ifndef CLASS_BASE_ENTITY
#define CLASS_BASE_ENTITY

#include <string>
#include "lib/geo/rooms/base_room.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/uuid/uuid.hpp>

using namespace std;
using namespace boost::uuids;

class BaseEntity {
  public:
    BaseEntity(uuid id);
    BaseEntity(uuid id, BaseRoom* location, string* name, string* description);
    BaseEntity(uuid id, BaseRoom* location);
    string* getName();
    string* getDescription();
    string toString() const;
    friend ostream& operator <<(ostream& outputStream, const BaseEntity& b);
    uuid getId();

    void setName(string* name);
    void setDescription(string* description);
    bool saveEntity();
    static BaseEntity* loadEntity(FILE* entityFile);

  private:
    friend class boost::serialization::access;

  protected:
    string* description;
    string* name;
    uuid id;
    BaseRoom* location;

    template<class Archive>
    void serialize(Archive& archive, const unsigned int version);
};

#endif