#include "c.h"
CLASS_LOADER_REGISTER_CLASS(micros_label_gen::ColorLabelGeneratorPlugin, micros_label_gen::LabelGeneratorBase)

namespace micros_label_gen
{
  /*
  void Child2::createThread(void *arg){
    Child2 * tmp = (Child2*) arg;
    while(tmp->getI()!=1){
      sleep(3);
      tmp->setK(random());
      printf("k=%d\n",tmp->getK());
    }
  }*/
  /*
  void Child2::createThread(){
    //Child2 * tmp = (Child2*) arg;
    while(i!=1){
      sleep(3);
      k = random();//修改Child2的public类型的成员变量k
      printf("k=%d\n",k);
    }
  }
*/
  /*
  void Child2::startThread(){
    i = 100;
    t = std::thread(&Child2::createThread,this);
    t.detach();
    //if(t.joinable())  t.detach();
    /* 这段代码会造成createThread()一直在执行，在调用该函数的地方的后续代码都无法执行，所以这里不能使用while()
    while(i--){
      sleep(3);
      printf("current k=%d\n",k);
    }*/
  /*}
*/
  void ColorLabelGeneratorPlugin::genLabel(void *labelContent)
  {

    if (labelContent == NULL)
    {
      throw("NullPointerException：labelContent in ColorLabelGeneratorPlugin::genLabel(labelContent)");
      return; //这个是否不会执行？如果不执行，就删掉
    }
   // ofstream ofile;
    
//ofile.open("/home/ok/code/code/out.txt");
    char color[3] = {-1, -1, -1};
    //ofstream ofile("/home/ok/code/code/out.txt",ofstream::app); //定义输出文件
    while (flag)
    {
      
      
      color[0] = random() % 256;
      color[1] = random() % 256;
      color[2] = random() % 256;
      printf("color(R,G,B)=(%d,%d,%d)\n", color[0], color[1], color[2]);
      memcpy(labelContent, (void *)color, 3);
      //sleep(5);
   //   std::cout<<"YYYYYYTTTT"<<std::endl;
      //ofile<<"color: "<< color[0]<<color[1]<<color[2]<<endl;
      
      sleep(1);
    }
  // ofile.close();
  }

  void ColorLabelGeneratorPlugin::setReservedParam(void *aParam)
  {
    reservedParam = aParam;
  }

  void *ColorLabelGeneratorPlugin::getReservedParam()
  {
    return reservedParam;
  }

  void ColorLabelGeneratorPlugin::setFlag(int j)
  {
    cout<<"ColorLabelGeneratorPlugin::setFlag flag="<<j<<endl;
    flag = j;
  }

  int ColorLabelGeneratorPlugin::getFlag()
  {
    return flag;
  }

  void ColorLabelGeneratorPlugin::setK(int j)
  {
    k = j;
  }

  int ColorLabelGeneratorPlugin::getK()
  {
    return k;
  }
} // namespace micros_label_gen
