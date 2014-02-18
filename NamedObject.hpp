#ifndef NAMED_OBJECT_H
#define NAMED_OBJECT_H

#include <string>

namespace world {
  class NamedObject{
  public:
    const std::string getName() const ;
  protected:
    NamedObject(std::string n);
  private:
    const std::string name;
  };

}

#endif
