#include "jumping_enemy.hpp"
#include <cstdlib>

using biv::JumpingEnemy;

JumpingEnemy::JumpingEnemy(const Coord& top_left, const int width, const int height) 
	: Enemy(top_left, width, height) {
}

void JumpingEnemy::move_horizontally() noexcept {
	Enemy::move_horizontally();
	
	if (top_left.y > 50) { 
		kill();
		return;
	}
	
	if (on_ground && (rand() % 50 == 0)) {
		vspeed = -0.7f; 
		on_ground = false;
	}
}
