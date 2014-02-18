#ifndef ROOM_H
#define ROOM_H

#include "Container.hpp"
#include "NamedObject.hpp"
#include <boost/shared_ptr.hpp>

namespace world {

  class Room : public Container, public NamedObject {
  protected:
    explicit Room(std::string name);
  public:
    static boost::shared_ptr<Room> create(std::string name) {
      return boost::shared_ptr<Room> (new Room(name));
    }
  };

}

#endif
