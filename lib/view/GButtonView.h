//===============================================
#ifndef _GButtonView_
#define _GButtonView_
//===============================================
#include <QWidget>
//===============================================
namespace Ui {
class GButtonView;
}
//===============================================
class GButtonView : public QWidget {
    Q_OBJECT

private:
    GButtonView(QWidget *parent = 0);

public:
    ~GButtonView();
    static GButtonView* Instance();

protected:
    void closeEvent(QCloseEvent *event);

private:
    static GButtonView* m_instance;
    Ui::GButtonView *ui;
};
//===============================================
#endif
//===============================================
