//===============================================
#include "GRadioButtonView.h"
#include "ui_GRadioButtonView.h"
#include "GMessageView.h"
#include <QCloseEvent>
//===============================================
GRadioButtonView* GRadioButtonView::m_instance = 0;
//===============================================
GRadioButtonView::GRadioButtonView(QWidget *parent) :
    QWidget(parent), ui(new Ui::GRadioButtonView) {
    ui->setupUi(this);
    createObjects();
    createConnections();
}
//===============================================
GRadioButtonView::~GRadioButtonView() {
    delete ui;
}
//===============================================
GRadioButtonView* GRadioButtonView::Instance() {
    if(m_instance == 0) {
        m_instance = new GRadioButtonView;
    }
    return m_instance;
}
//===============================================
void GRadioButtonView::closeEvent(QCloseEvent *event) {
    qApp->closeAllWindows();
    event->accept();
}
//===============================================
void GRadioButtonView::createObjects() {
    m_radioGroup1 = new QButtonGroup(this);
    m_radioGroup1->addButton(ui->m_yes);
    m_radioGroup1->addButton(ui->m_no);
    m_radioGroup1->addButton(ui->m_maybe);

    m_radioGroup2 = new QButtonGroup(this);
    m_radioGroup2->addButton(ui->m_male);
    m_radioGroup2->addButton(ui->m_female);
    m_radioGroup2->addButton(ui->m_notSure);
}
//===============================================
void GRadioButtonView::createConnections() {
    connect(ui->m_run, SIGNAL(clicked()), this, SLOT(runSlot()));
}
//===============================================
void GRadioButtonView::runSlot() {
    QString m_message = "";
    QString m_ready = "_NONE_";
    QString m_genre = "_NONE_";

    if(ui->m_yes->isChecked() == true) m_ready = "Yes";
    else if(ui->m_no->isChecked() == true) m_ready = "No";
    else if(ui->m_maybe->isChecked() == true) m_ready = "Maybe";

    if(ui->m_male->isChecked() == true) m_genre = "Male";
    else if(ui->m_female->isChecked() == true) m_genre = "Female";
    else if(ui->m_notSure->isChecked() == true) m_genre = "Not sure";

    m_message += QString("Are you ready? : %1\n").arg(m_ready);
    m_message += QString("Male or female? : %1").arg(m_genre);

    GMessageView::Instance()->showData(m_message);
    GMessageView::Instance()->separate();
}
//===============================================
