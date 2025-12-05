#include "console_flying_enemy.hpp"

using biv::ConsoleFlyingEnemy;

ConsoleFlyingEnemy::ConsoleFlyingEnemy(const Coord& top_left, const int width, const int height, Game* game) 
	: FlyingEnemy(top_left, width, height, game), Rect(top_left, width, height) {}

char ConsoleFlyingEnemy::get_brush() const noexcept {
	return 'f';
}

bool ConsoleFlyingEnemy::is_active() const noexcept {
	return Collisionable::is_active();
}
