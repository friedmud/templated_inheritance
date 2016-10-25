#ifndef FUNCTIONDT_H
#define FUNCTIONDT_H

template <typename Parent>
class FunctionDT : public Parent
{
public:
  FunctionDT(const std::string & name, const std::map<std::string, double> & params) :
      Parent(name, params)
  {}

  virtual double computeDT()
  {
    // Of course, this would evaluate a Function
    // Just using something arbitrary to show how it would work
    return this->_t * 2.4;
  }
};

#endif
