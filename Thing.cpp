#include "Thing.hpp"
#include "NamedObject.hpp"

namespace world {

  Thing::Thing(std::string name, Container* p):
    NamedObject(name), 
    location(p) { 
    location->addThing(this);
  }
    
  //  Thing::Thing(const Thing& t):
  //NamedObject(t.getName()), 
  //location(t.getLocation()) {
  //}

  Container* Thing::getLocation() const {
    return location;
  }
  
  Thing::~Thing() {
    location->delThing(this);
  }

}
