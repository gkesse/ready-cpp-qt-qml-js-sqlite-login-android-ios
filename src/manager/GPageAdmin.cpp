//===============================================
#include "GPageAdmin.h"
#include "GMenuIcon.h"
#include "GManager.h"
//===============================================
GPageAdmin::GPageAdmin(QWidget* parent) : QFrame(parent) {
    setObjectName("GPageAdmin");
    G_PAGE_ID = "HOME";
    
    createMenuKey();
    createMenuName();
    createMenuPicto();
    createMenuPad();
    createLayout();
}
//===============================================
GPageAdmin::~GPageAdmin() {
    
}
//===============================================
void GPageAdmin::createMenuKey() {
    m_menuKey.append(G_PAGE_ID);
    m_menuKey.append("IPHONE");
    m_menuKey.append("LCL");
    m_menuKey.append("LCL");
    m_menuKey.append("LCL");
    m_menuKey.append("LCL");
    m_menuKey.append("LCL");
    m_menuKey.append("LCL");
    m_menuKey.append("LCL");
    m_menuKey.append("LCL");
    m_menuKey.append("LCL");
}
//===============================================
void GPageAdmin::createMenuName() {

}
//===============================================
void GPageAdmin::createMenuPicto() {

}
//===============================================
void GPageAdmin::createMenuPad() {
    sGMenuIcon* lMenuIcon = GManager::Instance()->dataGet()->menu_icon;
    
    m_menuPadLayout = new QGridLayout;
    m_menuPadLayout->setMargin(0);
    m_menuPadLayout->setSpacing(0);

    int lPadRow = 0;
    int lPadCol = 0;

    QString lMenuRef = m_menuKey.at(0);
    for(int i = 0; i < m_menuKey.size(); i++) {
        QString lMenuKey = m_menuKey.at(i);
        QString lMenuName = m_menuName.value(lMenuKey, lMenuKey);
        int lMenuPicto = m_menuPicto.value(lMenuKey, lMenuIcon->default_icon);
        QString lMenuId = lMenuRef + "." + lMenuKey;
        GMenuIcon* lMenuButton = new GMenuIcon;
        lMenuButton->setIcon(GManager::Instance()->pictoLoad(lMenuPicto, lMenuIcon->icon_color));
        lMenuButton->setTitle(lMenuName);
        lMenuButton->setIconSize(lMenuIcon->icon_size, lMenuIcon->icon_size);
        m_menuPadLayout->addWidget(lMenuButton, lPadRow, lPadCol, Qt::AlignCenter);
        lPadCol++;
        if(lPadCol == lMenuIcon->col_max) {
            lPadRow++;
            lPadCol = 0;
        }
    }
}
//===============================================
void GPageAdmin::createLayout() {
    m_workspace = new QTextEdit;
    m_workspace->setReadOnly(true);
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addLayout(m_menuPadLayout, 0);
    m_mainLayout->addWidget(m_workspace, 1);
    m_mainLayout->setMargin(0);
    m_mainLayout->setSpacing(0);
    setLayout(m_mainLayout);
}
//===============================================
