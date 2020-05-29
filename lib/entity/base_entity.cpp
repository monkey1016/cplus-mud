#include <string>
#include <iostream>
#include "base_entity.hpp"
#include <boost/format.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_serialize.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <fstream>

using namespace std;

BaseEntity::BaseEntity(uuid id)
{
  this->id = id;
}

BaseEntity::BaseEntity(uuid id, BaseRoom* location, string* name, string* description)
{
  this->id = id;
  this->name = name;
  this->description = description;
  this->location = location;
}

BaseEntity::BaseEntity(uuid id, BaseRoom* location)
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

uuid BaseEntity::getId()
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

template<class Archive>
void BaseEntity::serialize(Archive& archive, const unsigned int version)
{
  archive & *description;
  archive & *name;
  archive & id;
  if(location != nullptr)
  {
    archive & location->getId();
  }
}

bool BaseEntity::saveEntity()
{
  cout << "Saving object: " << endl;
  cout << *name << endl;
  string filename = *name + ".dat";
  std::ofstream ofs(filename.c_str());
  boost::archive::text_oarchive oa(ofs);
  try
  {
    oa << this;
  } 
  catch (const std::exception& e)
  {
    cout << "Failed to save object: " << e.what();
    return false;
  }

  return true;
}