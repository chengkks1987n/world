#ifndef PERSON_H
#define PERSON_H

#include <boost/shared_ptr.hpp>
#include <set>
#include "world_type.hpp"

namespace world {
  class Person : public Container, public MobileThing  {
  public:
    static sp_Person create (string name, sp_Room birthLocation, int health,
			     int strength);
    int getStrength () const;
    int getHealth () const;
    void say (string text) const;
    set_sp_Person peopleAround () const;
    set_sp_Thing stuffAround () const;
    set_sp_MobileThing peekPerson (sp_Person other) const;
    void peekAround () const;
    bool take (sp_MobileThing mt);
    bool take (sp_MobileThing mt, sp_Person from);
    void drop (sp_MobileThing mt);
    void give (sp_MobileThing mt, sp_Person to);
    bool move (sp_Room to_room);
    bool move (Direction to_direction);
    bool move (sp_Exit to_exit);
    void suffer (int hits, sp_Person from);
    void die ();
  protected:
    Person (string name, sp_Room birthLocation, int health, int strength);
  private:
    int health;
    int strength;
  };

}
#endif
