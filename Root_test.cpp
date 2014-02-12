#include "NamedObject.hpp"
#include <boost/test/unit_test.hpp>
#include <iostream>

using namespace std;

BOOST_AUTO_TEST_CASE( test_Root )
{
  cout << "TEST Root with NamedObject" << endl;

  world::NamedObject n1("n1");
  world::NamedObject n2("n1");
  
  BOOST_CHECK(!n1.isSame(n2));
  BOOST_CHECK(!n2.isSame(n1));
  BOOST_CHECK(n2.isSame(n2));
}
