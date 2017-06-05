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

    void init(int numberOfRows, int numberOfCols, int sizeOfField, int padding, QGraphicsScene* scene);

    int getWidth();

    int getHeight();

    void paint();

    bool isInGrid(const QPoint &point);

    int getClickedRowIdx(const QPoint &point);

    int getClickedColIdx(const QPoint &point);
};

#endif // GRID_H
