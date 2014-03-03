#include "Direction.hpp"
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE( test_Direction )
{
  using namespace world;
  BOOST_CHECK(UP == opposite_direction(DOWN));
  BOOST_CHECK(DOWN == opposite_direction(UP));
  BOOST_CHECK(SOUTH == opposite_direction(NORTH));
  BOOST_CHECK(NORTH == opposite_direction(SOUTH));
  BOOST_CHECK(WEST == opposite_direction(EAST));
  BOOST_CHECK(EAST == opposite_direction(WEST));

}
