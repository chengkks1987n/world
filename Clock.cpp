#include "Clock.hpp"
#include <iostream>

using namespace std;

namespace world{
  
  Clock* Clock::instance = NULL;
  
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
  
  Clock* Clock::getInstance() {
    if (instance == NULL)  instance = new Clock();
    return instance;
  }
  
  void Clock::addCallBack( CallBack* p) {
    if (p != NULL) events.insert(p);
  }

  void Clock::removeCallBack(CallBack* p) {
    if (p != NULL) events.erase(p);
  }
}
