#include <GLFW/glfw3.h>

namespace peg {

class AppWindow {
   private:
    bool inited = false;
    GLFWwindow* window;

   public:
    bool Init(int width, int height, const char* title);
    void Run();
    ~AppWindow();
};

}  // namespace peg
