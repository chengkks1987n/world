#ifndef DIRECTION_H
#define DIRECTION_H

namespace world {

  enum Direction {UP=1, DOWN, SOUTH, NORTH, WEST, EAST };
  
  Direction opposite_direction(Direction d) ;

}

#endif
