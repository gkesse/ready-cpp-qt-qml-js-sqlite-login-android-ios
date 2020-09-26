//===============================================
#include "GWindow.h"
#include "GManager.h"
//===============================================
GWindow::GWindow(QWidget* parent) : QFrame(parent) {
    sGQt* lQt = GManager::Instance()->dataGet()->qt;
        
    QLabel* lLabel = new QLabel;    
    lLabel->setText("Bonjour tout le monde\n");
    
    QVBoxLayout* lLayout = new QVBoxLayout;    
    lLayout->addWidget(lLabel);
    lLayout->setAlignment(Qt::AlignCenter);
    
    setLayout(lLayout);
    setWindowTitle(lQt->title);
    resize(lQt->width, lQt->height);
}
//===============================================
GWindow::~GWindow() {
    
}
//===============================================
