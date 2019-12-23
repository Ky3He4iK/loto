//
// Created by ky3he4ik on 23/12/2019.
//

#include "Card.h"
#include <iostream>

Card::Card(const QVector<QVector<int>> &_cardValues, QWidget *) : cardValues(_cardValues) {
    layout = new QGridLayout();

    buttons.resize(3);
    for (int i = 0; i < 3; i++) {
        buttons[i].resize(9);
        for (int j = 0; j < 9; j++) {
            buttons[i][j] = new MyButton(i, j, cardValues[i][j]);
            layout->addWidget(buttons[i][j], i, j);
            connect(buttons[i][j], &MyButton::pressedSignal, this, &Card::buttonPressed);
            std::cerr << i << ' ' << j << ' ' << cardValues[i][j] << '\n';
        }
    }
    setLayout(layout);
}

void Card::newBarrel(int barelVal) {
    current_bar = barelVal;
    if (is_bot)
        for (int i = 0; i < 3; i++)
            buttonPressed(barelVal / 10, i);
}

void Card::buttonPressed(int x, int y) {
    if (buttons[x][y]->getVal() == current_bar) {
        buttons[x][y]->setOk();
        int okc = 0;
        for (int i = 0; i < 9; i++) {
            if (buttons[i][y]->getOk()) {
                okc++;
                break;
            }
        }
        if (okc == 5)
                emit finished();
    }
}

void Card::setBot() {
    is_bot = true;
}
