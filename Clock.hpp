#ifndef CLOCK_H
#define CLOCK_H

#include "CallBack.hpp"
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/utility.hpp>

namespace world {
  class Clock: boost::noncopyable{
  public:
    static boost::shared_ptr<Clock> instance();

    int getCurrentTime() const;
    void reset();
    void run(int n);

    void addCallBack( boost::shared_ptr<CallBack> p) ;
    void removeCallBack(boost::shared_ptr<CallBack> p);
  protected:
    Clock();  
    void tick();
  private:
    int currentTime;
    std::set< boost::weak_ptr<CallBack> > events;

    static boost::shared_ptr<Clock> inst;
  };

}
#endif
