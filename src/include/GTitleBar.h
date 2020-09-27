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

public slots:
    void slotTitleClick();
    void slotTitleUpdate();
    
signals:
    void emitTitleClick();
    
private:
    QToolButton* m_icon;
    QLabel* m_title;
    QToolButton* m_fullscreen;
    QToolButton* m_minimize;
    QToolButton* m_maximize;
    QToolButton* m_close;
    QMap<QWidget*, QString> m_widgetId;
};
//===============================================
#endif
//===============================================

