//
// Created by ky3he4ik on 23/12/2019.
//

#include "MainWindow.h"
#include <fstream>

MainWindow::MainWindow(QWidget *) {
    layout = new QHBoxLayout();
    cards.resize(2);
    cards[0] = new Card(load_card());
    layout->addWidget(cards[0]);
    connect(cards[0], &Card::finished, this, &MainWindow::finishSlot);

    label = new QLabel();
    layout->addWidget(label);

    cards[1] = new Card(load_card());
    layout->addWidget(cards[1]);
    cards[1]->setBot();
    connect(cards[1], &Card::finished, this, &MainWindow::finishSlot);

    setLayout(layout);
    label->setText(QString::number(123));
    timerSlot();

    timer = new QTimer();
    timer->start(100);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerSlot);
}

void MainWindow::finishSlot() {
    hide();
}

void MainWindow::timerSlot() {
    int box = rand() % 91;
    cards[0]->newBarrel(box);
    cards[1]->newBarrel(box);
    label->setText(QString::number(box));
}


QVector<QVector<int> > MainWindow::load_card() {
    static int countcards = 6;
    static bool cur_num_cards[] = {false, false, false, false, false, false};
    static int cards[6][3][9] = {

            {
                    {0, 16, 21, 31, 42, 0,  60, 0,  0},
                                                         {1, 18, 0,  33, 0,  53, 62, 0,  0},
                                                                                              {2, 0,  0,  38, 0,  55, 69, 74, 0}
            },
            {
                    {0, 12, 21, 0,  41, 51, 61, 0,  0},
                                                         {0, 13, 22, 0,  42, 0,  67, 0,  86},
                                                                                              {0, 14, 25, 0,  43, 0,  69, 0,  90}
            },
            {
                    {7, 0,  0,  34, 0,  0,  69, 72, 85},
                                                         {0, 0,  24, 38, 0,  51, 0,  73, 89},
                                                                                              {8, 18, 0,  39, 40, 0,  0,  75, 0}
            },
            {
                    {0, 10, 22, 0,  0,  0,  63, 77, 80},

                                                         {2, 0,  25, 0,  0,  53, 65, 0,  84},
                                                                                              {0, 17, 28, 31, 0,  57, 69, 0,  0}
            },
            {       {1, 13, 21, 0,  0,  0,  62, 0,  84}, {4, 16, 0,  0,  0,  52, 0,  70, 86}, {0, 17, 23, 0,  0,  57, 0,  73, 89}},
            {       {7, 10, 0,  30, 40, 52, 0,  0,  0},  {0, 12, 0,  33, 46, 0,  63, 75, 0},  {8, 16, 0,  35, 47, 0,  0,  77, 0}}
    };

    srand(time(0));
    int x = rand() % countcards;
    while (cur_num_cards[x]) {
        x = rand() % countcards;
    }
    cur_num_cards[x] = true;
    x++;
    std::string file_name = "card";
    file_name += (x / 10 + 48);
    file_name += (x % 10 + 48);
    file_name += ".txt";
    std::ifstream fin("card04.txt");
    QVector<QVector<int> > card;
    card.resize(3);
    for (int i = 0; i < 3; i++) {
        card[i].resize(9);
        for (int j = 0; j < 9; j++) {
//            fin >> card[i][j];
            card[i][j] = cards[x - 1][i][j];
        }
    }
    fin.close();
    return card;
}