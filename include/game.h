#pragma once

#include <cstring>
#include <cstdlib>

typedef uint16_t coor_t;
typedef uint32_t coor_hash_t;

enum Direction { Up, Down, Left, Right };

enum Difficulty { Easy, Normal, Hard };

inline Direction negativeDir(Direction d) {
    switch (d) {
    case Up: return Down;
    case Down: return Up;
    case Left: return Right;
    case Right: return Left;
    default: exit(-1);
    }
}