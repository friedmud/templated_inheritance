#ifndef MINOFDT_H
#define MINOFDT_H

template <typename Parent1, typename Parent2>
class MinOfDT : public Parent1, public Parent2
{
public:
  MinOfDT(const std::string & name, const std::map<std::string, double> & params) :
      Parent1(name, params),
      Parent2(name, params)
  {}

  virtual double computeDT()
  {
    auto dt1 = Parent1::computeDT();
    auto dt2 = Parent2::computeDT();

    return std::min(dt1, dt2);
  }
};

#endif
