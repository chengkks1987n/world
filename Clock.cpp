 #include "Clock.hpp"
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;
using namespace boost;

namespace world{
  
  shared_ptr<Clock> Clock::instance;
  
  Clock::Clock() {
    currentTime = 0;
  }
  
  void Clock::tick() {
    cout << "[----- at clock " << currentTime <<" -----]" << endl;
    for(set<CallBack*>::iterator it = events.begin();
	it != events.end(); ++it) {
      (*it)->action();
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
  
  shared_ptr<Clock> Clock::getInstance() {
    if (!instance) {
      shared_ptr<Clock> p(new Clock());
      instance = p;
    }
    return instance;
  }
  
  void Clock::addCallBack( CallBack* p) {
    if (p != NULL) events.insert(p);
  }

  void Clock::removeCallBack(CallBack* p) {
    if (p != NULL) events.erase(p);
  }
}
