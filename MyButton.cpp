//
// Created by ky3he4ik on 23/12/2019.
//

#include <QtWidgets/QStyleOption>
#include <QtGui/QPainter>
#include "MyButton.h"
#include <random>
#include <fstream>
#include <string>

MyButton::MyButton(int _x, int _y, int _val, QWidget *) : x(_x), y(_y), val(_val) {
    if (val == 0)
        setEnabled(false);
    else
        setText(QString::number(val));
    connect(this, &MyButton::pressed, this, &MyButton::onPressed);
}

int MyButton::getVal() {
    return val;
}

void MyButton::onPressed() {
    emit pressedSignal(x, y);
}

bool MyButton::getOk() {
    return ok;
}

void MyButton::setOk() {
    ok = true;
    setEnabled(false);
}

void MyButton::paintEvent(QPaintEvent *event) {
    if (ok) {

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
    QPushButton::paintEvent(event);
}
