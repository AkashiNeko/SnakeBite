#pragma once

#include "game.h"

class Body {
public:
    coor_t x;
    coor_t y;
    static coor_t height;
    static coor_t width;
public:
    Body();
    Body(coor_t x, coor_t y);
    ~Body();
    Body getNextDir(Direction dir, coor_t d = 1);
    Body getNextUp(coor_t d = 1);
    Body getNextDown(coor_t d = 1);
    Body getNextLeft(coor_t d = 1);
    Body getNextRight(coor_t d = 1);
};