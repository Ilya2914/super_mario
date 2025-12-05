#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "flying_enemy.hpp"

namespace biv {
	class ConsoleFlyingEnemy : public FlyingEnemy, public ConsoleUIObjectRectAdapter {
		public:
			ConsoleFlyingEnemy(const Coord& top_left, const int width, const int height, Game* game);

			char get_brush() const noexcept override;
			bool is_active() const noexcept override;
	};
}
