#include "Clock.hpp"
#include <set>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;
using namespace boost;

namespace world{
  
  shared_ptr<Clock> Clock::inst;

  Clock::Clock(): currentTime(0) {
    
  }

  void Clock::tick() {
    cout << "[----- at clock " << currentTime <<" -----]" << endl;
    for(set<weak_ptr<CallBack> >::iterator it = events.begin();
	it != events.end(); 
	++it) {
      shared_ptr<CallBack> cb = (*it).lock();
      if (cb) 	cb->action();
    }
    ++currentTime;
  }
  
  int Clock::getCurrentTime() const {
    return this->currentTime;
  }

  void Clock::reset() {
    currentTime = 0;
    events.clear();

    cout << "[----- the clock reset -----]" << endl;
  }
  
  void Clock::run(int n) {
    while (n--) this->tick();
  }
  
  shared_ptr<Clock> Clock::instance() {
    if (!inst) {
      inst = shared_ptr<Clock>(new Clock());
    }
    return inst;
  }
  
  void Clock::addCallBack(shared_ptr<CallBack> p) {
    if (p) events.insert(p);
  }

  void Clock::removeCallBack(shared_ptr<CallBack> p) {
    if (p) events.erase(p);
  }
}
