#pragma once

#include "game.h"
#include "snake.h"
#include "body.h"
#include "style.h"

#include <iostream>
#include <fstream>
#include <string>
using std::string;


class SnakeBiteApp {
    int argc;
    char** argv;
    Snake* snake;
    Difficulty diff;
    bool setDiff;
public:
    SnakeBiteApp(int argCount, char* argVector[]);
    ~SnakeBiteApp();
    void initConfig();
    int exec();
private:
    void args(char* arg);
    void printHelp();
    void printVersion();
    void printOptionError(const char* option);
    void printSnakeBite();
};