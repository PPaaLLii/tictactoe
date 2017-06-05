#include "game.h"
#include <QGraphicsScene>
#include "grid.h"
#include <QDebug>
#include <vector>

Game::Game()
{
    int padding = 20;
    int innerPadding = 13;
    int numberOfRows = 3;
    int numberOfCols = 3;
    int sizeOfField = 50;

    m_scene = new QGraphicsScene(this);

    setScene(m_scene);
    m_scene->setSceneRect(0, 0, calculateWindowSize(numberOfCols, sizeOfField, padding), calculateWindowSize(numberOfRows, sizeOfField, padding));

    setFixedSize(calculateWindowSize(numberOfCols, sizeOfField, padding), calculateWindowSize(numberOfRows, sizeOfField, padding));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_grid.init(numberOfRows, numberOfCols, sizeOfField, padding, innerPadding, m_scene);
    m_grid.setRect(padding, padding, m_grid.getWidth(), m_grid.getHeight());
    m_scene->addItem(&m_grid);
    m_grid.paint();

    // board setup
    for (int rows = 0; rows < numberOfRows; ++rows) {
        std::vector<int> r;
        for (int cols = 0; cols < numberOfCols; ++cols) {
            r.push_back(-1);
        }
        m_board.push_back(r);
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    int row = m_grid.getClickedRowIdx(event->pos());
    int col = m_grid.getClickedColIdx(event->pos());

    if (row == -1 || col == -1)
        return;

    if (!isValidMove(row, col))
        return;

    m_grid.paintMove(row, col, m_nextMove);
    m_board[row][col] = m_nextMove;

    m_nextMove = !m_nextMove;
}

int Game::calculateWindowSize(int numberOfFields, int sizeOfField, int padding)
{
    return numberOfFields * sizeOfField + numberOfFields + 1 + 2 * padding + 2;
}

bool Game::isValidMove(int row, int col)
{
    return m_board[row][col] == -1;
}
