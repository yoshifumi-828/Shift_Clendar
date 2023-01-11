#ifndef SHIFTCALENDER_H
#define SHIFTCALENDER_H

#include <QWidget>
#include <time.h>
#include <QDate>
#include <QCalendar>
#include <QPushButton>
#include "propertydialog.h"
#include <QRandomGenerator> // 乱数用

#define HORYDAY -1          // シフトに入れない日.
#define NON_SHIFT_DAY -2    // シフトに入れるが休みの日.
#define SHIFT_LINE_1 -11    //  dialogでのシフト時間入力欄1
#define SHIFT_LINE_2 -12    //  dialogでのシフト時間入力欄2
#define SHIFT_LINE_3 -13    //  dialogでのシフト時間入力欄3
#define PLUS_BUTTON 0
#define PROPERTY_BUTTON 1

QT_BEGIN_NAMESPACE
namespace Ui { class Shift_Calendar; }
QT_END_NAMESPACE

class Shift_Calendar : public QWidget
{
    Q_OBJECT

public:
    Shift_Calendar(QWidget *parent = nullptr);
    ~Shift_Calendar();
    struct member_data{
        struct PropertyDialog::MEMBER_PROPERTY property;
        QPushButton *pro_button;
        int shift[31] = {NON_SHIFT_DAY};    // 31日間のシフトの状態(HORYDAY(//), NON_SHIFT_DAY(/), シフトの時間(dialogに入力しているもの), 手動入力(0-24))
    };

private slots:
    void on_year_Box_valueChanged(int arg1);            // 年入力欄に変更があった場合.
    void on_month_Box_currentIndexChanged(int index);   // 月入力欄に変更があった場合.
    void on_display_month_Box_currentIndexChanged(int index);   // 前半、後半、全体欄に変更があった場合.
    void on_pushButton_clicked();   // +ボタンが押された際.
    void on_propertyButton_clicked();   // プロパティボタンが押された際.
    void add_line();                // 行を追加する関数.
    void return_dialog();           // ダイアログをOKで終了した際に呼ばれる関数.
    void on_auto_input_Button_clicked();

private:
    Ui::Shift_Calendar *ui;
    // ==== 変数 ====
    int row_count;                      // 現在の行数を保持する変数.
    int dialog_flag;                    // ダイアログを呼ぶ際にどのボタンから呼んだかを記録するフラグ.
    QString DofW = "月火水木金土日";       // 曜日表示の際に使う文字列.
    QStringList header_horizon;         // 列のラベル(日付)を保持する文字列リスト.
    QStringList header_horizon_latter;  // 後半のみの列のラベル(日付)を保持する文字列リスト.
    QStringList header_vertical;        // 行のラベルを保持する文字列リスト.
    PropertyDialog *dialog = new PropertyDialog;    // プロパティ入力ダイアログ.
    QVector<member_data> ST_memdata_list;
    QPushButton *button;
    QString shift_list[3];
    // ==== 関数 ====
    void update_calendar();             // カレンダーの表示を更新する関数.
    void update_property();             // プロパティボタンが押された際に戻る関数.
    void set_holiday_list(int row);     // 行数をもとに対象人物の休み希望を文字列から取得し、struct member_data内のshift配列に反映させる.
    void update_shift_list();           // structのshiftを更新する関数.
    void display_header();              // ヘッダーを表示する関数.
    int count_num_shift(int column);    // シフトに入っている人の人数を数える関数.
    QString shift_int2str(int shift_int);   // シフト配列のintを渡すとQString型で表示すべきシフトの文字列を返す関数.
};
#endif // SHIFTCALENDER_H
