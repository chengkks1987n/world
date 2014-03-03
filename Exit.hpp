#ifndef EXIT_H
#define EXIT_H

#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "Direction.hpp"

namespace world {

  class Room;

  class Exit { 
  public:
    static boost::shared_ptr<Exit> create(Direction dirct, 
					  boost::shared_ptr<Room> from,
					  boost::shared_ptr<Room> to);
    Direction getDirection() const;
    boost::weak_ptr<Room> getFrom() const;
    boost::weak_ptr<Room> getTo() const;
  private:
    Exit(Direction direct, boost::shared_ptr<Room> f, boost::shared_ptr<Room> t);
    boost::weak_ptr<Room> from;
    boost::weak_ptr<Room> to;
    Direction direction;
  };

  void bothWayExit(Direction d, boost::shared_ptr<Room> from,
		   boost::shared_ptr<Room> to);

}

#endif
