#include "base_room.h"
#include <boost/uuid/uuid.hpp>

using namespace std;
using namespace boost::uuids;


BaseRoom::BaseRoom(uuid id, string* name, string* description)
{
  this->id = id;
  this->name = name;
  this->description = description;
}

uuid BaseRoom::getId()
{
  return id;
}

string* BaseRoom::getName()
{
  return name;
}

void BaseRoom::setName(string* name)
{
  this->name = name;
}

void BaseRoom::setDescription(string* description)
{
  this->description = description;
}