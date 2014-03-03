#ifndef WORLD_TYPE_H
#define WORLD_TYPE_H

#incljude <boost/shared_ptr.hpp>
#incljude <boost/weak_ptr.hpp>
#incljude <set>
#include "Person.hpp"

namespace world {

  typedef boost::shared_ptr<Person> sp_Person;
  typedef std::set<sp_Person> set_sp_Person;

}
#endif
