#include "qt_game.hpp"
#include "game.hpp"
#include "qt_ui_factory.hpp"
#include "first_level.hpp"
#include "qt_game_map.hpp"
#include <QTimer>
#include <QApplication>

namespace biv {
    static Game* game = nullptr;
    static UIFactory* ui_factory = nullptr;
    static GameLevel* game_level = nullptr;
    static Mario* mario = nullptr;
    static QTimer* timer = nullptr;

    int QtGame::run(int argc, char *argv[]) {
        QApplication app(argc, argv);
        
        GameMap* game_map = init();
        game_map->show();
        
        return app.exec();
    }

    GameMap* QtGame::init() {
        game = new Game();
        ui_factory = new QtUIFactory(game);
        GameMap* game_map = ui_factory->get_game_map();
        game_level = new FirstLevel(ui_factory);
        mario = ui_factory->get_mario();
        
        timer = new QTimer();
        QObject::connect(timer, &QTimer::timeout, [game_map]() {
            auto* qt_map = dynamic_cast<QtGameMap*>(game_map);
            biv::os::UserInput user_input = qt_map ? qt_map->get_input() : biv::os::UserInput::NO_INPUT;

            switch (user_input) {
                case biv::os::UserInput::MAP_LEFT:
                    mario->move_map_left();
                    if (!game->check_static_collisions(mario)) {
                        game->move_map_left();
                    }
                    mario->move_map_right();
                    break;
                case biv::os::UserInput::MAP_RIGHT:
                    mario->move_map_right();
                    if (!game->check_static_collisions(mario)) {
                        game->move_map_right();
                    }
                    mario->move_map_left();
                    break;
                case biv::os::UserInput::MARIO_JUMP:
                    mario->jump();
                    break;
                case biv::os::UserInput::EXIT:
                    game->finish();
                    break;
                default:
                    break;
            }
            
            game->move_objs_horizontally();
            game->check_horizontally_static_collisions();
            
            game->move_objs_vertically();
            game->check_mario_collision();
            game->check_vertically_static_collisions();
            
            if (
                game_map->is_below_map(mario->get_top())
                || !mario->is_active()
            ) {
                game_level->restart();
                game->start_level();
                mario = ui_factory->get_mario();
            }
            
            if (game->is_level_end()) {
                if (!game_level->is_final()) {
                    game_level = game_level->get_next();
                    mario = ui_factory->get_mario();
                    game->start_level();
                } else {
                    game->finish();
                }
            }
            
            game_map->refresh();
            
            if (game->is_finished()) {
                QApplication::quit();
            }
        });
        
        timer->start(16);
        return game_map;
    }
}
