#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "grid.h"

class Game : public QGraphicsView
{
public:
    QGraphicsScene *m_scene;

    Grid m_grid;

    Game();

    void mousePressEvent(QMouseEvent *event);

private:
    int calculateWindowSize(int numberOfFields, int sizeOfField, int padding);
};

#endif // GAME_H
