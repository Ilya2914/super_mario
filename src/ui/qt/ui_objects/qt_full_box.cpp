#include "qt_full_box.hpp"
using biv::QtFullBox;

QtFullBox::QtFullBox(const Coord& top_left, const int width, const int height, UIFactory* ui_factory)
    : FullBox(top_left, width, height, ui_factory), QtUIObjectRectAdapter(top_left, width, height) {}

void QtFullBox::paint(QPainter& painter) const {
    painter.setBrush(Qt::yellow);
    painter.setPen(Qt::black);
    painter.drawRect(get_left(), get_top(), get_width(), get_height());
    painter.drawText(get_left(), get_top(), get_width(), get_height(), Qt::AlignCenter, "?");
}

bool QtFullBox::is_active() const noexcept {
    return Collisionable::is_active();
}
