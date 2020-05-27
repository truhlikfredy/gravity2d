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

  for (auto &object:*objects) {
    object.updateVelocity(objects, 3.0f);
  }

  for (int i=0; i< 100; i++) {

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
//      auto offset = ((int)(object.location.x) + (int)(object.location.y) * WIDTH )* 4;
//      pixels[offset] = 0xff;
//      pixels[offset+3] = 0xff;
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
  for (float y = -object->radius; y < object->radius; y++) {
    int width = sqrtf((object->radius * object->radius) - (y * y));
    for (float x = -width; x < width; x++) {
      int offset = ((int)(object->location.x + x) + (int)(object->location.y + y) * WIDTH )* 4;
      pixels[offset + 0] = 0xff;
      pixels[offset + 1] = 0xff;
      pixels[offset + 2] = 0xff;
      pixels[offset + 3] = 0xff;
    }
  }

}


// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
template class Display<double>;
template class Display<float>;
