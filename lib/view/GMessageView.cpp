//===============================================
#include "GMessageView.h"
#include "ui_GMessageView.h"
#include <QDesktopWidget>
//===============================================
GMessageView* GMessageView::m_instance = 0;
//===============================================
GMessageView::GMessageView(QWidget *parent) :
QWidget(parent), ui(new Ui::GMessageView) {
    ui->setupUi(this);
    setPosition();
}
//===============================================
GMessageView::~GMessageView() {
    delete ui;
}
//===============================================
GMessageView* GMessageView::Instance() {
    if(m_instance == 0) {
        m_instance = new GMessageView;
    }
    return m_instance;
}
//===============================================
void GMessageView::setPosition() {
    QRect m_desktop = QApplication::desktop()->screenGeometry();
    int m_width = 400;
    int m_height = 200;
    int m_x = m_desktop.width() - m_width;
    int m_y = m_desktop.height() - m_height - 50;
    setGeometry(m_x, m_y, m_width, m_height);
}
//===============================================
void GMessageView::showData(const QString& data, const QString& name) {
    QString m_format = "";
    if(name != "") m_format += name + " : ";
    m_format += data;
    ui->m_message->append(m_format);
}
//===============================================
void GMessageView::showData(const int& data, const QString& name) {
    QString m_format = QString("%1").arg(data);
    showData(m_format, name);
}
//===============================================
void GMessageView::showData(const uint& data, const QString& name) {
    QString m_format = QString("%1").arg(data);
    showData(m_format, name);
}
//===============================================
void GMessageView::showData(const long& data, const QString& name) {
    QString m_format = QString("%1").arg(data);
    showData(m_format, name);
}
//===============================================
void GMessageView::showData(const ulong& data, const QString& name) {
    QString m_format = QString("%1").arg(data);
    showData(m_format, name);
}
//===============================================
void GMessageView::showData(const double& data, const QString& name) {
    QString m_format = QString("%1").arg(data);
    showData(m_format, name);
}
//===============================================

