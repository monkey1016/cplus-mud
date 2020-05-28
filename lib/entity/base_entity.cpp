#include <string>
#include "base_entity.hpp"
#include "boost/format.hpp"

using namespace std;

BaseEntity::BaseEntity(int id)
{
  this->id = id;
}

BaseEntity::BaseEntity(int id, BaseRoom* location)
{
  this->id = id;
  this->location = location;
}

void BaseEntity::setDescription(string* description)
{
  this->description = description;
}

void BaseEntity::setName(string* name)
{
  this->name = name;
}

string* BaseEntity::getDescription()
{
  return this->description;
}

string* BaseEntity::getName()
{
  return this->name;
}

int BaseEntity::getId()
{
  return this->id;
}

string BaseEntity::toString() const
{
  return boost::str(boost::format("%1%[%2%]") %  id % name); //to_string(id) + "[" + name + "]";
}

ostream& operator <<(ostream& outputStream, const BaseEntity& b)
{
  outputStream << b.toString();
  return outputStream;
}