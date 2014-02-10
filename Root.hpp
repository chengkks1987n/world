#ifndef ROOT_H
#define ROOT_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace world {
  
  class Root {
  private:
    const boost::uuids::uuid tag;
    Root(const Root& r); // without implementation
   
  protected:
    Root();

  public:
    virtual bool isSame(const Root& r);
    virtual ~Root(){};

  };

}

#endif
