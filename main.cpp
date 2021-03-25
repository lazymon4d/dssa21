#include "design_strength.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    design_strength w;
    w.show();
    //load_data();
    return a.exec();
}
