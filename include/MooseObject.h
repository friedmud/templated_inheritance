#ifndef MOOSEOBJECT_H
#define MOOSEOBJECT_H

#include<string>
#include<map>

class MooseObject
{
public:
  MooseObject(const std::string & name, const std::map<std::string, double> & params) :
      _name(name),
      _params(params)
  {}

  std::string name() { return _name; }

protected:
  const std::string & _name;

  const std::map<std::string, double> & _params;
};

#endif
