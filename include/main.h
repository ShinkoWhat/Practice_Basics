#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//delegates declaration
void framebufferSizeCallback(GLFWwindow* window, int width, int height);

namespace Context {
  class MainContext {
    private:
      GLFWwindow* _window;

    protected:
      
    public:
      MainContext(); 

      void setWindow(GLFWwindow* window) {
        Context::MainContext::_window = window;
      }

      GLFWwindow* getWindow() {
        return _window;
      }    

      void createWindow(Context::MainContext& contextInst);
      void initialization();
  };
}