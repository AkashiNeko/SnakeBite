#pragma once

#include "game.h"
#include <vector>
using std::vector;

class Board {
    vector<vector<Block>> b;
public:
    Board(coor_t r, coor_t c);
    ~Board();
    vector<Block>& operator[](size_t index);
};