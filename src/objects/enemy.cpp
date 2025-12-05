#include "enemy.hpp"

#include "map_movable.hpp"

using biv::Enemy;

Enemy::Enemy(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
}

biv::Rect Enemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed Enemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void Enemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void Enemy::process_mario_collision(Collisionable* mario) noexcept {
	Rect mario_rect = mario->get_rect();
	Rect enemy_rect = get_rect();

	// Марио убивает врага, если падает и его ноги находятся в верхней части врага
	bool is_falling = mario->get_speed().v > 0;
	bool is_above = mario_rect.get_bottom() < enemy_rect.get_y() + enemy_rect.get_height() * 0.7f;

	if (is_falling && is_above) {
		kill();
	} else {
		mario->kill();
	}
}

void Enemy::process_vertical_static_collision(Rect* obj) noexcept {
	top_left.x += hspeed;
	if (!has_collision(obj)) {
		process_horizontal_static_collision(obj);
	} else {
		top_left.x -= hspeed;
	}
	
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
		on_ground = true;
	}
}
