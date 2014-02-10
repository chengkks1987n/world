#ifndef ROOM_H
#define ROOM_H

#include "Container.hpp"
#include "NamedObject.hpp"

namespace world {

  class Room : public Container, public NamedObject {
  public:
    Room(const std::string& name);
  };

}

#endif
