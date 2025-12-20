#include "qt_enemy_stop.hpp"
using biv::QtEnemyStop;

QtEnemyStop::QtEnemyStop(const Coord& top_left, const int width, const int height)
    : EnemyStop(top_left, width, height), QtUIObjectRectAdapter(top_left, width, height) {}

void QtEnemyStop::paint(QPainter& painter) const {
    painter.setBrush(Qt::darkMagenta);
    painter.setPen(Qt::black);
    painter.drawRect(get_left(), get_top(), get_width(), get_height());
}

bool QtEnemyStop::is_active() const noexcept {
    return Collisionable::is_active();
}
