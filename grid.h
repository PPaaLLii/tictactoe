#ifndef GRID_H
#define GRID_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMouseEvent>

class Grid : public QGraphicsRectItem
{
private:
    int m_numberOfRows;
    int m_numberOfCols;
    int m_sizeOfField;
    int m_padding;
    QGraphicsScene* m_scene;

public:
    Grid(int numberOfRows, int numberOfCols, int sizeOfField, int padding, QGraphicsScene* scene) :
        m_numberOfRows{ numberOfRows },
        m_numberOfCols{ numberOfCols },
        m_sizeOfField{ sizeOfField },
        m_padding{ padding },
        m_scene{ scene }
    {
    }

    int getWidth();

    int getHeight();

    void paint();
};

#endif // GRID_H
