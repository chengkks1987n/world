#ifndef NAMED_OBJECT_H
#define NAMED_OBJECT_H

#include "Root.hpp"
#include <string>

namespace world {
  class NamedObject : public Root{
  private:
    const std::string name;
    
  public:
    NamedObject(std::string n);

    const std::string getName() const ;
  };

}

#endif
