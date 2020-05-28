// #include <boost/test/included/unit_test.hpp>

// #include "test_base_areas.h"
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>
#include "main/rooms/base_room.h"
#define BOOST_TEST_MODULE C++ Unit Tests for Rooms

BOOST_AUTO_TEST_CASE( createRoom ) {
  BaseRoom* testRoom = new BaseRoom("sample");

  BOOST_TEST( boost::iequals("sample", &testRoom.getName()) );

}
