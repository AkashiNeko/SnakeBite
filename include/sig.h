#pragma once

#include <iostream>
#include <signal.h>
#include <cstdlib>

#include "style.h"

namespace sig {
    void callback_sigint(int);
}