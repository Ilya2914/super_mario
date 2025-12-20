#pragma once
#include "enemy_stop.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
    class QtEnemyStop : public EnemyStop, public QtUIObjectRectAdapter {
        public:
            QtEnemyStop(const Coord& top_left, const int width, const int height);
            void paint(QPainter& painter) const override;
            bool is_active() const noexcept override;
    };
}
