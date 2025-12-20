#include "qt_money.hpp"
using biv::QtMoney;

QtMoney::QtMoney(const Coord& top_left, const int width, const int height)
    : Money(top_left, width, height), QtUIObjectRectAdapter(top_left, width, height) {}

void QtMoney::paint(QPainter& painter) const {
    painter.setBrush(Qt::yellow);
    painter.setPen(Qt::black);
    painter.drawEllipse(get_left(), get_top(), get_width(), get_height());
}

bool QtMoney::is_active() const noexcept {
    return Collisionable::is_active();
}
