#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//delegates declaration
void framebufferSizeCallback(GLFWwindow* window, int width, int height);

namespace Context {
  class MainContext {
    private:
      int initialization();
      GLFWwindow* _window;

    protected:
      void createWindow(Context::MainContext* contextInst);

    public:
      MainContext(); 

      void setWindow(GLFWwindow* window) {
        Context::MainContext::_window = window;
      }

      GLFWwindow* getWindow() {
        return _window;
      }    
  };
}