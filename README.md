# Code_OpenGL
About OpenGL's Simple Programming Environment (on VSCode)

## 使用须知
这是一个在vscode上使用glew glfw glad freeglut四种库进行OpenGL开发的环境配置

## 你需要准备的环境有
MinGW, install gcc、g++、gdb 和 mingw32-make（其实只需要装一个MinGW然后依次安装就可以了），这里需要注意gcc版本需要9.2，如果是6.0可能会出一些问题，装完后记得添加环境变量

## 准备工作
你需要将c_cpp_properties的include和编译环境改成你自己的MinGW安装路径

## 后续更新
以后可能会根据课程需要继续添加UI库imgui和模型库assimp