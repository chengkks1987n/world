#ifndef THING_H
#define THING_H

#include "NamedObject.hpp"
#include <string>
#include <boost/weak_ptr.hpp>

namespace world {
  class Container;

  class Thing : public NamedObject { //factory class
  public:
    boost::weak_ptr<Container> getLocation() const ;
    virtual ~Thing() {};
    static boost::shared_ptr<Thing> create(std::string name, 
					   boost::shared_ptr<Container> c);
  protected:
    Thing(std::string name, boost::shared_ptr<Container> c);
  private:
    boost::weak_ptr<Container> location;
  };
}

#endif
