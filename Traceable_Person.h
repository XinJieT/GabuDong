
#ifndef _TRACEABLE_PERSON_H_
#define _TRACEABLE_PERSON_H_

// Traceable_Person.h

// ee1520 hw2

// The ee1520 lecture on Monday, April 14 of 2025 ended at 2 pm in the EE Building at NCKU.
// The instructor took the Bus 77 from the Zi-Chiang campus Chang-Rong Station, leaving
// at 2:30 pm, and the bus driver was a Psychology student named Tiffany. On the same bus,
// there was another ee1520 student, John. John asked the instructor some questions about
// homework assignment #2 (using his own computer), before he got off the bus at the NCKU
// Hospital stop at 2:45 pm on the same date. After John being off the bus, the instructor
// started playing an online game on an Android device. The instructor said “thank you” to
// the bus driver, Tiffany, before he himself got off at the Moore and Pollock stop at 3:15 pm.
// The bus has 24/7 video recording. The instructor lost his phone an Android device at some
// point. And, later, he realized this and tried to retrieve the device.

// Step 1: identify the objects

// Timestamps (4 of them)
// {“time” : “2025-04-14T14:00:00+0000”}
// {“time” : “2025-04-14T14:30:00+0000”}
// {“time” : “2025-04-14T14:45:00+0000”}
// {“time” : “2025-04-14T15:15:00+0000”}

// Person (3 of them)
// [finding suitable classs to inherit or to contain -->
//  class Person, class Personal_Timed_GPS_Record, class Time_Location]
// {“name” : “Felix Wu”}
// {“name” : “Felix Wu”, “occupation” : “instructor”,
//  “GPS trace”: [
//     {"time" : “2025-04-14T14:00:00+0000”,
//      "location":
//       {
//        "latitude" : 1.0,
//        "longitude" : -1.0,
//        "label" : "NCKU EE 4th floor"
//       }
//     },
//     {"time" : “2025-04-14T14:30:00+0000”,
//      "location":
//       {
//        "latitude" : 1.0,
//        "longitude" : -1.0,
//        "label" : "Chang-Rong Bus Stop"
//       }
//     },
//     {"time" : “2025-04-14T14:45:00+0000”,
//      "location":
//       {
//        "latitude" : 1.0,
//        "longitude" : -1.0,
//        "label" : "NCKU Hospital"
//       }
//     },
//     {"time" : “2025-04-14T15:15:00+0000”,
//      "location":
//       {
//        "latitude" : 1.0,
//        "longitude" : -1.0,
//        "label" : "Moore and Pollock bus stop"
//       }
//     },
//  ]}

// The issue of CASTing!!

// Step 2: the action (How objects should interact with each other?)

// Design consideration -- GPS location of a person or a device associated with a person?

// option #1: GPS <--> Person
// option #2: GPS <--> Phone <--> Person

// Also, can a person (or a bus) have multiple devices? (i.e., multiple locations)
// How about a location of a group of people [e.g., a family] or a group of cars?
// I put my phone (or one of my phones) on a drone (to take pictures) or a robot
//       with remote control?
// Is this useful?

// But, we should start it with something SIMPLE (first -- for hw2-3 at least)
// "One device per person"


#include "Person.h"
#include "Personal_Timed_GPS_Record.h"
#include "Locatable_Thing.h"

using namespace std;

class Traceable_Person : public Person
{
private:
protected:
public:

  // something else
  std::string occupation;
  Personal_Timed_GPS_Record GPS_trace;
  Locatable_Thing *phone;
  
  // constructor
  Traceable_Person(std::string, std::string);
  Traceable_Person(std::string, std::string, GPS_DD *);
  Traceable_Person();
  ~Traceable_Person();

  // something else
  
  // virtual Json::Value * dump2JSON(void);
  // virtual void JSON2Object(Json::Value *);
};

#endif  /* _TRACEABLE_PERSON_H_ */
