#include "enemy_stop.hpp"

using biv::EnemyStop;

EnemyStop::EnemyStop(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {

}

biv::Rect EnemyStop::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed EnemyStop::get_speed() const noexcept {
	return {0, 0};
}

void EnemyStop::process_horizontal_static_collision(Rect* obj) noexcept {

}

void EnemyStop::process_mario_collision(Collisionable* mario) noexcept {
	mario->kill();
}

void EnemyStop::process_vertical_static_collision(Rect* obj) noexcept {

}

