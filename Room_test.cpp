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
  BOOST_CHECK(r.getThings().size() == 1);
  
  BOOST_CHECK(r.thingNamed("wand").size() == 1);

  

}
