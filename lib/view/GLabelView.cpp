//===============================================
#include "GLabelView.h"
#include "ui_GLabelView.h"
#include <QCloseEvent>
//===============================================
GLabelView* GLabelView::m_instance = 0;
//===============================================
GLabelView::GLabelView(QWidget *parent) :
    QWidget(parent), ui(new Ui::GLabelView) {
    ui->setupUi(this);
    resize(400, 300);
}
//===============================================
GLabelView::~GLabelView() {
    delete ui;
}
//===============================================
GLabelView* GLabelView::Instance() {
    if(m_instance == 0) {
        m_instance = new GLabelView;
    }
    return m_instance;
}
//===============================================
void GLabelView::closeEvent(QCloseEvent *event) {
    qApp->closeAllWindows();
    event->accept();
}
//===============================================
