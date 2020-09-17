# labelGeneratorPlugin
1. 此为标签生成器框架，依赖于class_loader这个第三方框架(源代码：https://github.com/ros/class_loader ，相关介绍：http://wiki.ros.org/class_loader)。
2. 用户实现标签生成器插件只需要继承基类LabelGeneratorBase并实现相关接口，并按照class_loader的要求导出子类和基类的关系即可，用户可以在子类里增加其他函数或变量。

v0.1 提供插件示例并生成测试程序、打包形成动态库
1. 本版本的lib目录下的libclass_loader.so是基于ubuntu 20.04 x64平台采用无ros环境的cmake方式编译得到的。如果该so文件无法使用，请下载源码生成（参考其给出的CmakeLists.txt）。
2. 本版本实现了2个简单的标签生成器插件，可供用户参考借鉴。
3. CMakeLists.txt里面的内容规定将本工程的test目录下的文件生成测试程序并将本工程include和src目录下的头文件和cpp文件打包生成动态库，该动态库配合libclass_loader.so和include下的基类文件即可放到独立环境中使用。
