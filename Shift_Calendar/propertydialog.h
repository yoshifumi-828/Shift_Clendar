#ifndef PROPERTYDIALOG_H
#define PROPERTYDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QLineEdit>

namespace Ui {
class PropertyDialog;
}

class PropertyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PropertyDialog(QWidget *parent = nullptr);
    ~PropertyDialog();
    struct MEMBER_PROPERTY {    // プロパティで保存するデータの構造体.
        QString name = "";
        bool go_dow[7] = {false};
        QString holiday = "";
        bool shift_time[3] = {false};
        QString shift_time_str[3] = {""};
    };
    void get_property(QWidget *parent=nullptr, struct MEMBER_PROPERTY *property = nullptr);  // 親のウィジェットで使用するための名前取得関数(後で構造体取得にするかも).

signals:
    void okButtonClicked(); // 親ウィジェットに伝えるシグナル.

private slots:
    void on_buttonBox_accepted();   // OKボタンが押された際.

private:
    Ui::PropertyDialog *ui;
    QCheckBox *check_list[7];
    QCheckBox *shift_time[3];
    QLineEdit *shift_time_line[3];
};

#endif // PROPERTYDIALOG_H
