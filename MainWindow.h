//
// Created by ky3he4ik on 23/12/2019.
//

#ifndef GAYA_MAINWINDOW_H
#define GAYA_MAINWINDOW_H

#include <QWidget>
#include "Card.h"
#include <QHBoxLayout>
#include <QTimer>
#include <QLabel>

class MainWindow : public QWidget {
Q_OBJECT
private:
    QHBoxLayout *layout;
    QVector<Card *> cards;
    QLabel *label;
    QTimer *timer;
    static QVector<QVector<int> > load_card();
public:
    explicit MainWindow(QWidget * = Q_NULLPTR);

private slots:

    void timerSlot();

    void finishSlot();
};


#endif //GAYA_MAINWINDOW_H
