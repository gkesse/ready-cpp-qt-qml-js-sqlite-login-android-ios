//===============================================
#include "GProcess.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess(QObject *parent) :
    QObject(parent) {

}
//===============================================
GProcess::~GProcess() {

}
//===============================================
GProcess* GProcess::Instance() {
    if(m_instance == 0) {
        m_instance = new GProcess;
    }
    return m_instance;
}
//===============================================
void GProcess::run() {

}
//===============================================
