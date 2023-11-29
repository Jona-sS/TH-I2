#include "MainWindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    Q_INIT_RESOURCE(resource);

    MainWindow w;
    w.show();

    return a.exec();
}
