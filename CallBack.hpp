#ifndef CALL_BACK_H
#define CALL_BACK_H

namespace world {
  
  class CallBack {
  protected:
    CallBack() {};
    virtual ~CallBack() {};
  public:
    virtual void action() = 0;
  };
}
#endif
