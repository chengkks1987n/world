#include "Clock.hpp"
#include <iostream>

using namespace std;

int main() {

  world::Clock *c = world::Clock::getInstance();

  cout << "current time: " << c->getCurrentTime() << endl;
  c->run(5);
  cout << "current time: " << c->getCurrentTime() << endl;  

  c->run(3);
  cout << "current time: " << c->getCurrentTime() << endl;  
  return 0;
}
