#include "TimeStepper.h"
#include "ConstantDT.h"

#include<iostream>

int main()
{
  std::map<std::string, double> params;

  params["dt"] = 3.4;

  ConstantDT<TimeStepper> constant_dt("constant", params);

  std::cout<<"DT: "<<constant_dt.computeDT()<<std::endl;
}
