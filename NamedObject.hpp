#ifndef NAMED_OBJECT_H
#define NAMED_OBJECT_H

#include <string>

namespace world {
  class NamedObject{
  public:
    NamedObject(std::string n);
    const std::string getName() const ;
  private:
    const std::string name;
  };

}

#endif
