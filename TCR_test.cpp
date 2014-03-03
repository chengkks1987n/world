#include "Thing.hpp"
#include "Container.hpp"
#include "Room.hpp"
#include <iostream>
#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

using namespace std;
using namespace boost;

BOOST_AUTO_TEST_CASE( test_Room_Container_Thing )
{
  shared_ptr<world::Room> r1 = world::Room::create("lab");
  shared_ptr<world::Room> r2 = world::Room::create("1503A");

  shared_ptr<world::Thing> t1 = world::Thing::create("tree", r1);
  shared_ptr<world::Thing> t2 = world::Thing::create("table", r2);
  weak_ptr<world::Thing> wp = world::Thing::create("book", r1);
  
  BOOST_CHECK(t1->getName() == "tree");
  BOOST_CHECK(t2->getName() == "table");

  BOOST_CHECK(t1->getBirthLocation().lock() == r1);
  BOOST_CHECK(t2->getBirthLocation().lock() == r2);
  BOOST_CHECK(t1->getBirthLocation().lock() == t1->getBirthLocation().lock());

  BOOST_CHECK(r1->getName() == "lab");
  BOOST_CHECK(r2->getName() == "1503A");
  
  BOOST_CHECK(r1->getThings().size() == 2);
  BOOST_CHECK(r2->getThings().size() == 1);
  BOOST_CHECK(r1->haveThing(t1));
  BOOST_CHECK(!r1->haveThing(t2));
  
  BOOST_CHECK(r1->thingNamed("book").size() == 1);
  BOOST_CHECK(*(r1->thingNamed("tree").begin()) == t1);
  BOOST_CHECK(r1->thingNamed("dont have").size() == 0);

  r1->delThing(wp.lock());
  BOOST_CHECK(wp.use_count() == 0);
  BOOST_CHECK(t1.use_count() == 2);
  BOOST_CHECK(r1->getThings().size() == 1);

  r1->delThing(t1);
  BOOST_CHECK(!r1->haveThing(t1));
  BOOST_CHECK(t1.use_count() == 1);
  BOOST_CHECK(t1->getBirthLocation().lock() == r1);
}
