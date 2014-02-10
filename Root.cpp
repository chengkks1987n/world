#include "Root.hpp"

namespace world {

  Root::Root(): 
    tag(boost::uuids::random_generator()()){
  }

  bool Root::isSame(const Root& r) {
    return r.tag == tag;
  }

}
