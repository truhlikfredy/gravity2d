/*
 * author: Anton Krug anton.krug@gmail.com
 * date: 20/04/2020
 */

#ifndef GRAVITY2D_DISPLAY_H
#define GRAVITY2D_DISPLAY_H

#define WIDTH  320
#define HEIGHT 240
#define SCALE 4.0

#include <SFML/Graphics.hpp>
#include "../types/object.h"

template<typename T = double>
class Display {
private:
  sf::Texture      texture;
  sf::Uint8*       pixels;
  sf::Sprite       sprite;
  sf::RenderWindow window;

public:
  Display();

  void renderLoop(std::vector<Object<T>> *objects);
  bool keepLooping();
};

#endif //GRAVITY2D_DISPLAY_H
