#ifndef TIMESTEPPER_H
#define TIMESTEPPER_H

#include "MooseObject.h"

class TimeStepper : public MooseObject
{
public:
  TimeStepper(const std::string & name, const std::map<std::string, double> & params) :
      MooseObject(name, params)
  {}

  virtual double computeDT() = 0;
};

#endif
