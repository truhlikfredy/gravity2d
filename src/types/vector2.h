/*
 * author: Anton Krug anton.krug@gmail.com
 * date: 20/04/2020
 */

#ifndef GRAVITY2D_Vector2_H_
#define GRAVITY2D_Vector2_H_

template<typename T = double>
class Vector2 {

public:
  // Fields
  T x, y;

  // Constructors
  Vector2();

  Vector2(T xInit, T yInit);

  Vector2(const Vector2& base);

  // Operators
  bool operator==(const Vector2& secondVector);

  Vector2 operator+(Vector2 secondVector);

  void operator+=(Vector2 secondVector);

  Vector2 operator-(Vector2 secondVector);

  void operator-=(Vector2 secondVector);

  Vector2 operator-(T scalar);

  void operator-=(T scalar);

  Vector2 operator*(T scalar);

  void operator*=(T scalar);

  Vector2 operator*(Vector2 secondVector);

  void operator*=(Vector2 secondVector);

  Vector2 operator/(T scalar);

  void operator/=(T scalar);

  // Functions
  T dot(Vector2 secondVector);

  Vector2 normalize();

  Vector2 normalize(Vector2 secondVector);

  T distance(Vector2 secondVector);

  T distanceSquared(Vector2 secondVector);

  T sum();

  T lenght();

  Vector2 min(Vector2 secondVector);

  Vector2 max(Vector2 secondVector);

  T min();

  T max();

  Vector2 invert();

  bool isZero();
};

#endif /* VECTOR_H_ */
