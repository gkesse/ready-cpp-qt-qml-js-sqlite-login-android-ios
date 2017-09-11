//===============================================
#include "GStyle.h"
#include "GProcess.h"
#include <QApplication>
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GStyle::Instance()->load();
    GProcess::Instance()->run();
    return app.exec();
}
//===============================================
