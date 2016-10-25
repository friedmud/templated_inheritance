#ifndef CONSTANTDT_H
#define CONSTANTDT_H

template <typename Parent>
class ConstantDT : public Parent
{
public:
  ConstantDT(const std::string & name, const std::map<std::string, double> & params) :
      Parent(name, params),
      _dt_param(params.at("dt"))
  {}

  virtual double computeDT()
  {
    return _dt_param;
  }

protected:
  const double & _dt_param;
};

#endif
