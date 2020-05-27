/*
 * author: Anton Krug anton.krug@gmail.com
 * date: 20/04/2020
 */


#ifndef GRAVITY2D_DEBOUNCE_H
#define GRAVITY2D_DEBOUNCE_H

#include <SFML/Window/Keyboard.hpp>

class Debounce {

private:

public:
  static bool pressed[];
  static bool isKeyPressed(sf::Keyboard::Key key);

};

#endif //GRAVITY2D_DEBOUNCE_H
