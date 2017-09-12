//===============================================
#ifndef _GRadioButtonView_
#define _GRadioButtonView_
//===============================================
#include <QWidget>
#include <QButtonGroup>
//===============================================
namespace Ui {
class GRadioButtonView;
}
//===============================================
class GRadioButtonView : public QWidget {
    Q_OBJECT

private:
    GRadioButtonView(QWidget *parent = 0);

public:
    ~GRadioButtonView();
    static GRadioButtonView* Instance();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void createObjects();
    void createConnections();

public slots:
    void runSlot();

private:
    static GRadioButtonView* m_instance;
    Ui::GRadioButtonView *ui;
    QButtonGroup* m_radioGroup1;
    QButtonGroup* m_radioGroup2;
};
//===============================================
#endif
//===============================================
