#include "MobileThing.hpp"
#include "Room.hpp"

#include <boost/test/unit_test.hpp>


using namespace std;
using namespace boost;

BOOST_AUTO_TEST_CASE( test_MobileThing )
{
  cout << "TEST MobileThing" << endl;

  shared_ptr<world::Room> r1 = world::Room::create("lab");
  shared_ptr<world::Room> r2 = world::Room::create("1503");

  //world::MobileThing mt("cant compile", r1);
  shared_ptr<world::MobileThing> mt = world::MobileThing::create("pen", r1);

  //mt->getLocation(); //cannt compile
  BOOST_CHECK(mt->getBirthLocation().lock() == mt->getOwner().lock());
  BOOST_CHECK(mt->getBirthLocation().lock() == r1);
  BOOST_CHECK(r1->haveThing(mt));
  BOOST_CHECK(!r2->haveThing(mt));
  
  world::MobileThing::moveTo(mt, r2);
  BOOST_CHECK(mt->getBirthLocation().lock() != mt->getOwner().lock());
  BOOST_CHECK(mt->getBirthLocation().lock() == r1);
  BOOST_CHECK(mt->getOwner().lock() == r2);
  BOOST_CHECK(!r1->haveThing(mt));
  BOOST_CHECK(r2->haveThing(mt));
  
  world::MobileThing::moveTo(mt, r2);
  BOOST_CHECK(mt->getBirthLocation().lock() != mt->getOwner().lock());
  BOOST_CHECK(mt->getBirthLocation().lock() == r1);
  BOOST_CHECK(mt->getOwner().lock() == r2);
  BOOST_CHECK(!r1->haveThing(mt));
  BOOST_CHECK(r2->haveThing(mt));
  
}
