#include "app.h"
#include "json/json.hpp"
using json = nlohmann::json;

SnakeBiteApp::SnakeBiteApp(int argCount, char* argVector[])
    :argc(argCount),
    argv(argVector),
    snake(nullptr),
    paint(new Paint()),
    diff(Normal),
    setDiff(false),
    debug(false)
{
    // dispose args
    if (argCount > 2) {
        printOptionError(argVector[1]);
        exit(1);
    }
    else if (argCount == 2) {
        args(argVector[1]);
    }
    initConfig();
    snake = new Snake(Body(Body::height / 2, Body::width / 2));
    
    // print logo "Snake Bite"
    printSnakeBite();
    waitAnyKey();
    initUI();
}

SnakeBiteApp::~SnakeBiteApp() {
    delete snake;
}

int SnakeBiteApp::exec() {
    // execute
    while (1);
    return 0;
}

void SnakeBiteApp::initUI() {
    // clear screen
    CLEAR;
    // set cursor positive
    setCursor(0, 0);
    // draw map border
    paint->drawBorder(Body::height, Body::width);
}

void SnakeBiteApp::args(char* arg) {
    char* p = arg;
    if (*p != '-') {
        printOptionError(arg);
        exit(1);
    }
    ++p;
    switch (*p) {
    case 'h':
        printHelp();
        exit(0);
    case 'v':
        printVersion();
        exit(0);
    case '-':
        ++p;
        break;
    default:
        printOptionError(arg);
        exit(1);
    }
    if (strcmp(p, "easy") == 0) {
        diff = Easy;
        setDiff = true;
    }
    else if (strcmp(p, "normal") == 0) {
        diff = Normal;
        setDiff = true;
    }
    else if (strcmp(p, "hard") == 0) {
        diff = Hard;
        setDiff = true;
    }
    else if (strcmp(p, "help") == 0) {
        printHelp();
        exit(0);
    }
    else if (strcmp(p, "version") == 0) {
        printVersion();
        exit(0);
    }
    else {
        printOptionError(arg);
        exit(1);
    }
}

void SnakeBiteApp::initConfig() {
    json config;
    std::ifstream f("config.json");
    if (!f.is_open()) {
        std::cerr << "File \'config.json\' cannot found." << std::endl;
        std::cerr << "Use the 'cd' command to go to the directory where \'config.json\'." << std::endl;
        return;
    }
    f >> config;
    f.close();
    if (setDiff) {
        const char* diffStr[] = { "Easy", "Normal", "Hard" };
        config["difficulty"] = diffStr[static_cast<int>(diff)];
        std::ofstream f("config.json");
        if (!f.is_open()) {
            std::cerr << "File \'config.json\' cannot found." << std::endl;
            exit(1);
        }
        f << config;
        f.close();
    }
    else {
        string config_diff(config["difficulty"]);
        switch (config_diff[0]) {
        case 'E': case 'e': case '0':
            diff = Easy;
            break;
        case 'N': case 'n': case '1':
            diff = Normal;
            break;
        case 'H': case 'h': case '2':
            diff = Hard;
            break;
        default:
            std::cerr << "Config error: {\"difficulty\": \"" << config_diff << "\"}" << std::endl;
            exit(1);
        }
    }
    Body::height = static_cast<coor_t>(config["size"]["height"]);
    Body::width = static_cast<coor_t>(config["size"]["width"]);

}

void SnakeBiteApp::printHelp() {
    std::cout << "Usage:                                           " << std::endl;
    std::cout << "    snake [options]                              " << std::endl;
    std::cout << "General Options:                                 " << std::endl;
    std::cout << "    -h, --help      Show help.                   " << std::endl;
    std::cout << "    -v, --version   Show version and exit.       " << std::endl;
    std::cout << "    --easy          Set the difficulty to easy.  " << std::endl;
    std::cout << "    --normal        Set the difficulty to normal." << std::endl;
    std::cout << "    --hard          Set the difficulty to hard.  " << std::endl;
}

void SnakeBiteApp::printVersion() {
    std::cout << "Snake Bite 1.0.0" << std::endl;
    std::cout << "https://github.com/AkashiNeko/SnakeBite" << std::endl;
}

void SnakeBiteApp::printOptionError(const char* option) {
    std::cout << "unknown option " << option << std::endl;
    std::cout << "Try \'python -h\' for more information." << std::endl;
}

void SnakeBiteApp::printSnakeBite() {
    // clear screen
    CLEAR;
    // set cursor positive
    setCursor(0, 0);
    std::cout << BG_BLACK << C_CYAN;
    std::cout << "   _____             _         ______ _ _        " << std::endl;
    std::cout << "  /  ___|           | |        | ___ (_) |       " << std::endl;
    std::cout << "  \\ `--. _ __   __ _| | _____  | |_/ /_| |_ ___  " << std::endl;
    std::cout << "   `--. \\ '_ \\ / _` | |/ / _ \\ | ___ \\ | __/ _ \\ " << std::endl;
    std::cout << "  /\\__/ / | | | (_| |   <  __/ | |_/ / | ||  __/ " << std::endl;
    std::cout << "  \\____/|_| |_|\\__,_|_|\\_\\___| \\____/|_|\\__\\___| " << std::endl;
    std::cout << C_BLUE;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << C_WHITE;
    std::cout << "                 \033[37;1mDifficult: ";
    switch (diff) {
    case Easy:
        std::cout << C_GREEN << "Easy" << std::endl;
        break;
    case Normal:
        std::cout << C_YELLOW << "Normal" << std::endl;
        break;
    case Hard:
        std::cout << C_RED << "Hard" << std::endl;
        break;
    default:
        break;
    }
    std::cout << std::endl;
    std::cout << C_MAGENTA;
    std::cout << "          Press any key to start the game" << std::endl;
    std::cout << C_BLUE;
    std::cout << "--------------------------------------------------\033[0m" << std::endl;
}