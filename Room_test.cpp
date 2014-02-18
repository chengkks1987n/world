#include "Thing.hpp"
#include "Room.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <set>


using namespace std;
using namespace boost;

BOOST_AUTO_TEST_CASE( test_Room )
{
  cout << "TEST Room and Thing" << endl;
  shared_ptr<world::Room> r = world::Room::create("lab");
  
  BOOST_CHECK(r->getName() == "lab");
  BOOST_CHECK(r->getThings().size() == 0);

  shared_ptr<world::Thing> t = world::Thing::create("wand", r);
  BOOST_CHECK(t->getName() == "wand");
  BOOST_CHECK(t->getLocation().lock() == r);

  BOOST_CHECK(r->getThings().size() == 1);  
  BOOST_CHECK(r->thingNamed("wand").size() == 1);
  BOOST_CHECK(*(r->getThings().begin()) == t);
  BOOST_CHECK(*(r->thingNamed("wand").begin()) == t);
  
  shared_ptr<world::Thing> t1 = world::Thing::create("book", r);
  BOOST_CHECK(r->getThings().size() == 2);
  BOOST_CHECK(*(r->thingNamed("wand").begin()) == t);
  BOOST_CHECK(r->thingNamed("wand").size() == 1);
  BOOST_CHECK(*(r->thingNamed("book").begin()) == t1);
  BOOST_CHECK(r->thingNamed("book").size() == 1);

  BOOST_CHECK(r->thingNamed("empty").size() == 0);
  
  shared_ptr<world::Thing> t2 = world::Thing::create("book", r);
  BOOST_CHECK(r->getThings().size() == 3);
  BOOST_CHECK(*(r->thingNamed("wand").begin()) == t);
  BOOST_CHECK(r->thingNamed("wand").size() == 1);
  BOOST_CHECK(r->thingNamed("book").size() == 2);

}
