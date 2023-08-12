#ifndef GRAPHICS_RENDERER_HPP_INCLUDED
#define GRAPHICS_RENDERER_HPP_INCLUDED

#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

#include <vector>
#include "render-object.hpp"

class Renderer {
private:
  GLFWwindow* window;
  GLuint vertexShader;
  GLuint fragmentShader;
  GLuint shaderProgram;
  GLuint VBO;
  GLuint VAO;
  GLuint EBO;
  int width;
  int height;
  std::vector<RenderObject> render_objects;

  void initializeGLFWWindow();
  void initializeOpenGL();
  void initializeShaders();
  void draw();
  static void errorCallback(int error, const char* description);
  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
  static void frameBufferResizeCallback(GLFWwindow* window, int width, int height);
  void addRenderObject(RenderObject render_object);
public:
  void initialize();
  void run();

};

#endif // GRAPHICS_RENDERER_HPP_INCLUDED