#ifndef __H_B_H__
#define __H_B_H__
#include  "labelGeneratorBase.h"
#include "class_loader/class_loader.h"
#include <time.h>
#include <fstream>
#include<iomanip>
//class_loader/class_loader.h >

#include <random>
namespace micros_label_gen{
    using namespace std;
    
    class TimeLabelGeneratorPlugin : public LabelGeneratorBase  
    {
        int j; 
        
    public:
            void print()
            {
                cout<<"class TimeLabelGeneratorPlugin!"<<endl;
            }   
         //   void createThread();
            //void startThread();
            void genLabel(void *);
            int getJ();
            void setJ(int k);
            int getFlag();
            void setFlag(int s); 
            void setReservedParam(void *);
      		void * getReservedParam();
    };
}
#endif
