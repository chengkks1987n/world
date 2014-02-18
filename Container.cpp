#include "Container.hpp"

using namespace std;
using namespace boost;

namespace world {

  bool Container::haveThing(shared_ptr<Thing> t) const {
    return t && things.find(t) != things.end();
  }

  set<shared_ptr<Thing> > 
  Container::getThings() const {
    return things;
  }

  void Container::addThing(shared_ptr<Thing> t){
    if (t) things.insert(t);
  }

  void Container::delThing(shared_ptr<Thing> t) {
    things.erase(t);
  }

  set<shared_ptr<Thing> >
  Container::thingNamed(const std::string name) const {
    set<shared_ptr<Thing> > rlt;
    for(set<shared_ptr<Thing> >::iterator it = things.begin();
	it != things.end();
	++it) {
      if ((*it)->getName() == name) {
	rlt.insert(*it);
      }
    }
    return rlt;
  }

}


