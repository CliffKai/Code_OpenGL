#define GLEW_STATIC//GLEW静态库编译预处理
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
 
const float vertices_data[6] = {
	-0.5, -0.5,
	0.0, 0.5,
	0.5, -0.5
};
 
int main(void)
{
	GLFWwindow* window;
	//![1]初始化glfw库
	if (!glfwInit())  return -1;
	//![2]创建窗口模式窗口及其OpenGL上下文
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();//渲染终止并释放错误回调
		return -1;
	}
	//![3]使窗口的上下文成为当前上下文
	glfwMakeContextCurrent(window);
	//![4]初始化glew,需要首先有上下文环境才能GLEW_OK
	if (glewInit() != GLEW_OK)  return -1;
	std::cout << "GL_VERSION: " << glGetString(GL_VERSION) << std::endl;//版本号
	//初始化
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//设置清除颜色
	//glEnable(GL_DEPTH_TEST);//启动深度缓冲区
	//创建VAO&VBO对象
	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//绑定VAO&VBO对象(先绑VAO)
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//ARRAY数组buffer
	//写入显存buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_data), vertices_data, GL_STATIC_DRAW);//STATIC静态数据存储
	//解析数据
	glEnableVertexAttribArray(0);//启用0供着色器读取
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	//解绑VAO&VBO对象(后放VAO)
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
 
	//![5]循环直到用户关闭窗口
	while (!glfwWindowShouldClose(window))
	{
		//在此处渲染
		//清理
		glClear(GL_COLOR_BUFFER_BIT);//清除上一帧
		//绑定VAO记录的信息
		glBindVertexArray(VAO);
		//绘制
		glDrawArrays(GL_TRIANGLES, 0, 3);//以每三个顶点绘制一个三角形
		//交换前后缓冲并轮询处理事件
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//![6]释放
	glfwTerminate();//渲染终止并释放错误回调
	return 0;
}