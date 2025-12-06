#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "enemy_stop.hpp"

namespace biv {
	class ConsoleEnemyStop : public EnemyStop, public ConsoleUIObjectRectAdapter {
		public:
			ConsoleEnemyStop(const Coord& top_left, const int width, const int height);

			char get_brush() const noexcept override;
			bool is_active() const noexcept override;
	};
}
