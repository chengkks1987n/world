#include "Thing.hpp"
#include "Room.hpp"
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <set>

using namespace std;

BOOST_AUTO_TEST_CASE( test_Room )
{
  cout << "TEST Room and Thing" << endl;
  world::Room r("lab");
  
  BOOST_CHECK(r.getName() == "lab");
  BOOST_CHECK(r.getThings().size() == 0);
  BOOST_CHECK( !r.haveThing(NULL));

  r.delThing(NULL);
  BOOST_CHECK( !r.haveThing(NULL));
  BOOST_CHECK(r.getThings().size() == 0);  

  world::Thing t("wand", &r);
  BOOST_CHECK(t.getName() == "wand");
  BOOST_CHECK(t.getLocation() == &r);
  
  BOOST_CHECK(*(r.getThings().begin()) == &t);
  BOOST_CHECK(r.getThings().size() == 1);
  BOOST_CHECK(*(r.thingNamed("wand").begin()) == &t);
  BOOST_CHECK(r.thingNamed("wand").size() == 1);
  
  world::Thing t1("book", &r);
  BOOST_CHECK(r.getThings().size() == 2);
  BOOST_CHECK(*(r.thingNamed("wand").begin()) == &t);
  BOOST_CHECK(r.thingNamed("wand").size() == 1);
  BOOST_CHECK(*(r.thingNamed("book").begin()) == &t1);
  BOOST_CHECK(r.thingNamed("book").size() == 1);

  BOOST_CHECK(r.thingNamed("empty").size() == 0);
  
  world::Thing t2("book", &r);
  BOOST_CHECK(r.getThings().size() == 3);
  BOOST_CHECK(*(r.thingNamed("wand").begin()) == &t);
  BOOST_CHECK(r.thingNamed("wand").size() == 1);
  BOOST_CHECK(r.thingNamed("book").size() == 2);

}
