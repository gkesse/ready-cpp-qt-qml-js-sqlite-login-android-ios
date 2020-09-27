//===============================================
#include "GTitleBar.h"
#include "GManager.h"
//===============================================
GTitleBar::GTitleBar(QWidget* parent) : QFrame(parent) {
    setObjectName("GTitleBar");
    sGQt* lQt = GManager::Instance()->dataGet()->qt;
    sGTitleBar* lTitleBar = GManager::Instance()->dataGet()->title_bar;
    sGFont* lFont = GManager::Instance()->dataGet()->font;
    
    m_icon = new QToolButton;  
    m_icon->setIcon(QIcon(lTitleBar->icon_file));
    m_icon->setIconSize(QSize(lTitleBar->icon_size, lTitleBar->icon_size));
    m_icon->setCursor(Qt::PointingHandCursor);
    m_icon->setObjectName("icon");
    m_widgetId[m_icon] = "icon";
    
    m_title = new QLabel;    
    m_title->setText(lQt->title);
    m_title->setAlignment(Qt::AlignLeft);
    m_title->setMargin(0);
    int id = QFontDatabase::addApplicationFont(lFont->lobster);
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont monospace(family, 26);
    m_title->setFont(monospace);
    
    m_fullscreen = new QToolButton;    
    m_fullscreen->setIcon(GManager::Instance()->pictoLoad(fa::arrowsalt, lTitleBar->color));
    m_fullscreen->setIconSize(QSize(lTitleBar->icon_size, lTitleBar->icon_size));
    m_fullscreen->setCursor(Qt::PointingHandCursor);
    m_widgetId[m_fullscreen] = "fullscreen";

    m_minimize = new QToolButton;    
    m_minimize->setIcon(GManager::Instance()->pictoLoad(fa::windowminimize, lTitleBar->color));
    m_minimize->setIconSize(QSize(lTitleBar->icon_size, lTitleBar->icon_size));
    m_minimize->setCursor(Qt::PointingHandCursor);
    m_widgetId[m_minimize] = "minimize";

    m_maximize = new QToolButton;    
    m_maximize->setIcon(GManager::Instance()->pictoLoad(fa::windowmaximize, lTitleBar->color));
    m_maximize->setIconSize(QSize(lTitleBar->icon_size, lTitleBar->icon_size));
    m_maximize->setCursor(Qt::PointingHandCursor);
    m_widgetId[m_maximize] = "maximize";

    m_close = new QToolButton;    
    m_close->setIcon(GManager::Instance()->pictoLoad(fa::times, lTitleBar->color));                                                             
    m_close->setIconSize(QSize(lTitleBar->icon_size, lTitleBar->icon_size));
    m_close->setCursor(Qt::PointingHandCursor);
    m_widgetId[m_close] = "close";
    
    QHBoxLayout* lLayout = new QHBoxLayout;    
    lLayout->addWidget(m_icon, 0);
    lLayout->addWidget(m_title, 1);
    lLayout->addWidget(m_fullscreen, 0);
    lLayout->addWidget(m_minimize, 0);
    lLayout->addWidget(m_maximize, 0);
    lLayout->addWidget(m_close, 0);
    lLayout->setAlignment(Qt::AlignLeft);
    lLayout->setMargin(5);
    lLayout->setSpacing(5);
    
    setLayout(lLayout);

    connect(m_icon, SIGNAL(clicked()), this, SLOT(slotTitleClick()));
    connect(m_fullscreen, SIGNAL(clicked()), this, SLOT(slotTitleClick()));
    connect(m_minimize, SIGNAL(clicked()), this, SLOT(slotTitleClick()));
    connect(m_maximize, SIGNAL(clicked()), this, SLOT(slotTitleClick()));
    connect(m_close, SIGNAL(clicked()), this, SLOT(slotTitleClick()));
}
//===============================================
GTitleBar::~GTitleBar() {
    
}
//===============================================
void GTitleBar::slotTitleClick() {
    sGTitleBar* lTitleBar = GManager::Instance()->dataGet()->title_bar;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lTitleBar->click_id = m_widgetId[lWidget];
    emit emitTitleClick();
}
//===============================================
void GTitleBar::slotTitleUpdate() {
    sGTitleBar* lTitleBar = GManager::Instance()->dataGet()->title_bar;
    m_maximize->setIcon(GManager::Instance()->pictoLoad(lTitleBar->maximize_icon, lTitleBar->color));
}
//===============================================
