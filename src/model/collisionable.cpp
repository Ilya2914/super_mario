#include "collisionable.hpp"

using biv::Collisionable;

bool Collisionable::has_collision(Rect* obj) const noexcept {
	Rect myself = get_rect();
	
	float my_left = myself.get_x();
	float my_right = my_left + myself.get_width();
	float my_top = myself.get_y();
	float my_bottom = my_top + myself.get_height();
	
	float obj_left = obj->get_x();
	float obj_right = obj_left + obj->get_width();
	float obj_top = obj->get_y();
	float obj_bottom = obj_top + obj->get_height();
	
	return (
		my_right > obj_left &&
		my_left < obj_right && 
		my_bottom > obj_top && 
		my_top < obj_bottom
	);
}

bool Collisionable::is_active() const noexcept {
	return is_active_;
}

void Collisionable::kill() noexcept {
	is_active_ = false;
}
