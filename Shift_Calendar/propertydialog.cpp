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

// dialogに入力されている情報を取得する.
void PropertyDialog::get_property(struct MEMBER_PROPERTY *property)
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
    // 固定出勤曜日以外の出勤.
    property->other_dow = ui->other_dow_check->isChecked();
    return;
}

// dialogを表示する際の初期入力を設定する.
void PropertyDialog::set_property(int load_shift_num[3],QString load_shift_time_str[3],struct MEMBER_PROPERTY *property)
{
    if(property != nullptr){
        // 名前
        ui->name_line->setText(property->name);
        // 固定出勤曜日の設定.
        for (int i=0; i<7; i++){
        check_list[i]->setChecked(property->go_dow[i]);
        }
        // 休暇希望日の設定.
        ui->holiday_line->setText(property->holiday);
    }
    // シフト時間の設定.
    for(int i=0; i<3; i++){
        if(property != nullptr){
            shift_time[i]->setChecked(property->shift_time[i]);
        }
        shift_time_line[i]->setText(load_shift_time_str[i]);
        shift_num_box[i]->setValue(load_shift_num[i]);
    }
}

void PropertyDialog::on_buttonBox_accepted()
{
    okButtonClicked();
}


void PropertyDialog::on_pushButton_clicked()
{
    QMessageBox msgbox(this);
    msgbox.setIcon(QMessageBox::Question);
    msgbox.setWindowTitle(tr("確認"));
    msgbox.setText(tr("削除してよろしいですか？"));
    msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgbox.setDefaultButton(QMessageBox::No);
    msgbox.setButtonText(QMessageBox::Yes, tr("Yes"));
    msgbox.setButtonText(QMessageBox::No, tr("no"));
    int button = msgbox.exec();
    if(button == 0x4000){   // Yesの場合.
        deleteButtonClicked();
    }
}

