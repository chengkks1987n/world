#include "Exit.hpp"
#include "Room.hpp"
#include "Direction.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <set>

using namespace std;
using namespace boost;

BOOST_AUTO_TEST_CASE( test_Exit_Room )
{
  using namespace world;
  shared_ptr<world::Room> lobby_10 = world::Room::create("lobby_10");
  shared_ptr<world::Room> grendel_den = world::Room::create("grendel_den");
  shared_ptr<world::Room> building_13 = world::Room::create("building_13");
  shared_ptr<world::Room> lobby_7 = world::Room::create("lobby_7");

  shared_ptr<Exit> e1 = world::Exit::create(world::WEST, grendel_den, lobby_7);
  shared_ptr<Exit> e2 = world::Exit::create(world::EAST, lobby_7, grendel_den);
  bothWayExit(UP, grendel_den, lobby_10);
  bothWayExit(SOUTH, lobby_10, building_13);  

  BOOST_CHECK(e1->getDirection() == WEST);
  BOOST_CHECK(e1->getFrom().lock() == grendel_den);
  BOOST_CHECK(e1->getTo().lock() == lobby_7);
  BOOST_CHECK(e2->getDirection() == EAST);
  BOOST_CHECK(e2->getFrom().lock() == lobby_7);
  BOOST_CHECK(e2->getTo().lock() == grendel_den);

  BOOST_CHECK(lobby_7->getExits().size() == 1);
  BOOST_CHECK(grendel_den->getExits().size() == 2);
  BOOST_CHECK(lobby_10->getExits().size() == 2);
  BOOST_CHECK(building_13->getExits().size() == 1);

  set<shared_ptr<Exit> > es = lobby_10->exitsToward(UP);
  BOOST_CHECK(es.size() == 0);
  es = lobby_7->exitsToward(EAST);
  BOOST_CHECK(es.size() == 1);
  BOOST_CHECK(*es.begin() == e2);

  es = lobby_7->exitsTo(grendel_den);
  BOOST_CHECK(es.size() == 1);
  BOOST_CHECK(*es.begin() == e2);

}
