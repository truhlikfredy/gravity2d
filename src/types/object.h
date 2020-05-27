/*
 * author: Anton Krug anton.krug@gmail.com
 * date: 20/04/2020
 */

#ifndef GRAVITY2D_OBJECT_H
#define GRAVITY2D_OBJECT_H

#include <vector>
#include "vector2.h"

template<typename T = double>
class Object {
private:
    T          radius;
    T          weight;
    Vector2<T> velocity;

public:
    Vector2<T>    location;
    unsigned int  color;

    Object(Vector2<T> location, Vector2<T> velocity, unsigned int color, T radius, T weight);

    bool operator==(const Object& secondObject);

    void updateVelocity(std::vector<Object> *objects, T timeDelta);

    void updateLocation(T timeDelta);
};

#endif //GRAVITY2D_OBJECT_H
