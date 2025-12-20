#pragma once
#include "game_map.hpp"

namespace biv {
    class QtGame {
    public:
        static int run(int argc, char *argv[]);
    private:
        static GameMap* init();
    };
}
