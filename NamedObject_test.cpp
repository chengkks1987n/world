#include "NamedObject.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test_NamedObject )
{
  world::NamedObject n1("hello");
  
  BOOST_CHECK(n1.getName() == "hello");
}
