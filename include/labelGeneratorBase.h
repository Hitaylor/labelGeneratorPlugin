#ifndef __H_LABEL_GENERATOR_BASE_H__
#define __H_LABEL_GENERATOR_BASE_H__
#include <iostream>
#include <stdio.h>
#include <unistd.h>
//#include <thread>
namespace micros_label_gen{
  using namespace std;

  class LabelGeneratorBase
  
  {
    public:
      int flag;
      void * reservedParam;
  //    std::thread t;
  public:
      virtual void print() { }
  //    virtual void startThread(){}
      virtual void genLabel(void *){}
      virtual void setFlag(int j){}
      virtual int getFlag(){}
      virtual void setReservedParam(void *){}
      virtual void * getReservedParam(){}
  };
}

#endif
