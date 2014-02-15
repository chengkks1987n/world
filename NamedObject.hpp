#ifndef NAMED_OBJECT_H
#define NAMED_OBJECT_H

#include "Root.hpp"
#include <string>

namespace world {
  class NamedObject : public Root{
  private:
    const std::string name;
    
    NamedObject(const NamedObject& c); // without implementation
    NamedObject& operator=(const NamedObject& c); // without implementation
    
  public:
    NamedObject(std::string n);//implicit type convertate from string to self
    
    const std::string getName() const ;
  };

}

#endif
