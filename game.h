#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "grid.h"

class Game : public QGraphicsView
{
public:
    Game();

private:
    Grid m_grid;

    QGraphicsScene *m_scene;

    void mousePressEvent(QMouseEvent *event);

    int calculateWindowSize(int numberOfFields, int sizeOfField, int padding);

    bool isValidMove(int row, int col);

    // cross = 1 && circle = 0;
    bool m_nextMove = 1;

    std::vector<std::vector<int>> m_board;
};

#endif // GAME_H
