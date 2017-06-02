#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

int calculateWindowSize(int numberOfFields, int sizeOfField, int padding)
{
    return numberOfFields * sizeOfField + numberOfFields + 1 + 2 * padding + 2;
}

void paintGrid(int numberOfRows, int numberOfCols, int sizeOfField, int padding, QGraphicsScene* scene)
{
    // horizontal lines
    for (int hLineIdx = 0; hLineIdx < numberOfRows+1; ++hLineIdx) {
        int xStart = padding;
        int yStart = padding + hLineIdx * sizeOfField + hLineIdx;
        int xEnd = padding + sizeOfField * numberOfCols + numberOfCols;
        int yEnd = yStart;

        scene->addLine(xStart, yStart, xEnd, yEnd, QPen(Qt::black));
    }

    // vertical lines
    for (int vLineIdx = 0; vLineIdx < numberOfCols+1; ++vLineIdx) {
        int xStart = padding + vLineIdx * sizeOfField + vLineIdx;
        int yStart = padding;
        int xEnd = xStart;
        int yEnd = padding + sizeOfField * numberOfRows + numberOfRows;

        scene->addLine(xStart, yStart, xEnd, yEnd, QPen(Qt::black));
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    int padding = 20;
    int numberOfRows = 3;
    int numberOfCols = 3;
    int sizeOfField = 50;

    paintGrid(numberOfRows, numberOfCols, sizeOfField, padding, scene);

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(calculateWindowSize(numberOfCols, sizeOfField, padding), calculateWindowSize(numberOfRows, sizeOfField, padding));
    scene->setSceneRect(0, 0, calculateWindowSize(numberOfCols, sizeOfField, padding), calculateWindowSize(numberOfRows, sizeOfField, padding));

    return a.exec();
}
