#ifndef CLASS_BASE_AREA
#define CLASS_BASE_AREA

#include <vector>
#include "lib/geo/rooms/base_room.h"
#include "lib/geo/geo_object.h"

using namespace std;

class BaseArea : public GeoObject {
  private:
    vector<BaseRoom*> rooms;
  public:
    BaseArea(vector<BaseRoom*>* rooms);
    BaseArea();
    vector<BaseRoom*>* getRooms();
    void addRoom(BaseRoom* room);
    void addRooms(vector<BaseRoom*>* rooms);
};

#endif
