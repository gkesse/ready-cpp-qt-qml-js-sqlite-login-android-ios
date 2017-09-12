//===============================================
#include "GPushButtonView.h"
#include "ui_GPushButtonView.h"
#include "GMessageView.h"
#include <QCloseEvent>
//===============================================
GPushButtonView* GPushButtonView::m_instance = 0;
//===============================================
GPushButtonView::GPushButtonView(QWidget *parent) :
    QWidget(parent), ui(new Ui::GPushButtonView) {
    ui->setupUi(this);
    resize(400, 300);
    createConnexions();
}
//===============================================
GPushButtonView::~GPushButtonView() {
    delete ui;
}
//===============================================
GPushButtonView* GPushButtonView::Instance() {
    if(m_instance == 0) {
        m_instance = new GPushButtonView;
    }
    return m_instance;
}
//===============================================
void GPushButtonView::closeEvent(QCloseEvent *event) {
    qApp->closeAllWindows();
    event->accept();
}
//===============================================
void GPushButtonView::createConnexions() {
    connect(ui->m_create, SIGNAL(clicked()), this, SLOT(createSlot()));
    connect(ui->m_read, SIGNAL(clicked()), this, SLOT(readSlot()));
    connect(ui->m_update, SIGNAL(clicked()), this, SLOT(updateSlot()));
    connect(ui->m_delete, SIGNAL(clicked()), this, SLOT(deleteSlot()));
}
//===============================================
void GPushButtonView::createSlot() {
    GMessageView::Instance()->showData("Create PushButton is clicked...");
}
//===============================================
void GPushButtonView::readSlot() {
    GMessageView::Instance()->showData("Read PushButton is clicked...");
}
//===============================================
void GPushButtonView::updateSlot() {
    GMessageView::Instance()->showData("Update PushButton is clicked...");
}
//===============================================
void GPushButtonView::deleteSlot() {
    GMessageView::Instance()->showData("Delete PushButton is clicked...");
}

//===============================================
