#include "flying_enemy.hpp"
#include "game.hpp"
#include "mario.hpp"

#include <cmath>

using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(const Coord& top_left, const int width, const int height, Game* game) 
	: Enemy(top_left, width, height), game(game) {
	hspeed = 0.3;
	start_y = top_left.y;
	start_x = top_left.x;
}

void FlyingEnemy::move_horizontally() noexcept {
	float next_x = top_left.x + hspeed;
	Rect next_rect({next_x, top_left.y}, width, height);
	if (game->check_static_collisions(next_rect)) {
		hspeed = -hspeed;
		return;
	}

	Rect ground_check({next_x, top_left.y + height}, width, 5);
	if (!game->check_static_collisions(ground_check)) {
		hspeed = -hspeed;
		return;
	}

	Movable::move_horizontally();
}

void FlyingEnemy::move_vertically() noexcept {
}

void FlyingEnemy::move_map_left() noexcept {
	RectMapMovableAdapter::move_map_left();
	start_x -= MapMovable::MAP_STEP;
}

void FlyingEnemy::move_map_right() noexcept {
	RectMapMovableAdapter::move_map_right();
	start_x += MapMovable::MAP_STEP;
}

void FlyingEnemy::process_mario_collision(Collisionable* obj) noexcept {
	Mario* mario = static_cast<Mario*>(obj);
	Rect mario_rect = mario->get_rect();
	Rect enemy_rect = get_rect();

	bool is_falling = mario->get_speed().v > 0;
	bool is_above = mario_rect.get_bottom() < enemy_rect.get_y() + enemy_rect.get_height() * 0.7f;

	if (is_falling && is_above) {
		kill();
		mario->jump(); 
	} else {
		mario->kill();
	}
}

void FlyingEnemy::process_vertical_static_collision(Rect* obj) noexcept {

}
