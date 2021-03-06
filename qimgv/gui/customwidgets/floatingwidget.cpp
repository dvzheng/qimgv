#include "floatingwidget.h"

FloatingWidget::FloatingWidget(FloatingWidgetContainer *parent) : QWidget(parent), mAcceptKeyboardFocus(false) {
    this->setAccessibleName("OverlayWidget");
    connect(parent, &FloatingWidgetContainer::resized, this, &FloatingWidget::onContainerResized);
    hide();
}

QSize FloatingWidget::containerSize() {
    return container;
}

void FloatingWidget::setContainerSize(QSize container) {
    this->container = container;
    recalculateGeometry();
}

void FloatingWidget::onContainerResized(QSize size) {
    setContainerSize(size);
}

void FloatingWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool FloatingWidget::acceptKeyboardFocus() const {
    return mAcceptKeyboardFocus;

}
void FloatingWidget::setAcceptKeyboardFocus(bool mode) {
    mAcceptKeyboardFocus = mode;
}

void FloatingWidget::recalculateGeometry() {
}
