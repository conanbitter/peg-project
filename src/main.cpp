#include "appwindow.hpp"

int main() {
    peg::AppWindow app;
    if (app.Init(640, 480, "Hello World")) {
        app.Run();
    }
    return 0;
}