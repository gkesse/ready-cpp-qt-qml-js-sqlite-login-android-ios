//===============================================
#include "GOpenGL.h"
#include "ui_GOpenGL.h"
#include <QCloseEvent>
//===============================================
GOpenGL* GOpenGL::m_instance = 0;
//===============================================
GOpenGL::GOpenGL(QWidget *parent) :
    QWidget(parent), ui(new Ui::GOpenGL) {
    ui->setupUi(this);

}
//===============================================
GOpenGL::~GOpenGL() {
    delete ui;
}
//===============================================
GOpenGL* GOpenGL::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenGL;
    }
    return m_instance;
}
//===============================================
void GOpenGL::closeEvent(QCloseEvent *event) {
    qApp->closeAllWindows();
    event->accept();
}
//===============================================
