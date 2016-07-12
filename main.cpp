#include "pandaqt5.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //QApplication::setStyle("material");
    QApplication a(argc, argv);
    Pandaqt5 w;
    w.show();

    try {
        a.exec();
    }
    catch(const std::bad_alloc &) {
        return 0;
    }
    return 0;
}
