#include "Room.hpp"
#include "Exit.hpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace boost;
using namespace world;

/**
   @brief create two Exits, one is at dirction d, the other one is opposite.

   @param d must be one of UP, SOUTH, WEST.
   @param from 
   @param to 
   */
void bothWayExit(Direction d, shared_ptr<Room> from, shared_ptr<Room> to) {
  world::Exit::create(d, from, to);
  world::Exit::create((Direction)(d+1), to, from);
}

BOOST_AUTO_TEST_CASE( test_Exit )
{
  cout << "TEST Exit" << endl;

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
  shared_ptr<Exit> e = lobby_7->exitTo(grendel_den);
  BOOST_CHECK(e == e2);

}
