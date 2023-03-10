#pragma once

#include <cstring>
#include <cstdlib>

typedef unsigned short coor_t;
typedef unsigned int coor_hash_t;

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