//===============================================
#include "GWindow.h"
#include "GTitleBar.h"
#include "GPageAdmin.h"
#include "GManager.h"
//===============================================
GWindow::GWindow(QWidget* parent) : QFrame(parent) {
    sGQt* lQt = GManager::Instance()->dataGet()->qt;
    sGTitleBar* lTitleBar = GManager::Instance()->dataGet()->title_bar;

    m_titleBar = new GTitleBar;
    
    createPage();
    
    m_mainLayout = new QVBoxLayout;    
    m_mainLayout->addWidget(m_titleBar, 0);
    m_mainLayout->addWidget(lQt->page_map, 1);
    m_mainLayout->setMargin(0);
    m_mainLayout->setSpacing(0);
    
    setLayout(m_mainLayout);
    
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
void GWindow::createPage() {
    sGQt* lQt = GManager::Instance()->dataGet()->qt;
    lQt->page_map = new QStackedWidget;
    addPage("ADMIN", new GPageAdmin);
}
//===============================================
void GWindow::addPage(QString key, QWidget* widget) {
    sGQt* lQt = GManager::Instance()->dataGet()->qt;
    lQt->page_map->addWidget(widget);
    lQt->page_id[key] = lQt->page_map->count();
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
            lTitleBar->update = "fullscreen_img";
            lTitleBar->update_img = ":/img/exit_fullscreen.png";
            emit emitTitleUpdate();
        }
        else {
            showNormal();
            lTitleBar->update = "fullscreen_fa";
            lTitleBar->update_fa = fa::arrowsalt;
            emit emitTitleUpdate();
        }
    }
    else if(lTitleBar->click_id == "minimize") {
        showMinimized();
    }
    else if(lTitleBar->click_id == "maximize") {
        if(windowState() != Qt::WindowMaximized) {
            showMaximized();
            lTitleBar->update = "maximize_fa";
            lTitleBar->update_fa = fa::windowrestore;
            emit emitTitleUpdate();
        }
        else {
            showNormal();
            lTitleBar->update = "maximize_fa";
            lTitleBar->update_fa = fa::windowmaximize;
            emit emitTitleUpdate();
        }
    }
    else if(lTitleBar->click_id == "close") {
        close();
    }
}
//===============================================
