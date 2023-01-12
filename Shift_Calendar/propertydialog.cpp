#include "propertydialog.h"
#include "ui_propertydialog.h"

PropertyDialog::PropertyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropertyDialog)
{
    ui->setupUi(this);
    // ポインタ初期化
    check_list[0] = ui->mon_check;
    check_list[1] = ui->tue_check;
    check_list[2] = ui->wed_check;
    check_list[3] = ui->thu_check;
    check_list[4] = ui->fri_check;
    check_list[5] = ui->sat_check;
    check_list[6] = ui->sun_check;
    shift_time[0] = ui->shift_time_checkbox_1;
    shift_time[1] = ui->shift_time_checkbox_2;
    shift_time[2] = ui->shift_time_checkbox_3;
    shift_time_line[0] = ui->shift_time_line_1;
    shift_time_line[1] = ui->shift_time_line_2;
    shift_time_line[2] = ui->shift_time_line_3;
    shift_num_box[0] = ui->shift_num_box_1;
    shift_num_box[1] = ui->shift_num_box_2;
    shift_num_box[2] = ui->shift_num_box_3;
}

PropertyDialog::~PropertyDialog()
{
    delete ui;
}

void PropertyDialog::get_property(QWidget *parent, struct MEMBER_PROPERTY *property)
{
    // 名前の取得.
    property->name = ui->name_line->text();
    // 固定出勤曜日の取得.
    for (int i=0; i<7; i++){
        property->go_dow[i] = check_list[i]->isChecked();
    }
    // 休暇希望日の取得.
    property->holiday = ui->holiday_line->text();
    // シフト時間の取得.
    for(int i=0; i<3; i++){
        property->shift_time[i] = shift_time[i]->isChecked();
        property->shift_time_str[i] = shift_time_line[i]->text();
        property->shift_num[i] = shift_num_box[i]->value();
    }

    return;
}

void PropertyDialog::on_buttonBox_accepted()
{
    okButtonClicked();
}

