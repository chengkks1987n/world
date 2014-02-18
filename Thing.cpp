#include "Thing.hpp"
#include "NamedObject.hpp"
#include <string>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;
using namespace boost;

namespace world {

  Thing::Thing(std::string name, shared_ptr<Container> c):
    NamedObject(name),
    location(c) {

  }

  weak_ptr<Container> Thing::getLocation() const {
    return location;
  }
  
  shared_ptr<Thing> Thing::create(string name, shared_ptr<Container> c) {
    shared_ptr<Thing> ans(new Thing(name, c));
    c->addThing(ans);
    return ans;
  }
}
