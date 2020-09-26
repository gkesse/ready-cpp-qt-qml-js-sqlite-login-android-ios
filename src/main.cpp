//===============================================
#include "GManager.h"
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    sGQt* lQt = GManager::Instance()->dataGet()->qt;
    
    QWidget* lWindow = new QWidget;
    
    QLabel* lLabel = new QLabel;    
    lLabel->setText("Bonjour tout le monde\n");
    
    QVBoxLayout* lLayout = new QVBoxLayout;    
    lLayout->addWidget(lLabel);
    lLayout->setAlignment(Qt::AlignCenter);
    
    lWindow->setLayout(lLayout);
    lWindow->setWindowTitle(lQt->title);
    lWindow->resize(lQt->width, lQt->height);
    lWindow->show();
    return app.exec();
}
//===============================================
