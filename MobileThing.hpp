#ifndef MOBILE_THING_H
#define MOBILE_THING_H

#include "Thing.hpp"
#include "Container.hpp"
#include <boost/weak_ptr.hpp>

namespace world {
  using boost::shared_ptr;
  using boost::weak_ptr;

  class MobileThing : public Thing {
  public:
    weak_ptr<Container> getBirthLocation() const ;
    weak_ptr<Container> getOwner() const ;

    static shared_ptr<MobileThing> create(std::string name,
					  shared_ptr<Container> birthPlace);
    static void moveTo(shared_ptr<MobileThing> mt, shared_ptr<Container> to);
  protected:
    MobileThing(std::string name, shared_ptr<Container> birthPlace);
    weak_ptr<Container> getLocation() const ;
  private:
    weak_ptr<Container> owner;
  };



}

#endif
