#ifndef THING_H
#define THING_H

#include <string>
#include <boost/weak_ptr.hpp>

namespace world {
  class Container;

  class Thing {
  public:
    static boost::shared_ptr<Thing> create(std::string name, 
					   boost::shared_ptr<Container> location);
    virtual ~Thing() {};
    boost::weak_ptr<Container> getBirthLocation() const ;
    std::string getName() const;
  protected:
    Thing(std::string name, boost::shared_ptr<Container> location);
  private:
    boost::weak_ptr<Container> birthLocation;
    std::string name;
  };
}

#endif
