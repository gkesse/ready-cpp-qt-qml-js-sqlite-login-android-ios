//===============================================
#include "GStyle.h"
#include "GMessageView.h"
#include "GOpenGL.h"
#include "GProcess.h"
#include <QApplication>
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GStyle::Instance()->load();
    GOpenGL::Instance()->show();
    GMessageView::Instance()->show();
    GProcess::Instance()->run();
    return app.exec();
}
//===============================================
