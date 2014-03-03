#include "Room.hpp"

using namespace boost;
using namespace std;

namespace world {
  boost::shared_ptr<Room> Room::create(std::string name) {
    return boost::shared_ptr<Room> (new Room(name));
  }
  
  Room::Room(std::string name) :
    name(name) {
  }
  
  string Room::getName() const {
    return name;
  }
  /*
  std::set<shared_ptr<Exit> > Room::getExits() const {
    return exits;
  }

  std::set<shared_ptr<Exit> > Room::exitsToward(Direction d) {
    set<shared_ptr<Exit> > result;
    for (set<shared_ptr<Exit> >::iterator it = exits.begin();
	 it != exits.end();
	 ++it) {
      shared_ptr<Exit> e = *it;
      if (e->getDirection() == d) {
	result.insert(e);
      }
    }
    return result;
  }

  shared_ptr<Exit> Room::exitTo(shared_ptr<Room> to_room) {
    if (!to_room) return shared_ptr<Exit>();
    for (set<shared_ptr<Exit> >::iterator it = exits.begin();
	 it != exits.end();
	 ++it) {
      shared_ptr<Room> r = (*it)->getTo().lock();
      if (r == to_room) {
	return *it;
      }
    }
    return shared_ptr<Exit>();
  }

  void Room::addExit(boost::shared_ptr<Exit> e) {
    if (!e) return;
    exits.insert(e);
  }
  */
}



