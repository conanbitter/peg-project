#include "appwindow.hpp"

using namespace peg;

bool AppWindow::Init() {
    if (!glfwInit())
        return false;

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);
    int screenWidth = videoMode->width;
    int screenHeight = videoMode->height;
    if (mStyle == WindowStyle::BorderlessFullscreen) {
        mSize = std::make_pair(screenWidth, screenHeight);
    }
    bool isFullscreen = mStyle == WindowStyle::BorderlessFullscreen || mStyle == WindowStyle::Fullscreen;

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, mStyle == WindowStyle::Resizable ? GLFW_TRUE : GLFW_FALSE);
    glfwWindowHint(
        GLFW_DECORATED,
        mStyle == WindowStyle::Resizable || mStyle == WindowStyle::NonResizable ? GLFW_TRUE : GLFW_FALSE);

    mWindow = glfwCreateWindow(mSize.first, mSize.second, mTitle.c_str(), isFullscreen ? monitor : NULL, NULL);
    if (!mWindow) {
        glfwTerminate();
        return false;
    }
    glfwSetWindowPos(mWindow, (screenWidth - mSize.first) / 2, (screenHeight - mSize.second) / 2);
    glfwShowWindow(mWindow);

    glfwMakeContextCurrent(mWindow);

    glfwSwapInterval(mVsync ? 1 : 0);

    mIsInited = true;

    return true;
}

void AppWindow::Run() {
    if (!mIsInited) {
        return;
    }

    mIsRunning = true;

    while (!glfwWindowShouldClose(mWindow) && mIsRunning) {
        currentScene->OnUpdate(0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        currentScene->OnDraw(0.0);
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }
}

AppWindow::~AppWindow() {
    glfwTerminate();
}

void AppWindow::SetSize(int width, int height) {
    mSize = std::make_pair(width, height);
}

void AppWindow::SetSize(std::pair<int, int> size) {
    mSize = size;
}

void AppWindow::SetTitle(const std::string title) {
    mTitle = title;
}

void AppWindow::SetStyle(WindowStyle style) {
    mStyle = style;
}

void AppWindow::SetVsync(bool vsync) {
    mVsync = vsync;
}

void AppWindow::SetScene(Scene& scene) {
    currentScene = &scene;
    if (!scene.loaded) {
        scene.OnLoad();
        scene.loaded = true;
    }
}

Scene::Scene(AppWindow& appWindow) : app{appWindow} {}