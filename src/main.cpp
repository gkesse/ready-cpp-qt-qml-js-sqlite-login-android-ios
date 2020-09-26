//===============================================
#include "GWindow.h"
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GWindow* lWindow = new GWindow;
    lWindow->show();
    return app.exec();
}
//===============================================
