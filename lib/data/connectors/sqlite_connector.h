#include "connection.h"
#include <string>
#include "lib/geo/geo_object.h"

using namespace std;

class SqliteConnection : public Connection {
  private:
    sqlite3* dbConn;
  public:
    SqliteConnection(string location);
    ~SqliteConnection();
    bool save(GeoObject* ojb);
};