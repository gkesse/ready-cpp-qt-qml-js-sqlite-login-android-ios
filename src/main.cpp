//===============================================
#include "GInclude.h"
//===============================================
int main(int _argc, char** _argv) {
    QGuiApplication lApp(_argc, _argv);

    QQmlApplicationEngine lEngine;
    const QUrl lUrl("qrc:/qml/main.qml");

    QObject::connect(&lEngine, &QQmlApplicationEngine::objectCreationFailed,
        &lApp, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    lEngine.setOfflineStoragePath(".");
    lEngine.load(lUrl);

    return lApp.exec();
}
//===============================================
