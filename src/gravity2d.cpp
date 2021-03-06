/*
 * author: Anton Krug anton.krug@gmail.com
 * date: 20/04/2020
 */

#include "frontend/display.h"
#include "utils/debounce.h"

#define F_SIZE double

int main() {
  Display<F_SIZE> mainWindow;
  bool            quitRequested = false;

  std::vector<Object<>> objects = { Object<F_SIZE>(Vector2<F_SIZE>(WIDTH/2,     HEIGHT/2), Vector2<F_SIZE>(0.00055,0), 0x88ffff, 25,700000000),
                                    Object<F_SIZE>(Vector2<F_SIZE>(WIDTH/2+100, HEIGHT/2), Vector2<F_SIZE>(0,0.015),  0xffff88, 7, 2000000),
                                    Object<F_SIZE>(Vector2<F_SIZE>(WIDTH/2+95,  HEIGHT/2), Vector2<F_SIZE>(0, 0.017), 0xff88ff, 3, 5000)};

//  std::vector<Object<F_SIZE>> objects = { Object<F_SIZE>(Vector2<F_SIZE>(0, HEIGHT/2),    Vector2<F_SIZE>(0.001, 0.0007),   0xaaffff, 20, 100000  ),
//                                          Object<F_SIZE>(Vector2<F_SIZE>(0, HEIGHT/2+10), Vector2<F_SIZE>(0.0011, -0.0005), 0x8888ff, 6,  50000 )};

  while (mainWindow.keepLooping() && !quitRequested) {

    if (Debounce::isKeyPressed(sf::Keyboard::Q))  {
      // stop gravity2d
      quitRequested = true;
    }

    mainWindow.renderLoop(&objects);
  }

  return 0;
}
