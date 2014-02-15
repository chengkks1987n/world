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

    Thing(const Thing& t); // without implementation
    Thing& operator=(const Thing& t); // without implementation
    
  public:
    Thing(std::string name, Container* p);
    Container* getLocation() const ;
    virtual ~Thing();
  };
}

#endif
