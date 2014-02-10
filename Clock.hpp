#ifndef CLOCK_H
#define CLOCK_H

#include "CallBack.hpp"
#include <set>

namespace world {
  class Clock: public Root{
  private:
    int currentTime;
    std::set< CallBack*> events;

  private:
    static Clock* instance;

  private:
    Clock();  
    void tick();

    Clock(const Clock& c); // without implementation

  public:
    int getCurrentTime() const;
    void reset();
    void run(int n);

    void addCallBack( CallBack* p) ;
    void removeCallBack( CallBack* p);

  public:
    static Clock* getInstance();
  };

}
#endif
