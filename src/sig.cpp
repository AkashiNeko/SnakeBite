#include "sig.h"

void sig::callback_sigint(int) {
    setCursor(0, 0);
    std::cout << SHOW_CURSOR << DEFAULT;
    CLEAR;
    std::cout << "snakebite exit." << std::endl;
    exit(0);
}