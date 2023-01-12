#include "ShiftCalendar.h"
#include "ui_ShiftCalendar.h"

/*  エラーメッセージ  */
void error_msg(QString msg)
{
    qDebug() << "ERROR : " << msg;
}

Shift_Calendar::Shift_Calendar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Shift_Calendar)
{
    ui->setupUi(this);
    // 縦軸ラベル(日付ラベル).
    header_horizon << "";
    header_horizon_latter << "";
    for (int i=1; i <= 31; i++){
        header_horizon << QString::number(i);
        if(i > 15){
            header_horizon_latter << QString::number(i);
        }
    }
    // 横軸ラベル(名前ラベル).
    header_vertical.append("");
    row_count = 1;
    update_calendar();
    // シグナル.
    connect(dialog, SIGNAL(okButtonClicked()), this, SLOT(return_dialog()));
}

Shift_Calendar::~Shift_Calendar()
{
    delete ui;
}

// shift配列のintを表示する文字列に変換する関数.
QString Shift_Calendar::shift_int2str(int shift_int)
{
    switch (shift_int) {
        case HORYDAY:   // 休み希望日.
            return tr("//");
            break;
        case NON_SHIFT_DAY: // 入れるがシフトの無い日.
            return tr("/");
            break;
        case SHIFT_LINE_1: // シフト時間1なら.
            return shift_list[0];
            break;
        default:        // その他(未定 or シフトの時間).
            return QString::number(shift_int);  // 現在はそのまま数値を返す.
            break;
    }
}


// シフト表のヘッダーの表示を行う関数.
void Shift_Calendar::display_header()
{
    // ========= 列ラベルの表示 ========
    int addline = 1;    // 日付以外の列の数(現在は詳細ボタンの1列のみ);
    // 年と月を整数型で取得.
    int year = ui->year_Box->value();
    QString month_string = ui->month_Box->currentText();
    int month = month_string.toInt();
    // 表示上の月の日数を計算して日数分の列の表に設定
    QDate this_day(year, month, 1);
    int days_this_month = this_day.daysInMonth();
    // 表示月boxの状態よって月の前後半の表示範囲を変える.
    int display_area = ui->display_month_Box->currentIndex();
    switch(display_area){
        case 0: // 前半の場合15日まで表示.
            ui->tableWidget->setColumnCount(15+addline);
            ui->tableWidget->setHorizontalHeaderLabels(header_horizon);
            break;
        case 1: // 後半の場合16日から月末まで表示.
            ui->tableWidget->setColumnCount(days_this_month-15+addline);
            ui->tableWidget->setHorizontalHeaderLabels(header_horizon_latter);
            break;
        default:    // その他の場合月全体を表示.
            ui->tableWidget->setColumnCount(days_this_month+addline);
            ui->tableWidget->setHorizontalHeaderLabels(header_horizon);
            break;
    }

    // ======== 行ラベルの表示 ========
    int add_row = 1;    // 人の行と曜日以外の行の数(現在は合計人数の行のみ)
    // 行数,行ラベルの設定
    ui->tableWidget->setRowCount(row_count+add_row);
    QStringList tmp_header_vertical = header_vertical;  // 最終行(合計人数の行)はラベルを空欄にするための処理
    tmp_header_vertical << " ";
    ui->tableWidget->setVerticalHeaderLabels(tmp_header_vertical);
}

// シフト表の表の雛形部分を更新する関数.
// ウィジェット上部のBoxから年と月を取得してその月の日数分の列を持つ表に更新.
void Shift_Calendar::update_calendar()
{
    display_header();   // ヘッダーの表示.
    int year = ui->year_Box->value();
    QString month_string = ui->month_Box->currentText();
    int month = month_string.toInt();

    int cnt_column = ui->tableWidget->columnCount();    // 列の数

    // ======== 曜日行の表示 ========
    // １行目に曜日の入力.
    int i = 1;
    while(i < ui->tableWidget->columnCount()){
        // 列ラベルから日付を取得.
        QTableWidgetItem *day = ui->tableWidget->horizontalHeaderItem(i);
        QString str_day = day->text();
        int num_day = str_day.toInt();
        // 取得した日付から曜日を取得.
        QDate current_day(year, month, num_day);
        int j = current_day.dayOfWeek();
        // 曜日を1行目に入力.
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(DofW[j-1]));
        ui->tableWidget->setItem(0, i++, newItem);
    }

    // ======== 人物行の表示 ========
    i = 1;
    while(i < row_count){
        struct member_data this_mem = ST_memdata_list[i-1];
        // 1行毎にボタンとシフトを表示.
        for(int column = 0; column < cnt_column; column++){
            if(column == 0){
                ui->tableWidget->setCellWidget(i, column, this_mem.pro_button);   // 詳細ボタン.
            }else{
                // 列ラベルから日付を取得.
                QTableWidgetItem *day = ui->tableWidget->horizontalHeaderItem(column);
                QString str_day = day->text();
                int num_day = str_day.toInt();
                // 現在の行の人物の日付のシフトを文字列で表示する.
                QTableWidgetItem *newItem = new QTableWidgetItem(shift_int2str(this_mem.shift[num_day-1]));
                ui->tableWidget->setItem(i , column, newItem);
            }
        }
        i++;
    }

    // ======== 合計行の表示 ========
    i = 0;
    QTableWidgetItem *newItem = new QTableWidgetItem(tr("合計")); // 合計ラベルの表示
    ui->tableWidget->setItem(row_count, i++, newItem);
    while(i < cnt_column){                   // 合計の数を表示.
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(count_num_shift(i)));
        ui->tableWidget->setItem(row_count, i, newItem);  // 人がいるときに前半から後半にするとここでエラー
        i++;
    }
}

// シフトに入っている人をカウントする関数
int Shift_Calendar::count_num_shift(int column)
{
    // column列についてshift_list[0-2]と同じ文字列の数をカウントして返す
    int num = 0;
    for(int i=1; i<row_count; i++){ // 曜日行は飛ばすため1から
        QString cell_text = ui->tableWidget->item(i, column)->text();
        bool is_num;
        cell_text.toInt(&is_num);
        // shift_listのどれかと同じ文字列が入っていればカウントする.
        if(cell_text == shift_list[0] || cell_text == shift_list[1] || cell_text == shift_list[2] || is_num){
            num++;
        }
    }
    return num;
}

// 年入力欄に変更があった時.
void Shift_Calendar::on_year_Box_valueChanged(int arg1)
{
    update_calendar();
}

// 月入力欄に変更があった時.
void Shift_Calendar::on_month_Box_currentIndexChanged(int index)
{
    update_calendar();
}

// 表示範囲に変更があった時.
void Shift_Calendar::on_display_month_Box_currentIndexChanged(int index)
{
    update_calendar();
}

// +ボタンを押した時.
// プロパティ入力ダイアログを表示.
void Shift_Calendar::on_pushButton_clicked()
{
    dialog_flag = PLUS_BUTTON;
    dialog->show();
    dialog->activateWindow();
}

// プロパティボタンを押した際.
// プロパティダイアログを表示 + 初期入力にその人のデータを入れておく.
void Shift_Calendar::on_propertyButton_clicked()
{
    dialog_flag = PROPERTY_BUTTON;
    dialog->show();
    dialog->activateWindow();
}

// dialogから戻った際に呼ばれる関数.
void Shift_Calendar::return_dialog()
{
    switch(dialog_flag){
        case PROPERTY_BUTTON:   // プロパティボタンから戻った際
            update_property();
            update_shift_list();
            break;
        case PLUS_BUTTON:       // プラスボタンから戻った際
            add_line();
            update_shift_list();
            break;
        default:
            break;
    }
}

// (dialogから戻った際共通して処理する関数)
// dialogのシフト時間に入力している文字を取得する.
void Shift_Calendar::update_shift_list()
{
    for(int i=0; i<3; i++){
        shift_list[i] = ST_memdata_list.last().property.shift_time_str[i];
    }
}

// プロパティボタンで呼ばれたdialogから戻った際の処理.
void Shift_Calendar::update_property()
{
    // 更新されたプロパティを取得.
    struct PropertyDialog::MEMBER_PROPERTY pro;
    dialog->get_property(this, &pro);
    // 押されたボタンの行のデータを書き換える.
    // 行番号と書き換えるデータを渡して行番号と構造体リストの両方を更新する関数にしたほうが良いかも
    int current_num = ui->tableWidget->currentRow() - 1;
    ST_memdata_list[current_num].property = pro;
    set_holiday_list(current_num+1);
    header_vertical[current_num+1] = pro.name;  // 行ラベルも書き換える.
    for(int i=0; i<3; i++){
        shift_num[i] = pro.shift_num[i];
    }
    update_calendar();
}

// 1行追加する処理(+ボタンからダイアログをOKで終了した時に呼ばれる).
void Shift_Calendar::add_line()
{
    // ダイアログに入力したデータを構造体で取得.
    struct PropertyDialog::MEMBER_PROPERTY pro;
    dialog->get_property(this, &pro);
    // 取得したデータをにもとづいて表示を更新
    row_count++;                        // 1行追加.
    header_vertical.append(pro.name);   // 追加した行のラベルにダイアログから取得した名前を設定.
    // 1列目にプロパティ用のボタンを設定.
    QPushButton *button = new QPushButton();
    button->setText("詳細");
    connect(button, SIGNAL(clicked()), this, SLOT(on_propertyButton_clicked()));    // デストラクタでdeleteされているか確認する.
    // 構造体リストに個人データを保存
    struct member_data memdata;
    memdata.pro_button = button;
    memdata.property = pro;
    ST_memdata_list.append(memdata);
    set_holiday_list(row_count-1);
    update_calendar();
    for(int i=0; i<3; i++){
        shift_num[i] = pro.shift_num[i];
    }
}


// 自動入力ボタンが押された際の処理
// shift配列の中身を変える
void Shift_Calendar::on_auto_input_Button_clicked()
{
//    int i = 0;
//    // シフトの自動入力を行う.
//    // 上から順に人の行のみ確認する(0行目は曜日,最終行は人数なのでスキップ).
//    while(++i < row_count){
//        int j = 0;
//        // i行目について表示上のすべての日についてシフトを確認.
//        while(j < 31){
//            // 今は完全ランダム.
//            if(ST_memdata_list[i-1].shift[j] == NON_SHIFT_DAY){
//                if(QRandomGenerator::system()->generate() % 2 == 1){
//                    ST_memdata_list[i-1].shift[j] = SHIFT_LINE_1;
//                }
//            }
//            j++;
//        }
//    }
    int day_idx = 0;
    while(day_idx < 31){
        // ==== もし入れる人数が必須人数以下ならば入れる人は全員出勤にする. ====
        // 入れる人の人数を数える.
        int i = 0;
        int can_shift_num = 0;          // 休暇日の人数
        int shift_on_num[3] = {0};      // 各シフト時間別の入っている人数
        while(++i < row_count){ // 出勤できる人数を数える.
            int shift_time = ST_memdata_list[i-1].shift[day_idx];
            if(shift_time != HORYDAY){
                switch (shift_time) {
                    case SHIFT_LINE_1:
                        shift_on_num[0]++;
                        break;
                    case SHIFT_LINE_2:
                        shift_on_num[1]++;
                        break;
                    case SHIFT_LINE_3:
                        shift_on_num[2]++;
                        break;
                    case NON_SHIFT_DAY:
                        can_shift_num++;
                        break;
                    default:
                        break;
                }
            }
        }
        /// 以下勤務時間1のみ実装
        // 人数が足りない時は休暇希望の人以外出勤.
        if(can_shift_num + shift_on_num[0] <= shift_num[0]){
            i = 0;
            while(++i < row_count){
                if(ST_memdata_list[i-1].shift[day_idx] != HORYDAY){
                    ST_memdata_list[i-1].shift[day_idx] = SHIFT_LINE_1;
                }
            }
        }else{  // 人数が足りている場合は差分だけ完全ランダムに出勤.
            // 無限ループかも
//            int dif_num = shift_num[0] - shift_on_num[0];
//            for(int k=0; k < dif_num;){
//                int rand = QRandomGenerator::system()->generate()%dif_num;
//                if(ST_memdata_list[rand].shift[day_idx] == NON_SHIFT_DAY){
//                    ST_memdata_list[rand].shift[day_idx] = SHIFT_LINE_1;
//                    k++;
//                }
//            }
        }
        day_idx++;
    }
    update_calendar();
}

// 行数をもとに対象人物の休み希望を文字列から取得し、struct member_data内のshift配列に反映させる.
// プロパティの休み希望日入力欄から休み希望を取得.
// 引数:操作中の行数(0スタート).
void Shift_Calendar::set_holiday_list(int row)
{
    // 対象人物のデータ(構造体)を取得.
    struct PropertyDialog::MEMBER_PROPERTY pro = ST_memdata_list[row-1].property;
    // ==== 休み希望文字列から対象の日付を取得 ====
    QString holiday = pro.holiday;
    bool not_shift[31] = {false};
    int i = 0;
    int idx = 0;
    // 数字以外の文字で区切り、入力された日付を記録.
    while(i++ < holiday.length()){
        if(holiday[i-1].isNumber()){
            idx = idx*10 + holiday[i-1].digitValue();
        }else{
            if(idx <= 31){
                not_shift[idx-1] = true;
            }else{
                error_msg("over month day/ in set_holiday_list()");
            }
            idx = 0;
        }
    }
    // 文字列終了時の最後の日付も反映.
    if(idx != 0){
        if(idx <= 31){
            not_shift[idx-1] = true;
        }else{
            error_msg("over month day/ in set_holiday_list()");
        }
    }
    // ==== 取得した日付に基づいてshift配列に反映 ====
    for(int i=0; i < 31; i++){
        if(not_shift[i]){
            ST_memdata_list[row-1].shift[i] = HORYDAY;
        }else{
            ST_memdata_list[row-1].shift[i] = NON_SHIFT_DAY;
        }
    }

}

// 更新ボタンが押された時.
// 現在表示されている内容に内部データを書き換える(shift配列の中身のみ).
void Shift_Calendar::on_pushButton_2_clicked()
{
    for (int row = 1; row < row_count; row++){
        for(int column = 1; column < ui->tableWidget->columnCount(); column++){
            // 列ラベルから日付を取得.
            int num_day = ui->tableWidget->horizontalHeaderItem(column)->text().toInt();
            bool is_num;
            // 該当セルの表示テキストを取得.
            QString cell_text = ui->tableWidget->item(row, column)->text();
            int shift_time = cell_text.toInt(&is_num);
            // 表示テキストに合わせて内部データ(shift[])を変更.
            if(is_num){ // 数字ならそのまま数値を入れる.
                ST_memdata_list[row-1].shift[num_day-1] = shift_time;
                return;
            }
            // 休暇日ならその文字列に対応した数値を入れる.
            if(cell_text == "/"){
                ST_memdata_list[row-1].shift[num_day-1] = NON_SHIFT_DAY;
            }else if(cell_text == "//"){
                ST_memdata_list[row-1].shift[num_day-1] = HORYDAY;
            }
        }
    }
    // 代入が間違ってないことを確認するための再度画面更新.
    update_calendar();
}

