#include "Container.hpp"

using namespace std;

namespace world {

  bool Container::haveThing(Thing* t) const {
    return t != NULL && things.find(t) != things.end();
  }

  std::set<Thing*> Container::getThings() const {
    return things;
  }

  void Container::addThing(Thing* t){
    if (t != NULL) things.insert(t);
  }

  void Container::delThing(Thing* t) {
    things.erase(t);
  }

  std::set<Thing*> Container::thingNamed(const std::string name) const {
    std::set<Thing*> rlt;
    for(set<Thing*>::iterator it = things.begin();
	it != things.end();
	++it) {
      if ((*it)->getName() == name) {
	rlt.insert(*it);
      }
    }
    return rlt;
  }

}


