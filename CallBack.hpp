#ifndef CALL_BACK_H
#define CALL_BACK_H

#include "Root.hpp"

namespace world {
  
  class CallBack {

  protected:
    CallBack() {};
  private:    
    CallBack(const CallBack& cb); // without implementation
    CallBack& operator=(const CallBack& cb); // without implementation

  public:
    virtual void action() = 0;
    virtual ~CallBack() {};
  };

}
#endif
