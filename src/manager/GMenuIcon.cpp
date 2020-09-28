//===============================================
#include "GMenuIcon.h"
#include "GManager.h"
//===============================================
GMenuIcon::GMenuIcon(QWidget* parent) : QFrame(parent) {
    setObjectName("GMenuIcon");
    m_mainLayout = new QVBoxLayout;
    m_icon = new QToolButton;
    m_title = new QLabel;
    m_mainLayout->addWidget(m_icon, 1);
    m_mainLayout->addWidget(m_title, 0);
    setLayout(m_mainLayout);
}
//===============================================
GMenuIcon::~GMenuIcon() {
    
}
//===============================================
void GMenuIcon::setIcon(QIcon icon) {
    m_icon->setIcon(icon);
}
//===============================================
void GMenuIcon::setTitle(QString title) {
    m_title->setText(title);
}
//===============================================
