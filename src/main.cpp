#include "main.h"

int main() {
  Context::MainContext contextInit;
  glfwInit();
  contextInit.initialization();
  contextInit.createWindow(contextInit);

  std::cout << "Starting main proccess loop" << std::endl;
  while (!glfwWindowShouldClose(contextInit.getWindow()))
  {
      glfwSwapBuffers(contextInit.getWindow());
      glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}

//Instructions for glfw initialization
void Context::MainContext::initialization()
{
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

//constructor
Context::MainContext::MainContext()
{
  //constructor fields initialization
}

void Context::MainContext::createWindow(Context::MainContext& contextInst)
{
  GLFWwindow* window = glfwCreateWindow(800, 600, "MyWindow", NULL, NULL);
  std::cout << window << std::endl;
  contextInst.setWindow(window);
  if (contextInst.getWindow() == NULL) {
    std::cout << "Failed to create a GLFW window. GLFW window value: " << contextInst.getWindow() << std::endl;
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(contextInst.getWindow());
  glfwSetFramebufferSizeCallback(contextInst.getWindow(), framebufferSizeCallback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return;
  }

  //glViewport(0, 0, 800, 600);
}

//framebuffer size change delegate
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}
