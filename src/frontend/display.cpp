/*
 * author: Anton Krug anton.krug@gmail.com
 * date: 20/04/2020
 */

#include <cmath>

#include "display.h"

template<typename T>
Display<T>::Display() {
  pixels = new sf::Uint8[WIDTH * HEIGHT * 4];

  window.create(sf::VideoMode(WIDTH*SCALE, HEIGHT*SCALE), "Anton's gravity2d");
  texture.create(WIDTH, HEIGHT);
  sprite.setTexture(Display::texture);
  sprite.setScale(SCALE, SCALE);
}


template<typename T>
void Display<T>::renderLoop(std::vector<Object<T>> *objects) {
  sf::Event event;

  while (window.pollEvent(event))  {
    if (event.type == sf::Event::Closed) window.close();
  }

  fadeBackground();

  for (auto &object:*objects) {
    object.updateVelocity(objects, 3.0f);
  }

  for (auto &object:*objects) {
    object.updateLocation(3.0f);
    if (
        object.location.x >=0 &&
        object.location.x <= WIDTH &&
        object.location.y >=0 &&
        object.location.y <= HEIGHT
      ) {
        drawCircle(&object);
    }
  }

  window.clear();
  texture.update(pixels);
  window.draw(sprite);
  window.display();
}


template<typename T>
bool Display<T>::keepLooping() {
  return window.isOpen();
}


// https://stackoverflow.com/questions/1201200/fast-algorithm-for-drawing-filled-circles
template<typename T>
void Display<T>::drawCircle(const Object<T> *object) {
  auto pixels32 = (sf::Uint32*)(pixels);
  for (float y = -object->radius; y < object->radius; y++) {
    int width = sqrtf((object->radius * object->radius) - (y * y));
    for (float x = -width; x < width; x++) {
      int offset = (int)(object->location.x + x) + (int)(object->location.y + y) * WIDTH;
      pixels32[offset] = 0xff000000 | object->color;
    }
  }
}


template<typename T>
void Display<T>::fadeBackground() {
  auto pixels32 = (sf::Uint32*)(pixels);
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    if ((pixels32[i] & 0x000000ff) &&  (pixels32[i] & 0x0000ff00) && (pixels32[i] & 0x00ff0000) ) {
      pixels32[i] = pixels32[i] - 0x00010101;
    } else {
      pixels32[i] = (pixels32[i] & 0x00FEFEFE) >> 1;
    }
  }
}


// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
template class Display<double>;
template class Display<float>;
