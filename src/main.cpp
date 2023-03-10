/**
 *      _      _                    _       _   _   _          _            
 *     / \    | | __   __ _   ___  | |__   (_) | \ | |   ___  | | __   ___  
 *    / _ \   | |/ /  / _` | / __| | '_ \  | | |  \| |  / _ \ | |/ /  / _ \ 
 *   / ___ \  |   <  | (_| | \__ \ | | | | | | | |\  | |  __/ |   <  | (_) |
 *  /_/   \_\ |_|\_\  \__,_| |___/ |_| |_| |_| |_| \_|  \___| |_|\_\  \___/ 
 * 
 * 
 *  Date: 2023-3-9
 *  
 */

#include "app.h"

//#define DEBUG

#ifdef DEBUG
#include "app.h"
#include "board.h"
#include "snake.h"
#include "snakebody.h"
#include "game.h"

int main() {

    return 0;
}

#else

int main(int argc, char* argv[]) {
    SnakeBiteApp a(argc, argv);
    a.initConfig();
    return a.exec();
}

#endif