#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>

class Game : public QGraphicsView
{
public:
    QGraphicsScene *m_scene;

    Game();

    void mousePressEvent(QMouseEvent *event);

private:
    int calculateWindowSize(int numberOfFields, int sizeOfField, int padding);
};

#endif // GAME_H
