//===============================================
#ifndef _GLabelView_
#define _GLabelView_
//===============================================
#include <QWidget>
//===============================================
namespace Ui {
class GLabelView;
}
//===============================================
class GLabelView : public QWidget {
    Q_OBJECT

private:
    GLabelView(QWidget *parent = 0);

public:
    ~GLabelView();
    static GLabelView* Instance();

protected:
    void closeEvent(QCloseEvent *event);

private:
    static GLabelView* m_instance;
    Ui::GLabelView *ui;
};
//===============================================
#endif
//===============================================
