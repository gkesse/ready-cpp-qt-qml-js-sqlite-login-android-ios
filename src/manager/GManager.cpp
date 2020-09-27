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
    m_mgr->qt->style_file = ":/qss/styles.qss";
    m_mgr->qt->width = 640;
    m_mgr->qt->height = 480;
    // qt_awesoome
    m_QtAwesome = new QtAwesome(qApp);
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
void GManager::styleLoad() {
    QFile lFile(m_mgr->qt->style_file);
    lFile.open(QFile::ReadOnly);
    QString lStyleSheet = QLatin1String(lFile.readAll());
    qApp->setStyleSheet(lStyleSheet);
}
//===============================================
QIcon GManager::pictoLoad(int picto, QColor color) {
    m_QtAwesome->initFontAwesome();
     m_QtAwesome->setDefaultOption("color", color);
     m_QtAwesome->setDefaultOption("color-active", color);
    return  m_QtAwesome->icon(picto);
}
//===============================================
