#ifndef CLOCK_H
#define CLOCK_H

#include "CallBack.hpp"
#include <set>
#include <boost/shared_ptr.hpp>

namespace world {
  class Clock: public Root{
  private:
    int currentTime;
    std::set< CallBack*> events;

  private:
    static boost::shared_ptr<Clock> instance;

  private:
    Clock();  
    void tick();

    Clock& operator= (const Clock& c); // without implementation
    Clock(const Clock& c); // without implementation

  public:
    int getCurrentTime() const;
    void reset();
    void run(int n);

    void addCallBack( CallBack* p) ;
    void removeCallBack( CallBack* p);

  public:
    static boost::shared_ptr<Clock> getInstance();
  };

}
#endif
