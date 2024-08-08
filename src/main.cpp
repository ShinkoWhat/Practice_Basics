#include "main.h"

int main() {
  Context::MainContext contextInit;

  while (!glfwWindowShouldClose(contextInit.getWindow()))
  {
      glfwSwapBuffers(contextInit.getWindow());
      glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}

//Constructor for main context
Context::MainContext::MainContext()
{
  initialization();
  createWindow(this);
}

//Instructions for glfw initialization and window creation
int Context::MainContext::initialization()
{
  glfwInit();

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  return 0;
}

void Context::MainContext::createWindow(Context::MainContext* contextInst)
{
  GLFWwindow* window = glfwCreateWindow(800, 600, "MyWindow", NULL, NULL);
  contextInst->setWindow(window);
  if (contextInst->getWindow() == NULL) {
    std::cout << "Failed to create a GLFW window" << std::endl;
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(contextInst->getWindow());
  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(contextInst->getWindow(), framebufferSizeCallback);
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}
