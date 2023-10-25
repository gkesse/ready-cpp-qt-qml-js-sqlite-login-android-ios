//===============================================
#include "GProcess.h"
#include "GTest.h"
//===============================================
GProcess::GProcess()
: GObject() {

}
//===============================================
GProcess::~GProcess() {

}
//===============================================
void GProcess::init() {
    // libxml2
    xmlInitParser();
}
//===============================================
void GProcess::clean() {
    // libxml2
    xmlCleanupParser();
    xmlMemoryDump();
}
//===============================================
void GProcess::run(int _argc, char** _argv, char** _envs) {
    GString lModule = "";
    if(_argc > 1) lModule = _argv[1];

    if(lModule == "") {
        m_logs.addError("Le module est obligatoire.");
    }
    else if(lModule == "test") {
        runTest(_argc, _argv, _envs);
    }
    else {
        m_logs.addError("Le module est inconnu.");
    }
}
//===============================================
void GProcess::runTest(int _argc, char** _argv, char** _envs) {
    GTest lObj;
    lObj.run(_argc, _argv, _envs);
    m_logs.addLogs(lObj.getLogs());
}
//===============================================
