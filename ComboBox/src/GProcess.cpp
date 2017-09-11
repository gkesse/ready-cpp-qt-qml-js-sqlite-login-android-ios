//===============================================
#include "GProcess.h"
#include "GMessageView.h"
#include "GComboBoxView.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess(QObject *parent) :
    QObject(parent) {
    GComboBoxView::Instance()->show();
    GMessageView::Instance()->show();
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
