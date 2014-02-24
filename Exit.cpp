#include "Exit.hpp"
#include "Room.hpp"

using namespace boost;

namespace world {

  Direction Exit::getDirection() const {
    return d;
  }
  
  boost::weak_ptr<Room> Exit::getFrom() const {
    return from;
  }

  boost::weak_ptr<Room> Exit::getTo() const {
    return to;
  }

  boost::shared_ptr<Exit> Exit::create(Direction dirct, 
				       boost::shared_ptr<Room> from,
				       boost::shared_ptr<Room> to) {
    shared_ptr<Exit> a = shared_ptr<Exit> (new Exit(dirct, from, to));
    from->addExit(a);
    return a;
  }
  
  Exit::Exit(Direction direct, shared_ptr<Room> f, shared_ptr<Room> t):
    from(f), to(t) , d(direct) {
  }
  
}
