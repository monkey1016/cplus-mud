#include "sqlite_connector.h"
#include "sqlite3.h"
#include "boost/algorithm/string.hpp"
using namespace boost;

SqliteConnection::SqliteConnection(string location) {
  int rc = sqlite3_open(location.c_str(), &dbConn);
  if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
}

SqliteConnection::~SqliteConnection() {
  sqlite3_close(dbConn);
}

bool SqliteConnection::save(GeoObject* obj) {
  sqlite3_exec(ojb->saveMe())
}