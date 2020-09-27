//===============================================
#include "GWindow.h"
#include "GTitleBar.h"
#include "GManager.h"
//===============================================
GWindow::GWindow(QWidget* parent) : QFrame(parent) {
    sGQt* lQt = GManager::Instance()->dataGet()->qt;
    
    GTitleBar* lTitleBar = new GTitleBar;
    
    QLabel* lLabel = new QLabel;    
    lLabel->setText("Bonjour tout le monde\n");
    lLabel->setAlignment(Qt::AlignCenter);
    lLabel->setMargin(0);
    
    QVBoxLayout* lLayout = new QVBoxLayout;    
    lLayout->addWidget(lTitleBar, 0);
    lLayout->addWidget(lLabel, 1);
    lLayout->setMargin(0);
    
    setLayout(lLayout);
    setWindowTitle(lQt->title);
    resize(lQt->width, lQt->height);
}
//===============================================
GWindow::~GWindow() {
    
}
//===============================================
