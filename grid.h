#ifndef GRID_H
#define GRID_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMouseEvent>

class Grid : public QGraphicsRectItem
{
public:
    void init(int numberOfRows, int numberOfCols, int sizeOfField, int padding, int innerPadding, QGraphicsScene* scene);

    int getWidth();

    int getHeight();

    void paint();

    int getClickedRowIdx(const QPoint &point);

    int getClickedColIdx(const QPoint &point);

    void paintMove(int row, int col, bool move);

private:
    int m_numberOfRows;
    int m_numberOfCols;
    int m_sizeOfField;
    int m_padding;
    int m_innerPadding;
    QGraphicsScene* m_scene;

    bool isInGrid(const QPoint &point);

    void paintCircle(int row, int col);

    void paintCross(int row, int col);

    QRect getInnerRect(int row, int col);
};

#endif // GRID_H
