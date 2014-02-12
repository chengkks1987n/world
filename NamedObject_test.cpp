#include "NamedObject.hpp"
#include <boost/test/unit_test.hpp>
#include <iostream>

using namespace std;

BOOST_AUTO_TEST_CASE( test_NamedObject )
{
  cout << "TEST NamedObject" << endl;

  world::NamedObject n1("hello");
  
  BOOST_CHECK(n1.getName() == "hello");
}
