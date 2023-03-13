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

// class init {
// public:
//     init() {
//         // hidden cursor, black background
//         std::cout << HIDDEN_CURSOR << BG_BLACK << std::endl;
//     }
//     ~init() {
//         // show cursor, default style
//         CLEAR;
//         std::cout << SHOW_CURSOR << DEFAULT << std::endl;
//         setCursor(0, 0);
//     }
// };

// init i;

int main(int argc, char* argv[]) {
    SnakeBiteApp a(argc, argv);
    return a.exec();
}
