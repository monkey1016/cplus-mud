#ifndef CLASS_BASE_ENTITY
#define CLASS_BASE_ENTITY

#include <string>
#include "lib/geo/rooms/base_room.h"

using namespace std;

class BaseEntity {
  private:
    string* description;
    string* name;
    int id;
    BaseRoom* location;

  public:
    BaseEntity(int id);
    BaseEntity(int id, BaseRoom* location);
    string* getName();
    string* getDescription();
    string toString() const;
    friend ostream& operator <<(ostream& outputStream, const BaseEntity& b);
    int getId();

    void setName(string* name);
    void setDescription(string* description);
};

#endif