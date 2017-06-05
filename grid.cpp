#include "grid.h"
#include <QDebug>
#include <QPoint>

void Grid::init(int numberOfRows, int numberOfCols, int sizeOfField, int padding,int innerPadding, QGraphicsScene *scene)
{
    m_numberOfRows = numberOfRows;
    m_numberOfCols = numberOfCols;
    m_sizeOfField = sizeOfField;
    m_padding = padding;
    m_innerPadding = innerPadding;
    m_scene = scene;
}

int Grid::getWidth()
{
    return m_numberOfCols * m_sizeOfField + m_numberOfCols;
}

int Grid::getHeight()
{
    return m_numberOfRows * m_sizeOfField + m_numberOfRows;
}

void Grid::paint()
{
    // horizontal lines
    for (int hLineIdx = 0; hLineIdx < m_numberOfRows+1; ++hLineIdx) {
        int xStart = m_padding;
        int yStart = m_padding + hLineIdx * m_sizeOfField + hLineIdx;
        int xEnd = m_padding + m_sizeOfField * m_numberOfCols + m_numberOfCols;
        int yEnd = yStart;

        m_scene->addLine(xStart, yStart, xEnd, yEnd, QPen(Qt::black));
    }

    // vertical lines
    for (int vLineIdx = 0; vLineIdx < m_numberOfCols+1; ++vLineIdx) {
        int xStart = m_padding + vLineIdx * m_sizeOfField + vLineIdx;
        int yStart = m_padding;
        int xEnd = xStart;
        int yEnd = m_padding + m_sizeOfField * m_numberOfRows + m_numberOfRows;

        m_scene->addLine(xStart, yStart, xEnd, yEnd, QPen(Qt::black));
    }
}

int Grid::getClickedRowIdx(const QPoint &point)
{
    if (!isInGrid(point))
        return -1;

    if (((point.y() - m_padding - 1) % (m_sizeOfField + 1) == 0) || ((point.y() - m_padding - 2) % (m_sizeOfField + 1) == 0))
    {
        qDebug() << "horizontal line";
        return -1;
    }

    // integer division
    return (point.y() - m_padding - 2) / (m_sizeOfField + 1);
}

int Grid::getClickedColIdx(const QPoint &point)
{
    if (!isInGrid(point))
        return -1;

    if ((point.x() - m_padding - 1) % (m_sizeOfField + 1) == 0)
    {
        qDebug() << "vertical line";
        return -1;
    }

    // integer division
    return (point.x() - m_padding - 2) / (m_sizeOfField + 1);
}

void Grid::paintMove(int row, int col, bool move)
{
    if (move == 0)
        paintCircle(row, col);
    if (move == 1)
        paintCross(row, col);
}

bool Grid::isInGrid(const QPoint &point)
{
    int x = point.x();
    int y = point.y();

    return (x > (m_padding + 1)) && (x < (m_padding + m_numberOfCols * m_sizeOfField + m_numberOfCols))
            && (y > (m_padding + 1)) && (y < (m_padding + m_numberOfRows * m_sizeOfField + m_numberOfRows));
}

void Grid::paintCircle(int row, int col)
{
    QRect rect = getInnerRect(row, col);
    m_scene->addEllipse(rect.left(), rect.top(),rect.width(), rect.height(), QPen(Qt::red), Qt::NoBrush);
}

void Grid::paintCross(int row, int col)
{
    QRect rect = getInnerRect(row, col);
    m_scene->addLine(rect.left(), rect.top(), rect.right(), rect.bottom());
    m_scene->addLine(rect.left(), rect.bottom(), rect.right(), rect.top());
}

QRect Grid::getInnerRect(int row, int col)
{
    int x = m_padding + col * m_sizeOfField + col + m_innerPadding;
    int y = m_padding + row * m_sizeOfField + row + m_innerPadding;
    int size = m_sizeOfField - 2 * m_innerPadding;
    return QRect(x, y, size, size);
}
