#include "appwindow.hpp"

int main() {
    peg::AppWindow app;
    app.SetSize(1280, 720);
    app.SetTitle("Example");
    app.SetStyle(peg::WindowStyle::Resizable);
    app.SetVsync(true);
    if (app.Init()) {
        app.Run();
    }
    return 0;
}