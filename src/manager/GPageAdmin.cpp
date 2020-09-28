//===============================================
#include "GPageAdmin.h"
#include "GManager.h"
//===============================================
GPageAdmin::GPageAdmin(QWidget* parent) : QFrame(parent) {
    setObjectName("GPageAdmin");
    createMenuKey();
    createMenuAddress();
    createMenuBody();
    createLayout();
}
//===============================================
GPageAdmin::~GPageAdmin() {
    
}
//===============================================
void GPageAdmin::createMenuKey() {
    m_menuKey.append("ADMIN");
    m_menuKey.append("IPHONE");
    m_menuKey.append("LCL");
}
//===============================================
void GPageAdmin::createMenuAddress() {
    m_menuAddressLayout = new QHBoxLayout;
    m_menuAddressLayout->setAlignment(Qt::AlignLeft);
    m_menuAddressLayout->setMargin(0);
    
    QString lMenuKey = m_menuKey.at(0);
    QStringList lMenuMap = lMenuKey.split("\\.");
    QString lMenuId = "";
    for(int i = 0; i < lMenuMap.size(); i++) {
        QString lMenuItem = lMenuMap.at(i);
        if(i != 0) lMenuId += ".";
        lMenuId += lMenuItem;
        QPushButton* lMenuButton = new QPushButton;
        lMenuButton->setText(lMenuItem);
        m_menuAddressLayout->addWidget(lMenuButton);
    }
}
//===============================================
void GPageAdmin::createMenuBody() {
    m_menuBodyLayout = new QHBoxLayout;
    m_menuBodyLayout->setAlignment(Qt::AlignLeft);
    m_menuBodyLayout->setMargin(0);

    for(int i = 1; i < m_menuKey.size(); i++) {
        QString lMenuRef = m_menuKey.at(0);
        QString lMenuKey = m_menuKey.at(i);
        QString lMenuId = lMenuRef + "." + lMenuKey;
        QPushButton* lMenuButton = new QPushButton;
        lMenuButton->setText(lMenuKey);
        m_menuBodyLayout->addWidget(lMenuButton);
    }
}
//===============================================
void GPageAdmin::createLayout() {
    m_workspace = new QTextEdit;
    m_workspace->setReadOnly(true);
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addLayout(m_menuAddressLayout, 0);
    m_mainLayout->addLayout(m_menuBodyLayout, 0);
    m_mainLayout->addWidget(m_workspace, 1);
    m_menuBodyLayout->setMargin(0);
    setLayout(m_mainLayout);
}
//===============================================
