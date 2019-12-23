//
// Created by ky3he4ik on 23/12/2019.
//

#ifndef GAYA_CARD_H
#define GAYA_CARD_H

#include <QWidget>

#include <QGridLayout>
#include <QPushButton>
#include <QVector>
#include "MyButton.h"

class Card : public QWidget {
Q_OBJECT
private:
    QGridLayout *layout;
    QVector<QVector<MyButton *> > buttons;
    QVector<QVector<int>> cardValues;
    int current_bar;

    bool is_bot = false;

public:

    explicit Card(const QVector<QVector<int>> &_cardValues, QWidget * = Q_NULLPTR);

    void newBarrel(int barelVal);

    void setBot();

private slots:

    void buttonPressed(int x, int y);

signals:
    void finished();
};


#endif //GAYA_CARD_H
