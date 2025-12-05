#pragma once

#include "enemy.hpp"

namespace biv {
	class JumpingEnemy : public Enemy {
		public:
			JumpingEnemy(const Coord& top_left, const int width, const int height);
			
			void move_horizontally() noexcept override;
	};
}
