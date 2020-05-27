/*
 * author: Anton Krug anton.krug@gmail.com
 * date: 20/04/2020
 */

#include "object.h"

#define BIG_G 6.674e-11

template<typename T>
Object<T>::Object(Vector2<T> location, Vector2<T> velocity, unsigned int color, T radius, T weight):
  location(location), velocity(velocity), radius(radius), color(color), weight(weight) {
}


template<typename T>
bool Object<T>::operator==(const Object &secondObject) {
  return location == secondObject.location &&
         velocity == secondObject.location &&
         color    == secondObject.color &&
         radius   == secondObject.radius &&
         weight   == secondObject.weight;
}


template<typename T>
void Object<T>::updateVelocity(std::vector<Object> *objects, T timeDelta) {
  for (auto object:*objects) {
    if (!(object == *this)) {
      // Calculate on all objects except myself
      // https://en.wikipedia.org/wiki/Newton%27s_law_of_universal_gravitation
      auto distanceSquared = this->location.distanceSquared(object.location);
      auto forceDirection  = (object.location - this->location).normalize();
      auto acceleration    = (forceDirection * object.weight * BIG_G) / distanceSquared; // no need to calculate force

      velocity += acceleration * timeDelta;
    }
  }
}


template<typename T>
void Object<T>::updateLocation(T timeDelta) {
  location += velocity * timeDelta;
}

// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
template class Object<double>;
template class Object<float>;
