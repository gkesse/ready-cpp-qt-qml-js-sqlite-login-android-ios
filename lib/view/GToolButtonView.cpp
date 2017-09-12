//===============================================
#include "GToolButtonView.h"
#include "ui_GToolButtonView.h"
#include "GMessageView.h"
#include "GPicto.h"
#include <QCloseEvent>
//===============================================
GToolButtonView* GToolButtonView::m_instance = 0;
//===============================================
GToolButtonView::GToolButtonView(QWidget *parent) :
    QWidget(parent), ui(new Ui::GToolButtonView) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
}
//===============================================
GToolButtonView::~GToolButtonView() {
    delete ui;
}
//===============================================
GToolButtonView* GToolButtonView::Instance() {
    if(m_instance == 0) {
        m_instance = new GToolButtonView;
    }
    return m_instance;
}
//===============================================
void GToolButtonView::closeEvent(QCloseEvent *event) {
    qApp->closeAllWindows();
    event->accept();
}
//===============================================
void GToolButtonView::createObjects() {
    ui->m_facebook->setIcon(GPicto::Instance()->getPicto(fa::facebook));
    ui->m_skype->setIcon(GPicto::Instance()->getPicto(fa::skype));
    ui->m_github->setIcon(GPicto::Instance()->getPicto(fa::github));
    ui->m_linkedin->setIcon(GPicto::Instance()->getPicto(fa::linkedin));

    ui->m_facebook->setIconSize(QSize(20, 20));
    ui->m_skype->setIconSize(QSize(20, 20));
    ui->m_github->setIconSize(QSize(20, 20));
    ui->m_linkedin->setIconSize(QSize(20, 20));

    resize(400, 300);
}
//===============================================
void GToolButtonView::createConnexions() {
    connect(ui->m_facebook, SIGNAL(clicked()), this, SLOT(facebookSlot()));
    connect(ui->m_skype, SIGNAL(clicked()), this, SLOT(skypeSlot()));
    connect(ui->m_github, SIGNAL(clicked()), this, SLOT(githubSlot()));
    connect(ui->m_linkedin, SIGNAL(clicked()), this, SLOT(linkedinSlot()));
}
//===============================================
void GToolButtonView::facebookSlot() {
    GMessageView::Instance()->showData("Facebook ToolButton is clicked...");
}
//===============================================
void GToolButtonView::skypeSlot() {
    GMessageView::Instance()->showData("Skype ToolButton is clicked...");
}
//===============================================
void GToolButtonView::githubSlot() {
    GMessageView::Instance()->showData("GitHub ToolButton is clicked...");
}
//===============================================
void GToolButtonView::linkedinSlot() {
    GMessageView::Instance()->showData("LinkedIn ToolButton is clicked...");
}

//===============================================
