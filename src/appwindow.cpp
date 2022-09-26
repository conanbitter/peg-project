#include "appwindow.hpp"

using namespace peg;

bool AppWindow::Init(int width, int height, const char* title) {
    if (!glfwInit())
        return false;

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    inited = true;

    return true;
}

void AppWindow::Run() {
    if (!inited) {
        return;
    }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

AppWindow::~AppWindow() {
    glfwTerminate();
}