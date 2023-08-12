#include "../../include/graphics/renderer.hpp"

void Renderer::errorCallback(int error, const char* description)
{
  fputs(description, stderr);
}

void Renderer::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void Renderer::frameBufferResizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void Renderer::initialize() {
  initializeGLFWWindow();
  initializeOpenGL();
  initializeShaders();
}

void Renderer::initializeGLFWWindow() {
  // Set callback for errors
  glfwSetErrorCallback(errorCallback);

  // Initialize the library
  if (!glfwInit())
    throw std::runtime_error("Failed to initialize GLFW");

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

  // Without these two hints, nothing above OpenGL version 2.1 is supported
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(640, 480, "Running OpenGL on Mac", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    throw std::runtime_error("Failed to create GLFW window");
  }

  // Set callback for window
  glfwSetKeyCallback(window, keyCallback);

  // Set callback for framebuffer
  glfwSetFramebufferSizeCallback(window, frameBufferResizeCallback);

  // Make the window's context current
  glfwMakeContextCurrent(window);

  // Used to avoid screen tearing
  glfwSwapInterval(1);
}

void Renderer::initializeOpenGL() {
  // OpenGL initialization
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void Renderer::initializeShaders() {
  // Initialize VAO and VBO
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  // Bind VAO and VBO
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void Renderer::addRenderObject(RenderObject render_object)
{
}

void Renderer::draw() {
  // Clear the screen
  glClear(GL_COLOR_BUFFER_BIT);

  float vertices1[] = {
       -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
  };

  float triangleColor1[] = { 1.0f, 0.0f, 0.0f };
  glUniform3fv(glGetUniformLocation(shaderProgram, "triangleColor"), 1, triangleColor1);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Draw the triangle
  glDrawArrays(GL_TRIANGLES, 0, 3);

  // Swap front and back buffers
  glfwSwapBuffers(window);

  // Poll for and process events
  glfwPollEvents();
}

void Renderer::run() {
  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window))
  {
    draw();
  }

  // Clean up resources
  glDeleteProgram(shaderProgram);
  glDeleteShader(fragmentShader);
  glDeleteShader(vertexShader);
  glDeleteBuffers(1, &VBO);
  glDeleteVertexArrays(1, &VAO);

  // Terminate GLFW
  glfwTerminate();
}