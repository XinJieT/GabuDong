
#ifndef _LOCATABLE_THING_H_
#define _LOCATABLE_THING_H_

// Locatable_Thing.h

#include "Thing.h"
#include "GPS.h"

using namespace std;

class Locatable_Thing : public Thing
{
 private:
 protected:
 public:

  GPS_DD location;
  Locatable_Thing(GPS_DD);

  virtual Json::Value * dump2JSON(void);
  virtual void JSON2Object(Json::Value *);
};

#endif /* _THING_H_ */
