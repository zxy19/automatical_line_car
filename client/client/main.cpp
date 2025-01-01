#include "widget.h"
#include <QApplication>
#include "db.h"
#include "formviewer.h"
#include "varibles.h"
QString username;
int main(int argc, char *argv[])
{
    db::init();
    QApplication a(argc, argv);

    Widget w;
    w.show();

    return a.exec();
}
