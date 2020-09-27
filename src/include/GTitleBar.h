//===============================================
#ifndef _GTitleBar_
#define _GTitleBar_
//===============================================
#include "GInclude.h"
//===============================================
class GTitleBar : public QFrame {
    Q_OBJECT
    
public:
    GTitleBar(QWidget* parent  = 0);
    ~GTitleBar();
    
private:
    QToolButton* m_icon;
    QLabel* m_title;
    QToolButton* m_minimize;
    QToolButton* m_maximize;
    QToolButton* m_close;
};
//===============================================
#endif
//===============================================

