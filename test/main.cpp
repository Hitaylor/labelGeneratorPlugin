#include "b.h"
#include "c.h"

using namespace std;
using namespace micros_label_gen;
int main()
{
   TimeLabelGeneratorPlugin c1;
   ColorLabelGeneratorPlugin c2;
   // std::thread t1(std::bind(&Child::createThread),&c1,&c1),t2(std::bind(&Child2::createThread,&c2,&c2));
    LabelGeneratorBase *t, *t2; 
   t = new TimeLabelGeneratorPlugin();
    
    t->print();     
    //t->startThread();
    
    cout<<"SIZEOF Parent:"<<sizeof(t)<<endl;

    t2 = new ColorLabelGeneratorPlugin();
    t2->print();
    //t2->startThread();
    //下面保留一个延迟函数，确保main线程不会结束，否则前面创建的2个线程会随着main线程的结束而退出！
    getchar();
   cout<<"main thread exit()\n"<<endl; 
}