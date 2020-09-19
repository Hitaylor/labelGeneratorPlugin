#include "b.h"
namespace micros_label_gen
{
  /*
  void Child::createThread(void *arg){
    Child * tmp = (Child*) arg;
    while(tmp->getI()!=1){
      sleep(2);
      tmp->setJ(random());
      printf("j=%d\n",tmp->getJ());
    }
  }*/
  /*void Child::createThread(){
  // Child * tmp = (Child*) arg;
  printf("in the child::createThread(), and i =%d\n",i);
    while(i!=1){
      sleep(2);
    j = random();//修改Child的public类型的成员变量j
      printf("j=%d\n",j);
    }
    printf("in the end of the child::createThread()\n");
  }
  */
  /*
  void Child::startThread(){
    //t = new std::thread(&createThread,this);
    i = 50;
    printf("in the child::startThread()!\n");
    t = std::thread(&Child::createThread,this);
    t.detach();

  /* 这段代码会造成createThread()一直在执行，在调用该函数的地方的后续代码都无法执行，所以这里不能使用while()
    while(i--){
      sleep(2);
      printf("current j=%d\n",j);
    }
    */
  /*if(t.joinable())  t.detach();
    while(i--){
      sleep(1);
    }
    sleep(5);*/
  /*}*/

  void TimeLabelGeneratorPlugin::setFlag(int j)
  {
  cout<<"TimeLabelGeneratorPlugin::setFlag flag="<<j<<endl;
    flag = j;
  }

  int TimeLabelGeneratorPlugin::getFlag()
  {
    return flag;
  }

  void TimeLabelGeneratorPlugin::setJ(int k)
  {
    j = k;
  }

  int TimeLabelGeneratorPlugin::getJ()
  {
    return j;
  }

  void TimeLabelGeneratorPlugin::setReservedParam(void *aParam)
  {
    reservedParam = aParam;
  }

  void *TimeLabelGeneratorPlugin::getReservedParam()
  {
    return reservedParam;
  }

  void TimeLabelGeneratorPlugin::genLabel(void *labelContent)
  {
    //int *value;
    int64_t time_last;
    // ofstream ofile111; //定义输出文件
    // std::cout<<"000000000000000001"<<std::endl;
    // void *tmp;
    while (flag)
    {
    // ofile.open("/home/ok/code/code/out.txt");
    //std::cout<<"222222222222"<<std::endl;
      sleep(2);
      //std::cout<<"3333333333333333333333"<<std::endl;
      time_last = time(NULL); //改成时间函数
      //std::cout<<"4444444444444444444444444"<<std::endl;
      //tmp = value;
      memcpy(labelContent, &time_last, sizeof(time_last));
     // std::cout<<"555555555555555555"<<std::endl;
      printf("&time_last = 0x%0x time_last =%ld, labelContent =0x%0x, *labelConent =%ld\n",&time_last, time_last, labelContent, *((int64_t *)labelContent));
     //ofile << "time：" << *time_last << endl;

     //ofile.close();
    }
  }
} // namespace micros_label_gen

CLASS_LOADER_REGISTER_CLASS(micros_label_gen::TimeLabelGeneratorPlugin, micros_label_gen::LabelGeneratorBase)
