#ifndef ROOM_H
#define ROOM_H

//#include "Direction.hpp"
#include "Container.hpp"
//#include "Exit.hpp"
#include <boost/shared_ptr.hpp>
//#include <set>

namespace world {

  class Room : public Container {
  public:
    static boost::shared_ptr<Room> create(std::string name);
    std::string getName() const;
    //std::set<boost::shared_ptr<Exit> > getExits() const;
    //    std::set<boost::shared_ptr<Exit> > exitsToward(Direction d);
    //    boost::shared_ptr<Exit> exitTo(boost::shared_ptr<Room> to_room);
  private:
    std::string name;
    explicit Room(std::string name);
    //    void addExit(boost::shared_ptr<Exit> e);
    //std::set<boost::shared_ptr<Exit> > exits;
    //    friend boost::shared_ptr<Exit> Exit::create(Direction dirct, 
    //						boost::shared_ptr<Room> from,
    //						boost::shared_ptr<Room> to);

  };

}

#endif
