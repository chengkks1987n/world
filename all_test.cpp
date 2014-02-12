#define BOOST_TEST_MODULE all test
#include <boost/test/unit_test.hpp>
#include "Root.hpp"
#include "Container.hpp"
#include "CallBack.hpp"
#include "Clock.hpp"
#include <iostream>

using namespace std;

BOOST_AUTO_TEST_CASE( all_test )
{
  cout << "TEST all" << endl;

  // compile error for the follows:
  //world::Root r;
  //world::Container c;
  //world::CallBack cb;
  //world::Clock cl;
  

}


// EOF
