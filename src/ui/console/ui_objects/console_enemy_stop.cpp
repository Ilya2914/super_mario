#include "console_enemy_stop.hpp"

using biv::ConsoleEnemyStop;

ConsoleEnemyStop::ConsoleEnemyStop(const Coord& top_left, const int width, const int height) 
	: EnemyStop(top_left, width, height), Rect(top_left, width, height) {}

char ConsoleEnemyStop::get_brush() const noexcept {
	return 'S'; 
}

bool ConsoleEnemyStop::is_active() const noexcept {
	return Collisionable::is_active();
}
