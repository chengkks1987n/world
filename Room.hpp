#ifndef ROOM_H
#define ROOM_H

#include "Container.hpp"
#include "NamedObject.hpp"

namespace world {

  class Room : public Container, public NamedObject {
  private:
    Room(const Room& ); // without implementation
    Room& operator=(const Room& ); // without implementation

  public:
    explicit Room(const std::string& name);
  };

}

#endif
