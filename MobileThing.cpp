#include "MobileThing.hpp"

using std::string;

namespace world {

  boost::weak_ptr<Container> MobileThing::getBirthLocation() const  {
    return Thing::getLocation();
  }

  weak_ptr<Container> MobileThing::getOwner() const {
    return owner;
  }

  shared_ptr<MobileThing> MobileThing::create(string name, 
					      shared_ptr<Container> birthPlace) {
    shared_ptr<MobileThing> inst(new MobileThing(name, birthPlace));
    birthPlace->addThing(inst);
    return inst;
  }
  
  MobileThing::MobileThing(string name, shared_ptr<Container> birthPlace) : 
    Thing(name, birthPlace), owner(birthPlace)  {
    
  }

  weak_ptr<Container> MobileThing::getLocation() const {
    return Thing::getLocation();
  }

  void MobileThing::moveTo(shared_ptr<MobileThing> mt, shared_ptr<Container> to) {
    shared_ptr<Container> from = mt->getOwner().lock();
    if (to && from && to != from) {
      to->addThing(mt);
      from->delThing(mt);
      mt->owner = to;
    }
  }


}


