cmake_minimum_required(VERSION 3.26)
project(GameOfThrive)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Find the required packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Add the include directories for the libraries
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})

# Set debug flags
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Wpedantic -Werror -g")


add_executable(GameOfThrive src/main.cpp)

# Link the libraries
target_link_libraries(GameOfThrive ${OPENGL_LIBRARIES})
target_link_libraries(GameOfThrive glfw)