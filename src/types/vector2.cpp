/*
 * author: Anton Krug anton.krug@gmail.com
 * date: 20/04/2020
 */

#include <cmath>

#include "vector2.h"


template<typename T> Vector2<T>::Vector2(T x, T y): x(x), y(y) { }


template<typename T>
Vector2<T>::Vector2(const Vector2<T>& base): x(base.x), y(base.y){ }


template<typename T>
bool Vector2<T>::operator==(const Vector2<T> &secondVector) {
  return true;
}


template<typename T>
Vector2<T> Vector2<T>::operator+(Vector2<T> secondVector) {
  return Vector2(this->x + secondVector.x, this->y + secondVector.y);
}


template<typename T>
void Vector2<T>::operator+=(Vector2<T> secondVector) {
  this->x += secondVector.x;
  this->y += secondVector.y;
}


template<typename T>
Vector2<T> Vector2<T>::operator-(Vector2<T> secondVector) {
  return Vector2(this->x - secondVector.x, this->y - secondVector.y);
}


template<typename T>
void Vector2<T>::operator-=(Vector2<T> secondVector) {
  this->x -= secondVector.x;
  this->y -= secondVector.y;
}


template<typename T>
Vector2<T> Vector2<T>::operator-(T scalar) {
  return Vector2(this->x - scalar, this->y - scalar);
}


template<typename T>
void Vector2<T>::operator-=(T scalar) {
  this->x -= scalar;
  this->y -= scalar;
}


template<typename T>
Vector2<T> Vector2<T>::operator*(T scalar) {
  return Vector2(this->x * scalar, this->y * scalar);
}


template<typename T>
void Vector2<T>::operator*=(T scalar) {
  this->x *= scalar;
  this->y *= scalar;
}


template<typename T>
Vector2<T> Vector2<T>::operator*(Vector2<T> secondVector) {
  return Vector2(this->x * secondVector.x, this->y * secondVector.y);
}


template<typename T>
void Vector2<T>::operator*=(Vector2<T> secondVector) {
  this->x *= secondVector.x;
  this->y *= secondVector.y;
}


template<typename T>
Vector2<T> Vector2<T>::operator/(T scalar) {
  return Vector2(this->x / scalar, this->y / scalar);
}


template<typename T>
void Vector2<T>::operator/=(T scalar) {
  this->x /= scalar;
  this->y /= scalar;
}


template<typename T>
T Vector2<T>::dot(Vector2<T> secondVector) {
  return (x * secondVector.x + y * secondVector.y);
}


template<typename T>
Vector2<T> Vector2<T>::normalize() {
  const T magnitude = sqrt(x * x + y * y);
  return Vector2(x / magnitude, y / magnitude);
}


template<typename T>
Vector2<T> Vector2<T>::normalize(Vector2<T> secondVector) {
  const auto difference = *this - secondVector;
  const T magnitude = sqrt(difference.x * difference.x + difference.y * difference.y);
  return Vector2(difference.x / magnitude, difference.y / magnitude);
}


template<typename T>
T Vector2<T>::distance(Vector2<T> secondVector) {
  return sqrtf(powf(this->x - secondVector.x, 2) +
               powf(this->y - secondVector.y, 2));
}


template<typename T>
T Vector2<T>::distanceSquared(Vector2<T> secondVector) {
  return powf(this->x - secondVector.x, 2) +
         powf(this->y - secondVector.y, 2);
}

// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
template class Vector2<double>;
template class Vector2<float>;