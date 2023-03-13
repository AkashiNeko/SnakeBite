#include "body.h"

coor_t Body::height = 0;
coor_t Body::width = 0;

Body::Body() :x(0), y(0) {}
Body::Body(coor_t x, coor_t y) : x(x), y(y) {}
Body::Body(coor_hash_t ch) :x(ch & 0xFFFF), y((ch >> 16) & 0xFFFF) {}
Body::~Body() {}

Body Body::getNextDir(Direction dir, coor_t d) {
    switch (d) {
    case Up:    return getNextUp(d);
    case Down:  return getNextDown(d);
    case Left:  return getNextLeft(d);
    case Right: return getNextRight(d);
    default:    exit(-1);
    }
}

Body Body::getNextUp(coor_t d) {
    return Body(x - d >= 0 ? x - d : 0, y);
}

Body Body::getNextDown(coor_t d) {
    return Body(x + d < height ? x + d : height - 1, y);
}

Body Body::getNextLeft(coor_t d) {
    return Body(x, y - d >= 0 ? y - d : 0);
}

Body Body::getNextRight(coor_t d) {
    return Body(x, y + d < width ? y + d : width - 1);
}