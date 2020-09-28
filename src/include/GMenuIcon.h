//===============================================
#ifndef _GMenuIcon_
#define _GMenuIcon_
//===============================================
#include "GInclude.h"
//===============================================
class GMenuIcon : public QFrame {
    Q_OBJECT
    
public:
    GMenuIcon(QWidget* parent  = 0);
    ~GMenuIcon();
    
public:
    void setIcon(QIcon icon);
    void setTitle(QString title);

private:
    QToolButton* m_icon;
    QLabel* m_title;
    QVBoxLayout* m_mainLayout;
};
//===============================================
#endif
//===============================================

