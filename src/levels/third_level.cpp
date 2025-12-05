#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool ThirdLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* ThirdLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void ThirdLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	ui_factory->create_ship({20, 25}, 130, 2);
	
	ui_factory->create_ship({40, 20}, 10, 2);
	ui_factory->create_ship({60, 15}, 10, 2);
	ui_factory->create_ship({80, 10}, 10, 2);
	ui_factory->create_ship({130, 10}, 55, 3);
	
	ui_factory->create_enemy({50, 5}, 3, 2);
	ui_factory->create_flying_enemy({70, 20}, 3, 2);
	ui_factory->create_jumping_enemy({90, 5}, 3, 2);
	ui_factory->create_jumping_enemy({110, 5}, 3, 2);
	ui_factory->create_jumping_enemy({132, 12}, 3, 2);
	ui_factory->create_flying_enemy({130, 20}, 3, 2);
	
	ui_factory->create_full_box({65, 5}, 5, 3);
	ui_factory->create_full_box({85, 2}, 5, 3);
	
	ui_factory->create_full_box({100, 10}, 5, 3);
	ui_factory->create_full_box({120, 10}, 5, 3);
	ui_factory->create_full_box({145, 0}, 5, 3);
	
	ui_factory->create_ship({210, 20}, 10, 7);
	
	ui_factory->finalize_level();
}
