//===============================================
#include "GComboBoxView.h"
#include "ui_GComboBoxView.h"
#include <QCloseEvent>
//===============================================
GComboBoxView* GComboBoxView::m_instance = 0;
//===============================================
GComboBoxView::GComboBoxView(QWidget *parent) :
    QWidget(parent), ui(new Ui::GComboBoxView) {
    ui->setupUi(this);
    resize(400, 300);
}
//===============================================
GComboBoxView::~GComboBoxView() {
    delete ui;
}
//===============================================
GComboBoxView* GComboBoxView::Instance() {
    if(m_instance == 0) {
        m_instance = new GComboBoxView;
    }
    return m_instance;
}
//===============================================
void GComboBoxView::closeEvent(QCloseEvent *event) {
    qApp->closeAllWindows();
    event->accept();
}
//===============================================
