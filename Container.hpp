#ifndef CONTAINER_H
#define CONTAINER_H

#include "Root.hpp"
#include "Thing.hpp"
#include <set>

namespace world {
  class Thing;

  class Container {
  private:
    std::set<Thing*> things;
    Container(const Container& c); // without implementation

  protected:    
    Container() {};
    
  public:
    bool haveThing(Thing* t) const ;
    std::set<Thing*> getThings() const ;
    void addThing(Thing* t);
    void delThing(Thing* t);
    std::set<Thing*> thingNamed(const std::string name) const ;
    
    virtual ~Container() {};
  };

}

#endif
