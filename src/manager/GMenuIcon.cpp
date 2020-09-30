//===============================================
#include "GMenuIcon.h"
#include "GManager.h"
//===============================================
GMenuIcon::GMenuIcon(QWidget* parent) : QFrame(parent) {
    setObjectName("GMenuIcon");
        
    m_icon = new QToolButton;
    
    m_title = new QLabel;
    m_title->setAlignment(Qt::AlignCenter);
    
    m_iconLayout = new QHBoxLayout;
    m_iconLayout->addWidget(m_icon);
    m_iconLayout->setAlignment(Qt::AlignCenter);
    m_iconLayout->setMargin(0);
    m_iconLayout->setSpacing(0);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addLayout(m_iconLayout, 1);
    m_mainLayout->addWidget(m_title, 0);
    m_mainLayout->setMargin(0);
    m_mainLayout->setSpacing(0);
    
    setLayout(m_mainLayout);
    setCursor(Qt::PointingHandCursor);
}
//===============================================
GMenuIcon::~GMenuIcon() {
    
}
//===============================================
void GMenuIcon::setTitle(QString title) {
    m_title->setText(title);
}
//===============================================
void GMenuIcon::setIcon(QIcon icon) {
    m_icon->setIcon(icon);
}
//===============================================
void GMenuIcon::setIconSize(int width, int height) {
    m_icon->setIconSize(QSize(width, height));
}
//===============================================
