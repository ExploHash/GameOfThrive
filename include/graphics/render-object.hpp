#ifndef GRAPHICS_RENDER_OBJECT_HPP_INCLUDED
#define GRAPHICS_RENDER_OBJECT_HPP_INCLUDED

#include <vector>


class RenderObject {
  public:
    float x, y;
    std::vector<float> vertices;
    std::vector<float> bg_color;

    RenderObject(float x, float y, std::vector<float> vertices, std::vector<float> bg_color);

    void draw();
};

#endif // GRAPHICS_RENDER_OBJECT_HPP_INCLUDED