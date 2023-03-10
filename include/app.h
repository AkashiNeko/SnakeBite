#pragma once

#include "game.h"
#include "snake.h"
#include "body.h"
#include "style.h"
#include "paint.h"

#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
#include <conio.h>
#endif

inline void waitAnyKey() {
#ifdef _WIN32
    getch();
#else
    getchar();
#endif
}

using std::string;

class SnakeBiteApp {
    int argc;
    char** argv;
    Snake* snake;
    Paint* paint;
    Difficulty diff;
    bool setDiff;
    bool debug;
public:
    SnakeBiteApp(int argCount, char* argVector[]);
    ~SnakeBiteApp();
    int exec();
    void initUI();
private:
    void args(char* arg);
    void initConfig();
    void printHelp();
    void printVersion();
    void printOptionError(const char* option);
    void printSnakeBite();
    
};