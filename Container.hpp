#ifndef CONTAINER_H
#define CONTAINER_H

#include "Thing.hpp"
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/utility.hpp>

namespace world {
  class Thing;

  class Container :boost::noncopyable {
  public:
    bool haveThing(boost::shared_ptr<Thing> t) const ;
    std::set<boost::shared_ptr<Thing> > getThings() const ;
    
    void delThing(boost::shared_ptr<Thing> t);
    std::set<boost::shared_ptr<Thing> > thingNamed(const std::string name) const ;
    
    virtual ~Container() {};
  private:
    std::set<boost::shared_ptr<Thing> > things;
  protected:    
    Container() {};
    void addThing(boost::shared_ptr<Thing> t);
    
    friend class Thing;
  };

}

#endif
