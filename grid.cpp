#include "grid.h"
#include <QDebug>

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
