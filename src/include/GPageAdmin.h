//===============================================
#ifndef _GPageAdmin_
#define _GPageAdmin_
//===============================================
#include "GInclude.h"
//===============================================
class GPageAdmin : public QFrame {
    Q_OBJECT
    
public:
    GPageAdmin(QWidget* parent  = 0);
    ~GPageAdmin();
    
private:
    void createMenuKey();
    void createMenuName();
    void createMenuPicto();
    void createMenuPad();
    void createLayout();
    
private:
    QString G_PAGE_ID;
    QStringList m_menuKey;
    QMap<QString, QString> m_menuName;
    QMap<QString, int> m_menuPicto;
    QGridLayout* m_menuPadLayout;
    QHBoxLayout* m_menuAddressLayout;
    QHBoxLayout* m_menuBodyLayout;
    QVBoxLayout* m_mainLayout;
    QTextEdit* m_workspace;
};
//===============================================
#endif
//===============================================

