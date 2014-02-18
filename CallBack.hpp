#ifndef CALL_BACK_H
#define CALL_BACK_H

#include <boost/utility.hpp>

namespace world {
  
  class CallBack: boost::noncopyable {
  protected:
    CallBack() {};
    virtual ~CallBack() {};
  public:
    virtual void action() = 0;
  };
}
#endif
