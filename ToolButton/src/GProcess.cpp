//===============================================
#include "GProcess.h"
#include "GMessageView.h"
#include "GToolButtonView.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess(QObject *parent) :
    QObject(parent) {
    GMessageView::Instance()->show();
    GToolButtonView::Instance()->show();
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
