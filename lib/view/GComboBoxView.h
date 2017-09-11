//===============================================
#ifndef _GComboBoxView_
#define _GComboBoxView_
//===============================================
#include <QWidget>
//===============================================
namespace Ui {
class GComboBoxView;
}
//===============================================
class GComboBoxView : public QWidget {
    Q_OBJECT

private:
    GComboBoxView(QWidget *parent = 0);

public:
    ~GComboBoxView();
    static GComboBoxView* Instance();

protected:
    void closeEvent(QCloseEvent *event);

private:
    static GComboBoxView* m_instance;
    Ui::GComboBoxView *ui;
};
//===============================================
#endif
//===============================================
