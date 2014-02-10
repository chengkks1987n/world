#include "Clock.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test_Clock )
{
  world::Clock *c = world::Clock::getInstance();
  BOOST_CHECK(c->getCurrentTime() == 0);
  c->run(5);
  BOOST_CHECK(c->getCurrentTime() == 5);
  c->run(3);
  BOOST_CHECK(c->getCurrentTime() == 8);

  c->reset();
  BOOST_CHECK(c->getCurrentTime() == 0);
}
