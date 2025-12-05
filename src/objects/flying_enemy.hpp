#pragma once

#include "enemy.hpp"

namespace biv {
	class Game;

	class FlyingEnemy : public Enemy {
		private:
			Game* game;
			float start_y;
			float start_x;
			float patrol_distance = 15.0f;

		public:
			FlyingEnemy(const Coord& top_left, const int width, const int height, Game* game);
			
			void move_horizontally() noexcept override;
			void move_vertically() noexcept override;
			
			void move_map_left() noexcept override;
			void move_map_right() noexcept override;

			void process_mario_collision(Collisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
