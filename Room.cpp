#include "Room.hpp"
#include "Exit.hpp"

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

  std::set<boost::shared_ptr<Exit> > Room::exitsTo(shared_ptr<Room> to_room) {
    set<shared_ptr<Exit> > result;
    if (!to_room) return result;
    for (set<shared_ptr<Exit> >::iterator it = exits.begin();
	 it != exits.end();
	 ++it) {
      shared_ptr<Exit> e = *it;
      shared_ptr<Room> r = e->getTo().lock();
      if (r == to_room) {
	result.insert(e);
      }
    }
    return result;
  }

  void Room::addExit(boost::shared_ptr<Exit> e) {
    if (e) exits.insert(e);
  }
  
  void Room::delExit(boost::shared_ptr<Exit> e) {
    if (e) exits.erase(e);
  }
    
}



