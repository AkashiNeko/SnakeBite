#include "snake.h"

Snake::Snake(Body head, Direction d, size_t len) {
    Direction extension = negativeDir(d);
    snake.push_back(head);
    uset.insert(coorHash(head));
    Body tmp;
    while (--len) {
        tmp = tmp.getNextDir(extension);
        snake.push_back(tmp);
        uset.insert(coorHash(head));
    }
}

Snake::~Snake() {}
