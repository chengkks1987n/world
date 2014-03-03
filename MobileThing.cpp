#include "MobileThing.hpp"
#include "Container.hpp"
using namespace boost;
using namespace std;

namespace world {

  shared_ptr<MobileThing> MobileThing::create(string name, 
					      shared_ptr<Container> birthLocation){
    shared_ptr<MobileThing> inst(new MobileThing(name, birthLocation));
    birthLocation->addThing(inst);
    return inst;
  }
  
  MobileThing::MobileThing(string name, shared_ptr<Container> birthLocation) : 
    Thing(name, birthLocation), owner(birthLocation)  {
    
  }

  boost::weak_ptr<Container> MobileThing::getOwner() const  {
    return owner;
  }

  bool MobileThing::moveTo(shared_ptr<MobileThing> mt, shared_ptr<Container> to) {
    shared_ptr<Container> from = mt->getOwner().lock();
    if (to && from && to != from) {
      to->addThing(mt);
      from->delThing(mt);
      mt->owner = to;
      return true;
    }
    return false;
  }

}


