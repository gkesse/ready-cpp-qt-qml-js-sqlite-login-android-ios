//===============================================
#include "GTest.h"
#include "GMainWindow.h"
//===============================================
GTest::GTest()
: GObject() {

}
//===============================================
GTest::~GTest() {

}
//===============================================
void GTest::run(int _argc, char** _argv, char** _envs) {
    GString lMethod = "";
    if(_argc > 2) lMethod = _argv[2];

    if(lMethod == "") {
        m_logs.addError("La méthode est obligatoire.");
    }
    else if(lMethod == "test") {
        runTest(_argc, _argv, _envs);
    }
    else if(lMethod == "console") {
        runConsole(_argc, _argv, _envs);
    }
    else if(lMethod == "mainwindow") {
        runMainWindow(_argc, _argv, _envs);
    }
    else {
        m_logs.addError("La méthode est inconnue.");
    }
}
//===============================================
void GTest::runTest(int _argc, char** _argv, char** _envs) {
    printf("%s...\n", __PRETTY_FUNCTION__);
}
//===============================================
void GTest::runConsole(int _argc, char** _argv, char** _envs) {
    printf("%s...\n", __PRETTY_FUNCTION__);
    QApplication lApp(_argc, _argv);
    printf("Bonjour tout le monde.\n");
    lApp.exec();
}
//===============================================
void GTest::runMainWindow(int _argc, char** _argv, char** _envs) {
    printf("%s...\n", __PRETTY_FUNCTION__);
    QApplication lApp(_argc, _argv);
    GMainWindow lWindow;
    lWindow.show();
    lApp.exec();
}
//===============================================
