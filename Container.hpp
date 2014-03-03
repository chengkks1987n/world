#ifndef CONTAINER_H
#define CONTAINER_H

#include "Thing.hpp"
#include "MobileThing.hpp"
#include <set>
#include <boost/shared_ptr.hpp>

namespace world {

  class Container {
  public:
    bool haveThing(boost::shared_ptr<Thing> t) const ;
    std::set<boost::shared_ptr<Thing> > thingNamed(const std::string& name) const;
    std::set<boost::shared_ptr<Thing> > getThings() const ;
    void delThing(boost::shared_ptr<Thing> t);
    void addThing(boost::shared_ptr<Thing> t);
    virtual ~Container() {};
  protected: 
    Container() {};
  private:
    std::set<boost::shared_ptr<Thing> > things;    

  };

}

#endif
