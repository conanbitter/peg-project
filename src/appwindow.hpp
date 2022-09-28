#pragma once

#include <utility>
#include <string>
#include <GLFW/glfw3.h>

namespace peg {

enum class WindowStyle {
    Resizable,
    NonResizable,
    Borderless,
    Fullscreen,
    BorderlessFullscreen
};

class AppWindow {
   private:
    bool mIsInited = false;
    bool mIsRunning = false;
    GLFWwindow* mWindow;
    std::pair<int, int> mSize = std::make_pair(640, 480);
    std::string mTitle = "peg|project";
    WindowStyle mStyle = WindowStyle::Resizable;
    bool mVsync = true;

   public:
    double frameTime = 1.0 / 60.0;
    bool Init();
    void Run();
    ~AppWindow();

    std::pair<int, int> GetSize() const { return mSize; }
    std::string GetTitle() const { return mTitle; }
    WindowStyle GetStyle() const { return mStyle; }
    bool GetVsync() const { return mVsync; }

    void SetSize(int width, int height);
    void SetSize(std::pair<int, int> size);
    void SetTitle(const std::string title);
    void SetStyle(WindowStyle style);
    void SetVsync(bool vsync);
};

}  // namespace peg
