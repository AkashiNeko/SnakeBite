#include "paint.h"

std::string Paint::blockColor = BLOCK_BG;
std::string Paint::block = "  ";

Paint::Paint(cursor_t x, cursor_t y) :originX(x), originY(y) {}

void Paint::drawBorder(coor_t height, coor_t width) {
    cout << blockColor;
    setPositive(0, 0);
    for (coor_t i = 0; i < width + 3; ++i)
        cout << block;
    setPositive(height + 2, 0);
    for (coor_t i = 0; i < width + 3; ++i)
        cout << block;
    for (coor_t i = 1; i < height + 2; ++i) {
        setPositive(i, 0);
        cout << block;
        setPositive(i, width + 2);
        cout << block;
    }
    cout << BG_BLACK;
}
