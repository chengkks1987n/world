#ifndef MOBILE_THING_H
#define MOBILE_THING_H

#include "Thing.hpp"
#include <boost/weak_ptr.hpp>

namespace world {
//class Container;

  class MobileThing : public Thing {
  public:
    static boost::shared_ptr<MobileThing> create(std::string name, boost::shared_ptr<Container> birthLocation);
    static bool moveTo(boost::shared_ptr<MobileThing> mt, 
		       boost::shared_ptr<Container> to);
    boost::weak_ptr<Container> getOwner() const ;
  protected:
    MobileThing(std::string name, boost::shared_ptr<Container> birthLocation);
  private:
    boost::weak_ptr<Container> owner;
  };

}

#endif
