#include "TimeStepper.h"
#include "ConstantDT.h"
#include "BoundsDT.h"
#include "FunctionDT.h"
#include "MinOfDT.h"

#include<iostream>

int main()
{
  {
    std::map<std::string, double> params;
    params["_t"] = 1.0;
    params["dt"] = 3.4;

    ConstantDT<TimeStepper> constant_dt("constant", params);

    std::cout<<"ConstantDT: "<<constant_dt.computeDT()<<std::endl;
    std::cout<<"ConstantDT: "<<constant_dt.name()<<std::endl;
  }


  {
    std::map<std::string, double> params;
    params["_t"] = 1.0;
    params["dt"] = 3.4;

    params["min_dt"] = 4.2;
    params["max_dt"] = 7.8;

    BoundsDT<ConstantDT<TimeStepper> > bounds_dt("bounds", params);

    std::cout<<"BoundsDT: "<<bounds_dt.computeDT()<<std::endl;
  }


  {
    std::map<std::string, double> params;
    params["_t"] = 2.0;
    params["dt"] = 3.4;

    FunctionDT<TimeStepper> function_dt("function", params);

    std::cout<<"FunctionDT: "<<function_dt.computeDT()<<std::endl;
  }


  {
    std::map<std::string, double> params;
    params["_t"] = 5.0;
    params["dt"] = 3.4;

    params["min_dt"] = 4.2;
    params["max_dt"] = 7.8;

    BoundsDT<FunctionDT<TimeStepper> > ts("function", params);

    std::cout<<"BoundsDT<FunctionDT>: "<<ts.computeDT()<<std::endl;
  }

  {
    std::map<std::string, double> params;
    params["_t"] = 5.0;
    params["dt"] = 3.4;

    params["min_dt"] = 4.2;
    params["max_dt"] = 7.8;

    MinOfDT<ConstantDT<TimeStepper>, BoundsDT<FunctionDT<TimeStepper> > > ts("function", params);

    std::cout<<"MinOfDT<ConstantDT<TimeStepper>, BoundsDT<FunctionDT<TimeStepper> > >: "<<ts.computeDT()<<std::endl;
  }
}
