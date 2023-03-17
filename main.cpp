#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
//����������������ӵ���glew32s.libʱ��˵���������Ǿ�̬�⡣��ʱ��Ҫ��#include <GL/glew.h>ǰ��� #define GLEW_STATIC��

int main() {
    glfwInit();//��ʼ��
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//���汾��
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//�ΰ汾��
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "My First OpenGL Project", NULL, NULL);//��һ��800*600�Ĵ���
    if (window == NULL) {
        printf("failed...");
        glfwTerminate();//�رմ���
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