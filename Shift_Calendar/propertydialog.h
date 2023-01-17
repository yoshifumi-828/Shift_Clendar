#ifndef PROPERTYDIALOG_H
#define PROPERTYDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QMessageBox>

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
//        bool shift_time[3] = {false};       // どのシフト時間に入るか.
        bool shift_time = false;            // シフトに入るか.
        bool go_dow[7] = {false};           // 固定出勤曜日.
        bool other_dow = true;              // 固定出勤曜日以外の曜日に入らないか.
        QString holiday = "";               // 休暇希望日.
//        QString shift_time_str[3] = {""};   // シフト時間の文字列.
        QString shift_time_str = "";   // シフト時間の文字列.
//        int shift_num[3] = {0};             // シフトの必要人数.
        int shift_num = 0;             // シフトの必要人数.
    };
//    bool shift_time_can[3] = {false};
    bool shift_time_can = false;
    void get_property(struct MEMBER_PROPERTY *property = nullptr);  // 親のウィジェットで使用するための名前取得関数(後で構造体取得にするかも).
    void set_property(int load_shift_num, QString load_shift_time_str, struct MEMBER_PROPERTY *property = nullptr);
//    void set_property(int load_shift_num[3], QString load_shift_time_str[3], struct MEMBER_PROPERTY *property = nullptr);

signals:
    void okButtonClicked(); // 親ウィジェットに伝えるシグナル.
    void deleteButtonClicked();

private slots:
    void on_buttonBox_accepted();   // OKボタンが押された際.

    void on_pushButton_clicked();

private:
    Ui::PropertyDialog *ui;
    QCheckBox *check_list[7];
//    QCheckBox *shift_time[3];
//    QLineEdit *shift_time_line[3];
//    QSpinBox *shift_num_box[3];
    QCheckBox *shift_time;
    QLineEdit *shift_time_line;
    QSpinBox *shift_num_box;
};

#endif // PROPERTYDIALOG_H
