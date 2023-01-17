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
    // 縦軸ラベル(日付ラベル)の初期化.
    header_horizon << "";
    header_horizon_latter << "";
    for (int i=1; i <= 31; i++){
        header_horizon << QString::number(i);
        if(i > 15){
            header_horizon_latter << QString::number(i);
        }
    }
    // 横軸ラベル(名前ラベル)の初期化.
    header_vertical.append("");
    row_count = 1;
    // その他の初期化
    load_data();
    update_calendar();
    // シグナル.
    connect(dialog, SIGNAL(okButtonClicked()), this, SLOT(return_dialog()));
    connect(dialog, SIGNAL(deleteButtonClicked()), this, SLOT(delete_line()));
}

Shift_Calendar::~Shift_Calendar()
{
    delete ui;
}

// shift配列のintを表示する文字列に変換する関数.
QString Shift_Calendar::shift_int2str(int shift_int)
{
    switch (shift_int) {
        case HORYDAY:       // 休み希望日.
            return tr("//");
        case NON_SHIFT_DAY: // 入れるがシフトの無い日.
            return tr("/");
        case SHIFT_LINE_1:  // シフト時間1なら.
            return shift_time_str;
//        case SHIFT_LINE_2:  // シフト時間2なら.
//            return shift_time_str[1];
//        case SHIFT_LINE_3:  // シフト時間3なら.
//            return shift_time_str[2];
        default:            // その他(未定 or シフトの時間).
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
//    ui->tableWidget->clear(); // これをするとセットしたウィジェットの元まで消される.
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
        if(j == 7){ // 日曜日だけ赤色に設定
            newItem->setForeground(QBrush(QColor(255, 0, 0)));
        }
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
    // column列についてshift_time_str[0-2]と同じ文字列の数をカウントして返す
    int num = 0;
    for(int i=1; i<row_count; i++){ // 曜日行は飛ばすため1から
        QString cell_text = ui->tableWidget->item(i, column)->text();
        bool is_num;
        cell_text.toInt(&is_num);
        // shift_time_strのどれかと同じ文字列 or 数値 が入っていればカウントする.
//        if(cell_text == shift_time_str[0] || cell_text == shift_time_str[1] || cell_text == shift_time_str[2] || is_num){
//            num++;
//        }
          if(cell_text == shift_time_str){
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
    dialog->set_property(shift_num, shift_time_str);
    dialog->show();
    dialog->activateWindow();
}

// プロパティボタンを押した際.
// プロパティダイアログを表示 + 初期入力にその人のデータを入れておく.
void Shift_Calendar::on_propertyButton_clicked()
{
    dialog_flag = PROPERTY_BUTTON;
    int row_num = ui->tableWidget->currentRow();
    dialog->set_property(shift_num, shift_time_str, &ST_memdata_list[row_num-1].property);
    dialog->show();
    dialog->activateWindow();
}

// dialogから戻った際に呼ばれる関数.
void Shift_Calendar::return_dialog()
{
    switch(dialog_flag){
        case PROPERTY_BUTTON:   // プロパティボタンから戻った際
            update_property();
            set_shift_dow(ui->tableWidget->currentRow());
//            for(int i=0; i<3; i++){
//                shift_time_str[i] = ST_memdata_list[ui->tableWidget->currentRow()-1].property.shift_time_str[i];
//            }
            shift_time_str = ST_memdata_list[ui->tableWidget->currentRow()-1].property.shift_time_str;
            update_calendar();
            break;
        case PLUS_BUTTON:       // プラスボタンから戻った際
            add_line();
            set_shift_dow(row_count-1);
//            for(int i=0; i<3; i++){
//                shift_time_str[i] = ST_memdata_list.last().property.shift_time_str[i];
//            }
            shift_time_str = ST_memdata_list.last().property.shift_time_str;
            update_calendar();
            break;
        default:
            break;
    }
}

// プロパティボタンで呼ばれたdialogから戻った際の処理.
void Shift_Calendar::update_property()
{
    // 更新されたプロパティを取得.
    struct PropertyDialog::MEMBER_PROPERTY pro;
    dialog->get_property(&pro);
    // 押されたボタンの行のデータを書き換える.
    // 行番号と書き換えるデータを渡して行番号と構造体リストの両方を更新する関数にしたほうが良いかも
    int current_num = ui->tableWidget->currentRow() - 1;
    ST_memdata_list[current_num].property = pro;
    set_holiday_list(current_num+1);
    header_vertical[current_num+1] = pro.name;  // 行ラベルも書き換える.
    for(int i=0; i<3; i++){
        shift_num = pro.shift_num;
//        shift_num[i] = pro.shift_num[i];
    }
    update_calendar();
}

// 1行追加する処理(+ボタンからダイアログをOKで終了した時に呼ばれる).
void Shift_Calendar::add_line(int *shift)
{
    // ダイアログに入力したデータを構造体で取得.
    struct PropertyDialog::MEMBER_PROPERTY pro;
    dialog->get_property(&pro);
    // 取得したデータをにもとづいて表示を更新
    row_count++;                        // 1行追加.
    header_vertical.append(pro.name);   // 追加した行のラベルにダイアログから取得した名前を設定.
    // 1列目にプロパティ用のボタンを設定.
    QPushButton *button = new QPushButton();
    button->setText("詳細");
    connect(button, SIGNAL(clicked()), this, SLOT(on_propertyButton_clicked()));
    // 構造体に個人データを保存.
    struct member_data memdata;
    memdata.pro_button = button;
    memdata.property = pro;
    for(int i=0; i<31; i++){
        memdata.shift[i] = ((shift != nullptr) ? shift[i] : NON_SHIFT_DAY);
    }
//    for(int i=0; i<3; i++){
//        shift_num[i] = pro.shift_num[i];
//    }
    shift_num = pro.shift_num;
    // 構造体をリストに保存.
    ST_memdata_list.append(memdata);
    set_holiday_list(row_count-1);
    update_calendar();
}

// 1行削除する処理
void Shift_Calendar::delete_line()
{
    dialog->close();
    if(dialog_flag == PROPERTY_BUTTON){ // 詳細ボタンのダイアログから削除ボタンを押した時だけ.
        int row = ui->tableWidget->currentRow();
        ST_memdata_list.remove(row-1);
        header_vertical.remove(row);
        row_count--;
        ui->tableWidget->removeRow(row);
        update_calendar();
    }
}


// 自動入力ボタンが押された際の処理
// shift配列の中身を変える
void Shift_Calendar::on_auto_input_Button_clicked()
{
    int day_idx = 0;
    while(day_idx < 31){
        // ==== もし入れる人数が必須人数以下ならば入れる人は全員出勤にする. ====
        // 入れる人の人数を数える.
        int i = 0;
        int can_shift_num = 0;          // 休暇日の人数
        int shift_on_num[3] = {0};      // 各シフト時間別の入っている人数
        while(++i < row_count){ // 出勤できる人数を数える.
            int shift_time = ST_memdata_list[i-1].shift[day_idx];
            switch (shift_time) {
                case SHIFT_LINE_1:
                    shift_on_num[0]++;
                    break;
//                case SHIFT_LINE_2:
//                    shift_on_num[1]++;
//                    break;
//                case SHIFT_LINE_3:
//                    shift_on_num[2]++;
//                    break;
                case NON_SHIFT_DAY:
                    can_shift_num++;
                    break;
                default:
                    break;
            }
        }
        /// 以下勤務時間1のみ実装
        // 人数が足りない時は休暇希望の人以外出勤.
        if(can_shift_num + shift_on_num[0] <= shift_num){
            for(int i=0; i < row_count-1; i++){
                if(ST_memdata_list[i].shift[day_idx] != HORYDAY && ST_memdata_list[i].property.shift_time){
                    ST_memdata_list[i].shift[day_idx] = SHIFT_LINE_1;
                }
            }
        }else{  // 人数が足りている場合は差分だけ出勤.
            int dif_num = shift_num - shift_on_num[0];   // 追加で必要な人数 = 必要人数 - すでに入っている人数.
            // まず前後の日が休みなら出勤
            for(int i=0; i<row_count-1; i++){
                if(dif_num == 0){
                    break;
                }
                if(0 < day_idx && day_idx < 31-1){
                    bool tmp1 = ST_memdata_list[i].shift[day_idx-1] == NON_SHIFT_DAY || ST_memdata_list[i].shift[day_idx-1] == HORYDAY;
                    bool tmp2 = ST_memdata_list[i].shift[day_idx+1] == NON_SHIFT_DAY || ST_memdata_list[i].shift[day_idx+1] == HORYDAY;
                    if( tmp1 && tmp2){
                        if(ST_memdata_list[i].shift[day_idx] != SHIFT_LINE_1){
                            ST_memdata_list[i].shift[day_idx] = SHIFT_LINE_1;
                            dif_num--;
                        }
                    }
                }else if( 0 == day_idx ){
                    if(ST_memdata_list[i].shift[day_idx+1] == NON_SHIFT_DAY){
                        if(ST_memdata_list[i].shift[day_idx] != SHIFT_LINE_1){
                            ST_memdata_list[i].shift[day_idx] = SHIFT_LINE_1;
                            dif_num--;
                        }
                    }
                }else{
                    if(ST_memdata_list[i].shift[day_idx-1] == NON_SHIFT_DAY){
                        if(ST_memdata_list[i].shift[day_idx] != SHIFT_LINE_1){
                            ST_memdata_list[i].shift[day_idx] = SHIFT_LINE_1;
                            dif_num--;
                        }
                    }
                }
            }
            // 残りは完全ランダム
            while(0 < dif_num){
                int rand = QRandomGenerator::system()->generate()%(row_count-1);
                if(ST_memdata_list[rand].shift[day_idx] == NON_SHIFT_DAY){
                    ST_memdata_list[rand].shift[day_idx] = SHIFT_LINE_1;
                    dif_num--;
                }
            }
        }
        day_idx++;
    }
    update_calendar();
}

// シフトの固定出勤曜日が設定されている場合に反映.
void Shift_Calendar::set_shift_dow(int row)
{
    // 年月の取得.
    int year = ui->year_Box->value();
    QString month_string = ui->month_Box->currentText();
    int month = month_string.toInt();
    // 対象人物のデータ(構造体)を取得.
    struct PropertyDialog::MEMBER_PROPERTY pro = ST_memdata_list[row-1].property;
    // ==== 固定出勤曜日が設定されている場合 ====
    bool is_set_dow = false;
    for(int i=0; i<7; i++){
        if(pro.go_dow[i]){
            is_set_dow = true;
        }
    }
    // 設定されている場合.
    if(is_set_dow){
        // 出勤曜日なら出勤を、違うならシフト無し日or休暇日を設定.
        for(int i=0; i<31; i++){
            QDate current_day(year, month, i+1);
            int j = current_day.dayOfWeek();
            if(pro.go_dow[j-1]){
                if(pro.shift_time){
                    ST_memdata_list[row-1].shift[i] = SHIFT_LINE_1;
//                }else if(pro.shift_time[1]){
//                    ST_memdata_list[row-1].shift[i] = SHIFT_LINE_2;
//                }else if(pro.shift_time[2]){
//                    ST_memdata_list[row-1].shift[i] = SHIFT_LINE_3;
                }else{}
            }else{
                if(pro.other_dow){
                    ST_memdata_list[row-1].shift[i] = HORYDAY;
                }else{
                    ST_memdata_list[row-1].shift[i] = NON_SHIFT_DAY;
                }
            }
        }
    }
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
    int idx = 0;    // 文字から読み取った数値
    // 数字以外の文字で区切り、入力された日付を記録.
    for(int i = 0; i < holiday.length(); i++){
        if(holiday[i].isNumber()){
            idx = idx*10 + holiday[i].digitValue();
        }else{
            if(1 <= idx && idx <= 31){
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
        }
    }

}

// 更新ボタンが押された時.
// 現在表示されている内容に内部データを書き換える(shift配列の中身のみ).
void Shift_Calendar::on_update_button_clicked()
{
    for (int row = 1; row < row_count; row++){
        for(int column = 1; column < ui->tableWidget->columnCount(); column++){
            // 列ラベルから日付を取得.
            int num_day = ui->tableWidget->horizontalHeaderItem(column)->text().toInt();
            // 該当セルの表示テキストを取得.
            QString cell_text = ui->tableWidget->item(row, column)->text();
            // ==== 表示テキストに合わせて内部データ(shift[])を変更 ====
            // 数字ならそのまま数値を入れる.
            bool is_num;
            int shift_time = cell_text.toInt(&is_num);
            if(is_num){
                ST_memdata_list[row-1].shift[num_day-1] = shift_time;
                return;
            }
            // 文字列ならそれに対応した数値を入れる.定義されていなければ休暇日"/"とする.
            if(cell_text == "/"){
                ST_memdata_list[row-1].shift[num_day-1] = NON_SHIFT_DAY;
            }else if(cell_text == "//"){
                ST_memdata_list[row-1].shift[num_day-1] = HORYDAY;
            }else if(cell_text == shift_time_str[0]){
                ST_memdata_list[row-1].shift[num_day-1] = SHIFT_LINE_1;
//            }else if(cell_text == shift_time_str[1]){
//                ST_memdata_list[row-1].shift[num_day-1] = SHIFT_LINE_2;
//            }else if(cell_text == shift_time_str[2]){
//                ST_memdata_list[row-1].shift[num_day-1] = SHIFT_LINE_3;
            }else{
                ST_memdata_list[row-1].shift[num_day-1] = NON_SHIFT_DAY;    // ここ要考察
            }
        }
    }
    // 代入が間違ってないことを確認するための再度画面更新.
    update_calendar();
}

// 保存ボタンを押した際の動作.
// 必要な情報を外部ファイルに保存する.
/*
 * 保存データの詳細
 * ・全体情報(ファイル名:shift_app_maindata)
 * shift_time_str(QString[3])   シフト時間、空白区切りで
 * shift_num(int[3])        シフト必要人数、空白区切りで
 * row_count(int)           登録人数
 *
 * ・個人データ(ファイル名:[番号]data) ここの番号はテーブル上に表示される順番と同じ(上から0,1,...)
 * name(QString)        登録名
 * go_dow(bool[7])      固定出勤曜日T/F
 * shift_time(bool[3])  シフト時間の出勤の有無
 * year month shift[31] 前回保存した際の 年 月 シフト状況　を空白区切りで
*/
void Shift_Calendar::save_data()
{
    // ディレクトリの確認, 無ければ作成.
    QDir dir("data");
    if(!dir.exists()){
        QDir newdir("");
        if(!newdir.mkdir("data")){
            qDebug() << "cant mkdir";
        }
    }
    // 全体で必要な情報の保存
    QString file_name_whole = "./data/shift_app_maindata";
    QFile file(file_name_whole);
    if(!file.open(QIODevice::WriteOnly)) {
        error_msg("cant file open");
        return;
    }
    QTextStream out(&file);
//    out << shift_time_str[0] << " " << shift_time_str[1] << " " << shift_time_str[2] << "\n";
    out << shift_time_str << "\n";
//    out << shift_num[0] << " " << shift_num[1] << " " << shift_num[2] << "\n";
    out << shift_num << "\n";
    out << row_count-1 << "\n";
    file.close();
    // 個人データの保存
    for(int i=1; i<row_count; i++){
        QString file_name_per = "./data/" + QString::number(i-1) + "data";
        QFile file(file_name_per);
        if(!file.open(QIODevice::WriteOnly)) {
            error_msg("cant file open");
            return;
        }
        QTextStream out(&file);
        // 1行目 nameの出力
        out << ST_memdata_list[i-1].property.name << "\n";
        // 2行目 go_dowの出力
        for(int j=0; j<7; j++){
            out << (ST_memdata_list[i-1].property.go_dow[j] ? 1 : 0);
        }
        out << "\n";
        // 3行目 shift_timeの出力
//        for(int j=0; j<3; j++){
//            out << (ST_memdata_list[i-1].property.shift_time[j] ? 1 : 0);
//        }
        out << (ST_memdata_list[i-1].property.shift_time ? 1 : 0);
        out << "\n";
        // 4行目 shift[31]の出力
        int year = ui->year_Box->value();
        QString month_string = ui->month_Box->currentText();
        int month = month_string.toInt();
        out << year << " " << month;
        for(int k=0; k<31; k++){
            out << " " << ST_memdata_list[i-1].shift[k];
        }
        out << "\n";
        file.close();
    }
    qDebug() << "success save";
}

void Shift_Calendar::load_data()
{
    // ディレクトリの確認
    QString strDir = "./data/";
    QDir dir(strDir);
    if(!dir.exists()){
        return;
    }
    // ==== 全体情報の読み込み ====
    QString file_name_whole = "./data/shift_app_maindata";
    QFile file(file_name_whole);
    if(!file.open(QIODevice::ReadOnly)) {
        error_msg("cant file open maindata");
        return;
    }
    QTextStream in(&file);
    // 1行目 shift_time_strの読み込み.
    QString read_line = in.readLine();
    QStringList read_shift_time_str = read_line.split(" ");
    // 2行目 shift_numの読み込み.
    read_line = in.readLine();
    QStringList read_shift_num = read_line.split(" ");
    // 3行目 登録人数の読み込み.
    read_line = in.readLine();
    int num = read_line.toInt();
    // 読み込んだ情報の登録.
//    for(int i=0; i<3; i++){
//        shift_time_str[i] = read_shift_time_str[i];
//        shift_num[i] = read_shift_num[i].toInt();
//    }
    shift_time_str = read_shift_time_str.first();
    shift_num = read_shift_num.first().toInt();
    file.close();
    // ==== 個人データの読み込み ====
    for(int i=0; i<num; i++){
        QString file_name_per = "./data/" + QString::number(i) + "data";
        QFile file(file_name_per);
        if(!file.open(QIODevice::ReadOnly)) {
            error_msg("cant file open perdata");
            continue;
        }
        QTextStream in(&file);
        int load_shift[31];
        struct PropertyDialog::MEMBER_PROPERTY load_pro;
        // 1行目 nameの読み込み.
        load_pro.name = in.readLine();
        // 2行目 go_dowの読み込み.
        read_line = in.readLine();
        for(int i=0; i<7; i++){
            load_pro.go_dow[i] = (read_line[i] == '1' ? true : false);
        }
        // 3行目 shift_timeの読み込み.
        read_line = in.readLine();
//        for(int i=0; i<3; i++){
//            load_pro.shift_time[i] = (read_line[i] == '1' ? true : false);
//        }
        load_pro.shift_time = (read_line == '1' ? true : false);
        // 4行目 year month shift[31]の読み込み
        read_line = in.readLine();
        QStringList read_shift_line = read_line.split(" ");
        ui->year_Box->setValue(read_shift_line[0].toInt());
        ui->month_Box->setCurrentIndex(read_shift_line[1].toInt()-1);
        for(int i = 2; i < read_shift_line.size(); i++){
            load_shift[i-2] = read_shift_line[i].toInt();
        }
        // 読み込んだ情報の登録.
        dialog->set_property(shift_num, shift_time_str, &load_pro);
        add_line(load_shift);
        file.close();
    }
}

void Shift_Calendar::on_save_Button_clicked()
{
    save_data();
}

