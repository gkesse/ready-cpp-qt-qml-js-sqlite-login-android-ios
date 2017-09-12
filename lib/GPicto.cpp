//===============================================
#include "GPicto.h"
#include <QApplication>
//===============================================
GPicto* GPicto::m_instance = 0;
//===============================================
GPicto::GPicto() {
    createObjects();
}
//===============================================
GPicto::~GPicto() {

}
//===============================================
GPicto* GPicto::Instance() {
    if(m_instance == 0) {
        m_instance = new GPicto;
    }

    return m_instance;
}
//===============================================
void GPicto::createObjects() {
    m_picto = new QtAwesome(qApp);
    m_picto->initFontAwesome();
    m_color = QColor("white");
}
//===============================================
void GPicto::setColor(const QColor& color) {
    m_color = color;
}
//===============================================
QIcon GPicto::getPicto(const int& picto) const {
    m_picto->setDefaultOption("color", m_color);
    m_picto->setDefaultOption("color-active", m_color);
    return m_picto->icon(picto);
}
//===============================================
QIcon GPicto::getPicto(const QString& picto) const {
    m_picto->setDefaultOption("color", m_color);
    m_picto->setDefaultOption("color-active", m_color);
    return m_picto->icon(picto);
}
//===============================================
