#include "NamedObject.hpp"

namespace world {
  NamedObject::NamedObject(std::string n) :
    name(n) {
  }

  const std::string NamedObject::getName() const {
    return this->name;
  }      

}
