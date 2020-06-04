#ifndef CLASS_BASE_ROOM
#define CLASS_BASE_ROOM

#include <string>
#include "lib/geo/geo_object.h"
#include <boost/uuid/uuid.hpp>

using namespace std;
using namespace boost::uuids;

class BaseRoom : public GeoObject {
  private:
    string* name;
    string* description;
    uuid id;

  public:
    BaseRoom(uuid id, string* name, string* description);
    string* getName();
    uuid getId();
    void setName(string* name);
    void setDescription(string* description);
  
  // protected:
  //   template<class Archive>
  //   void serialize(Archive& archive, const unsigned int version);
};

#endif
