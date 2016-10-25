#ifndef BOUNDSDT_H
#define BOUNDSDT_H

#include<iostream>

template <typename Parent>
class BoundsDT : public Parent
{
public:
  BoundsDT(const std::string & name, const std::map<std::string, double> & params) :
      Parent(name, params),
      _min_dt(params.at("min_dt")),
      _max_dt(params.at("max_dt"))
  {}

  virtual double computeDT()
  {
    auto dt = Parent::computeDT();

    dt = std::max(dt, _min_dt);
    dt = std::min(dt, _max_dt);

    return dt;
  }

protected:
  const double & _min_dt;
  const double & _max_dt;
};

#endif
