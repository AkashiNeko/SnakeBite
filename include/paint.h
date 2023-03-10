#pragma once

#include "game.h"
#include "style.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Paint {
public:
    cursor_t originX;
    cursor_t originY;
    static std::string blockColor;
    static std::string block;
    Paint(cursor_t x = 1, cursor_t y = 2);
    void drawBorder(coor_t height, coor_t width);
    inline void setPositive(coor_t x, coor_t y) {
        setCursor(originX + x, originY + 2 * y);
    }
    inline void setBlock(coor_t x, coor_t y) {
        setPositive(x, y);
        cout << block;
    }
};