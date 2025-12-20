#include "qt_jumping_enemy.hpp"
using biv::QtJumpingEnemy;

QtJumpingEnemy::QtJumpingEnemy(const Coord& top_left, const int width, const int height)
    : JumpingEnemy(top_left, width, height), QtUIObjectRectAdapter(top_left, width, height) {}

void QtJumpingEnemy::paint(QPainter& painter) const {
    painter.setBrush(Qt::green);
    painter.setPen(Qt::black);
    painter.drawRect(get_left(), get_top(), get_width(), get_height());
}

bool QtJumpingEnemy::is_active() const noexcept {
    return Collisionable::is_active();
}
