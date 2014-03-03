#ifndef CONTAINER_H
#define CONTAINER_H

#include "Thing.hpp"
#include <set>
#include <boost/shared_ptr.hpp>

namespace world {

  class Container {
  public:
    bool haveThing(boost::shared_ptr<Thing> t) const ;
    std::set<boost::shared_ptr<Thing> > thingNamed(const std::string& name) const;
    std::set<boost::shared_ptr<Thing> > getThings() const ;
    void delThing(boost::shared_ptr<Thing> t);
    virtual ~Container() {};
  protected: 
    Container() {};
  private:
    void addThing(boost::shared_ptr<Thing> t);
    std::set<boost::shared_ptr<Thing> > things;    
    friend boost::shared_ptr<Thing> Thing::create(std::string name, boost::shared_ptr<Container> location);
  };

}

#endif
