#pragma once

#define HIDDEN_CURSOR "\033[?25l"
#define SHOW_CURSOR   "\033[?25h"

#define DEFAULT   "\033[0m\033[40m"

#define C_RED     "\033[31;1m"
#define C_GREEN   "\033[32;1m"
#define C_YELLOW  "\033[33;1m"
#define C_BLUE    "\033[34;1m"
#define C_MAGENTA "\033[35;1m"
#define C_CYAN    "\033[36;1m"
#define C_WHITE   "\033[37;1m"

#include <iostream>

#ifdef __linux__
    #define CLEAR std::cout << "\033[2J"
#elif _WIN32
    #include <windows.h>
    #include <cstdlib>
    #define CLEAR system("cls")
#endif

inline void setCursor(short x, short y) {
#ifdef __linux__
    std::cout << "\x1B[" << x << ";" << y << "H";
#elif _WIN32
    static HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(ConsoleHandle, {x, y});
#endif
}