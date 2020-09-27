//===============================================
#include "GWindow.h"
#include "GManager.h"
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GManager::Instance()->styleLoad();
    GWindow* lWindow = new GWindow;
    lWindow->show();
    return app.exec();
}
//===============================================
