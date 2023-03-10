#include "snake.h"

Snake::Snake(Body head, Direction d, size_t len) {
    snake.push_back(head);
    Direction extension = negativeDir(d);
    Body tmp;
    while (--len) {
        tmp = tmp.getNextDir(extension);
        snake.push_back(tmp);
    }
}

Snake::~Snake() {}
