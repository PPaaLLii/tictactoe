#include "game.h"
#include <QGraphicsScene>
#include "grid.h"
#include <QDebug>

Game::Game()
{
    int padding = 20;
    int numberOfRows = 3;
    int numberOfCols = 3;
    int sizeOfField = 50;

    m_scene = new QGraphicsScene(this);

    setScene(m_scene);
    m_scene->setSceneRect(0, 0, calculateWindowSize(numberOfCols, sizeOfField, padding), calculateWindowSize(numberOfRows, sizeOfField, padding));

    setFixedSize(calculateWindowSize(numberOfCols, sizeOfField, padding), calculateWindowSize(numberOfRows, sizeOfField, padding));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Grid grid(numberOfRows, numberOfCols, sizeOfField, padding, m_scene);
    grid.setRect(padding, padding, grid.getWidth(), grid.getHeight());
    m_scene->addItem(&grid);
    grid.paint();
}

void Game::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Click!";
}

int Game::calculateWindowSize(int numberOfFields, int sizeOfField, int padding)
{
    return numberOfFields * sizeOfField + numberOfFields + 1 + 2 * padding + 2;
}
