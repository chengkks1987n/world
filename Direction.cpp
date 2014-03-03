#include "Direction.hpp"

namespace world {
  Direction opposite_direction(Direction d) {
    if (d % 2 == 1) 
      return Direction(d+1);
    else
      return Direction(d-1);
  }
}
