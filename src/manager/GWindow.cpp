//===============================================
#include "GWindow.h"
#include "GTitleBar.h"
#include "GManager.h"
//===============================================
GWindow::GWindow(QWidget* parent) : QFrame(parent) {
    sGQt* lQt = GManager::Instance()->dataGet()->qt;
    sGTitleBar* lTitleBar = GManager::Instance()->dataGet()->title_bar;

    m_titleBar = new GTitleBar;
    
    lQt->page_map = new QStackedWidget;
    
    QVBoxLayout* lLayout = new QVBoxLayout;    
    lLayout->addWidget(m_titleBar, 0);
    lLayout->addWidget(lQt->page_map, 1);
    lLayout->setMargin(0);
    
    setLayout(lLayout);
    
    setWindowTitle(lQt->title);
    setWindowIcon(QIcon(lTitleBar->icon_file));
    resize(lQt->width, lQt->height);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    connect(m_titleBar, SIGNAL(emitTitleClick()), this, SLOT(slotTitleClcik()));
    connect(this, SIGNAL(emitTitleUpdate()), m_titleBar, SLOT(slotTitleUpdate()));
}
//===============================================
GWindow::~GWindow() {
    
}
//===============================================
void GWindow::slotTitleClcik() {
    sGTitleBar* lTitleBar = GManager::Instance()->dataGet()->title_bar;
    if(lTitleBar->click_id == "icon") {
        QDesktopServices::openUrl(QUrl(lTitleBar->url));
    }
    else if(lTitleBar->click_id == "fullscreen") {
        if(windowState() != Qt::WindowFullScreen) {
            showFullScreen();
        }
        else {
            showNormal();
        }
    }
    else if(lTitleBar->click_id == "minimize") {
        showMinimized();
    }
    else if(lTitleBar->click_id == "maximize") {
        if(windowState() != Qt::WindowMaximized) {
            showMaximized();
            lTitleBar->maximize_icon = fa::windowrestore;
            emit emitTitleUpdate();
        }
        else {
            showNormal();
            lTitleBar->maximize_icon = fa::windowmaximize;
            emit emitTitleUpdate();
        }
    }
    else if(lTitleBar->click_id == "close") {
        close();
    }
}
//===============================================
