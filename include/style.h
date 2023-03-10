#pragma once

#define HIDDEN_CURSOR "\033[?25l"
#define SHOW_CURSOR   "\033[?25h"

#define BG_BLACK  "\033[0m\033[40m"
#define DEFAULT   "\033[0m"
#define C_RED     "\033[31;1m"
#define C_GREEN   "\033[32;1m"
#define C_YELLOW  "\033[33;1m"
#define C_BLUE    "\033[34;1m"
#define C_MAGENTA "\033[35;1m"
#define C_CYAN    "\033[36;1m"
#define C_WHITE   "\033[37;1m"
#define BLOCK_BG  "\033[47m"

typedef short cursor_t;

#include <iostream>

#ifdef __linux__
    #define CLEAR std::cout << "\033[2J"
#elif _WIN32
    #include <windows.h>
    #include <cstdlib>
    #define CLEAR system("cls")
#endif

inline void setCursor(cursor_t x, cursor_t y) {
#ifdef __linux__
    std::cout << "\x1B[" << x << ";" << y << "H";
#elif _WIN32
    static HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(ConsoleHandle, {y, x});
#endif
}