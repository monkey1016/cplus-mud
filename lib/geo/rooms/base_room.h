#ifndef CLASS_BASE_ROOM
#define CLASS_BASE_ROOM

#include <string>
#include "lib/geo/geo_object.h"

using namespace std;

class BaseRoom : public GeoObject {
  private:
    string* name;
    string* description;
  public:
    BaseRoom(string name, string description);
    string* getName();
    void setName(string* name);
    void setDescription(string* description);
};

#endif
