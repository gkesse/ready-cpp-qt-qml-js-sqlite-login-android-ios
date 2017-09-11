//===============================================
#include "GButtonView.h"
#include "ui_GButtonView.h"
#include <QCloseEvent>
//===============================================
GButtonView* GButtonView::m_instance = 0;
//===============================================
GButtonView::GButtonView(QWidget *parent) :
    QWidget(parent), ui(new Ui::GButtonView) {
    ui->setupUi(this);

}
//===============================================
GButtonView::~GButtonView() {
    delete ui;
}
//===============================================
GButtonView* GButtonView::Instance() {
    if(m_instance == 0) {
        m_instance = new GButtonView;
    }
    return m_instance;
}
//===============================================
void GButtonView::closeEvent(QCloseEvent *event) {
    qApp->closeAllWindows();
    event->accept();
}
//===============================================
