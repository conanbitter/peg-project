#include "appwindow.hpp"
#include <iostream>

class MyScene : public peg::Scene {
   public:
    MyScene(peg::AppWindow& app) : peg::Scene(app){};
    ~MyScene(){};

    virtual void OnUpdate(double timeDelta) {
        std::cout << "Frame-";
    }
};

int main() {
    peg::AppWindow& app = peg::AppWindow::GetInstance();
    app.SetSize(1280, 720);
    app.SetTitle("Example");
    app.SetStyle(peg::WindowStyle::Resizable);
    app.SetVsync(true);

    MyScene sc(app);
    app.SetScene(sc);

    if (app.Init()) {
        app.Run();
    }
    return 0;
}