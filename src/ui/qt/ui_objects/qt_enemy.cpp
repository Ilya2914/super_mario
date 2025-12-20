#include "qt_enemy.hpp"
using biv::QtEnemy;

QtEnemy::QtEnemy(const Coord& top_left, const int width, const int height)
    : Enemy(top_left, width, height), QtUIObjectRectAdapter(top_left, width, height) {}

void QtEnemy::paint(QPainter& painter) const {
    painter.setBrush(Qt::magenta);
    painter.setPen(Qt::black);
    painter.drawRect(get_left(), get_top(), get_width(), get_height());
}

bool QtEnemy::is_active() const noexcept {
    return Collisionable::is_active();
}
