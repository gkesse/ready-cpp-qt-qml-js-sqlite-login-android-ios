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
    void createMenuAddress();
    void createMenuBody();
    void createLayout();
    
private:
    QStringList m_menuKey;
    QHBoxLayout* m_menuAddressLayout;
    QHBoxLayout* m_menuBodyLayout;
    QVBoxLayout* m_mainLayout;
    QTextEdit* m_workspace;
};
//===============================================
#endif
//===============================================

