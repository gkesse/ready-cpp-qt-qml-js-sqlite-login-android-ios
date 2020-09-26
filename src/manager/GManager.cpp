//===============================================
#include "GManager.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
GManager::GManager() {
    // manager
    m_mgr = new sGManager;
    // qt
    m_mgr->qt = new sGQt;
    m_mgr->qt->app_name = "ReadyApp";
    m_mgr->qt->title = m_mgr->qt->app_name;
    m_mgr->qt->width = 640;
    m_mgr->qt->height = 480;
}
//===============================================
GManager::~GManager() {
    
}
//===============================================
GManager* GManager::Instance() {
    if(m_instance == 0) {
        m_instance = new GManager;
    }
    return m_instance;
}
//===============================================
sGManager* GManager::dataGet() {
    return m_mgr;
}
//===============================================
