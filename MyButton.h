//
// Created by ky3he4ik on 23/12/2019.
//

#ifndef GAYA_MYBUTTON_H
#define GAYA_MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton {
Q_OBJECT
    int x, y, val;
    bool ok = false;

public:
    MyButton(int _x, int _y, int _val = 0, QWidget * = Q_NULLPTR);

    int getVal();

    bool getOk();

    void setOk();

    void paintEvent(QPaintEvent *event) override;

private slots:

    void onPressed();

signals:

    void pressedSignal(int x, int y);
};


#endif //GAYA_MYBUTTON_H
