#ifndef CLASS_GEO_OBJECT
#define CLASS_GEO_OBJECT

#include <string>
using namespace std;
class GeoObject {
  public:
    virtual string getFqdn();
    virtual string saveMe();
};

#endif
