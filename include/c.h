#ifndef __H_C_H__
#define __H_C_H__
#include  "labelGeneratorBase.h"
#include <random>
#include <time.h>
#include "class_loader/class_loader.h"
#include <fstream>
#include<iomanip>
namespace micros_label_gen{
    using namespace std;
    class ColorLabelGeneratorPlugin : public LabelGeneratorBase  
    {
        int k; 
    public:
            void print()
            {
                cout<<"class ColorLabelGeneratorPlugin!"<<endl;
            }     
        // void createThread(void *arg);
            //void createThread();
            //void startThread();
           void genLabel(void *);
            int getFlag();
            void setFlag(int s); 
             int getK();
            void setK(int k);
            void setReservedParam(void *);
      		void * getReservedParam();
    };
}
#endif
