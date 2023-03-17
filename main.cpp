#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
//当你在链接器中添加的是glew32s.lib时，说明你编译的是静态库。此时你要在#include <GL/glew.h>前添加 #define GLEW_STATIC。

int main() {
    glfwInit();//初始化
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//次版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "My First OpenGL Project", NULL, NULL);//打开一个800*600的窗口
    if (window == NULL) {
        printf("failed...");
        glfwTerminate();//关闭窗口
        return -1;
    }
    glfwMakeContextCurrent(window);


    glewExperimental = true;
    if (glewInit()!= GLEW_OK) {
        printf("failed...");
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 800, 600);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}