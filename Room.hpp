#ifndef ROOM_H
#define ROOM_H

#include "Direction.hpp"
#include "Container.hpp"
#include "Exit.hpp"
#include <boost/shared_ptr.hpp>
#include <set>

namespace world {

  class Room : public Container {
  public:
    static boost::shared_ptr<Room> create(std::string name);
    std::string getName() const;
    std::set<boost::shared_ptr<Exit> > getExits() const;
    std::set<boost::shared_ptr<Exit> > exitsToward(Direction d);
    std::set<boost::shared_ptr<Exit> > exitsTo(boost::shared_ptr<Room> to_room);
    void addExit(boost::shared_ptr<Exit> e);
    void delExit(boost::shared_ptr<Exit> e);
  private:
    explicit Room(std::string name);
    std::string name;
    std::set<boost::shared_ptr<Exit> > exits;

  };

}

#endif
