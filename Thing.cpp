#include "Thing.hpp"
#include "Container.hpp"
#include <string>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;
using namespace boost;

namespace world {

  Thing::Thing(std::string name0, shared_ptr<Container> location):
    name(name0),
    birthLocation(location) {

  }

  weak_ptr<Container> Thing::getBirthLocation() const {
    return birthLocation;
  }

  string Thing::getName() const {
    return name;
  }
  
  shared_ptr<Thing> Thing::create(string name, shared_ptr<Container> location) {
    shared_ptr<Thing> ans(new Thing(name, location));
    location->addThing(ans);
    return ans;
  }
}
