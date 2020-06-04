#include <string>
#include <iostream>
#include "base_entity.hpp"
#include <boost/format.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/filesystem.hpp>
#include <boost/json.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/core.hpp>
#include <fstream>

using namespace std;
using namespace mud::entities;
namespace json = boost::json;

extern string APPLICATION_DIRECTORY;

EntityManagerRegister<BaseEntity> BaseEntity::registration("mud::entities::BaseEntity");

BaseEntity::BaseEntity()
{
  boost::uuids::random_generator generator;
  boost::uuids::uuid player_uuid = generator();
  this->id = player_uuid;
}

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

// template<class Archive>
// void BaseEntity::serialize(Archive& archive, const unsigned int version)
// {
//   archive & *description;
//   archive & *name;
//   archive & id;
//   if(location != nullptr)
//   {
//     archive & location->getId();
//   }
// }

bool BaseEntity::saveEntity()
{
  // cout << "Saving object: " << endl;
  // cout << *name << endl;
  string filePath = APPLICATION_DIRECTORY + "/data/";
  string filename = *name + ".json";
  boost::filesystem::path dir(filePath.c_str());
  BOOST_LOG_SEV(logger, info) << "Testing";
  cout << "Filename: " << filename << endl;
  if(boost::filesystem::create_directory(dir))
  {
    cerr << "Directory Created: " << filePath << endl;
  }
  std::ofstream ofs((filePath + filename).c_str());
  try
  {
    // boost::archive::text_oarchive oa(ofs);
    ofs << this->toJsonString().c_str();
  } 
  catch (const std::exception& e)
  {
    cout << "Failed to save object: " << e.what() << endl;
    return false;
  }

  return true;
}

void BaseEntity::toJson(json::object& obj)
{
  obj.insert_or_assign("class", "mud::entities::BaseEntity");
  obj.insert_or_assign("id", boost::uuids::to_string(id).c_str());
  obj.insert_or_assign("name", (*name).c_str());
  obj.insert_or_assign("description", (*description).c_str());
  if(location != nullptr)
  {
    obj.insert_or_assign("location", boost::uuids::to_string(location->getId()).c_str());
  }
  else
  {
    obj.insert_or_assign("location", nullptr);
  }
}

json::string BaseEntity::toJsonString()
{
  json::object obj;
  this->toJson(obj);
  return json::to_string(obj);
}