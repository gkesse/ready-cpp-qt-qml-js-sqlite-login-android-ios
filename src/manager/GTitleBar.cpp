//===============================================
#include "GTitleBar.h"
#include "GManager.h"
//===============================================
GTitleBar::GTitleBar(QWidget* parent) : QFrame(parent) {
    setObjectName("GTitleBar");
    sGQt* lQt = GManager::Instance()->dataGet()->qt;
    int lSize = 16;
    QColor lColor = "teal";
    
    m_icon = new QToolButton;  
    m_icon->setIcon(GManager::Instance()->pictoLoad(fa::cogs, lColor));
    m_icon->setIconSize(QSize(lSize, lSize));
    m_icon->setCursor(Qt::PointingHandCursor);
    
    m_title = new QLabel;    
    m_title->setText(lQt->title);
    m_title->setAlignment(Qt::AlignLeft);
    m_title->setMargin(0);
    
    m_minimize = new QToolButton;    
    m_minimize->setIcon(GManager::Instance()->pictoLoad(fa::windowminimize, lColor));
    m_minimize->setIconSize(QSize(lSize, lSize));
    m_minimize->setCursor(Qt::PointingHandCursor);

    m_maximize = new QToolButton;    
    m_maximize->setIcon(GManager::Instance()->pictoLoad(fa::windowmaximize, lColor));
    m_maximize->setIconSize(QSize(lSize, lSize));
    m_maximize->setCursor(Qt::PointingHandCursor);

    m_close = new QToolButton;    
    m_close->setIcon(GManager::Instance()->pictoLoad(fa::times, lColor));
    m_close->setIconSize(QSize(lSize, lSize));
    m_close->setCursor(Qt::PointingHandCursor);
    
    QHBoxLayout* lLayout = new QHBoxLayout;    
    lLayout->addWidget(m_icon, 0);
    lLayout->addWidget(m_title, 1);
    lLayout->addWidget(m_minimize, 0);
    lLayout->addWidget(m_maximize, 0);
    lLayout->addWidget(m_close, 0);
    lLayout->setAlignment(Qt::AlignLeft);
    lLayout->setMargin(5);
    lLayout->setSpacing(5);
    
    setLayout(lLayout);
}
//===============================================
GTitleBar::~GTitleBar() {
    
}
//===============================================
