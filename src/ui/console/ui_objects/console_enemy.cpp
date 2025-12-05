#include "console_enemy.hpp"

using biv::ConsoleEnemy;

ConsoleEnemy::ConsoleEnemy(const Coord& top_left, const int width, const int height) 
	: Enemy(top_left, width, height), Rect(top_left, width, height) {}

char ConsoleEnemy::get_brush() const noexcept {
	return 'e';
}

bool ConsoleEnemy::is_active() const noexcept {
	return Collisionable::is_active();
}
