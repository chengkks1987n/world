#ifndef THING_H
#define THING_H

#include "Container.hpp"
#include "NamedObject.hpp"
#include <string>

namespace world {
  class Container;

  class Thing : public NamedObject {
  private:
    Container* location;
    
  public:
    Thing(std::string name, Container* p);
    Thing(const Thing& t);
    Container* getLocation() const ;
    ~Thing();
  };
}

#endif
