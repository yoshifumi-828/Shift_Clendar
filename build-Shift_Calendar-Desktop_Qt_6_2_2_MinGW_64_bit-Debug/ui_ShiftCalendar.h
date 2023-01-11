/********************************************************************************
** Form generated from reading UI file 'ShiftCalendar.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHIFTCALENDAR_H
#define UI_SHIFTCALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shift_Calendar
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpinBox *year_Box;
    QComboBox *month_Box;
    QComboBox *display_month_Box;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *save_Button;
    QPushButton *auto_input_Button;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Shift_Calendar)
    {
        if (Shift_Calendar->objectName().isEmpty())
            Shift_Calendar->setObjectName(QString::fromUtf8("Shift_Calendar"));
        Shift_Calendar->resize(640, 640);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Shift_Calendar->sizePolicy().hasHeightForWidth());
        Shift_Calendar->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Shift_Calendar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 10, -1, 10);
        year_Box = new QSpinBox(Shift_Calendar);
        year_Box->setObjectName(QString::fromUtf8("year_Box"));
        year_Box->setMinimum(2023);
        year_Box->setMaximum(2099);

        horizontalLayout->addWidget(year_Box);

        month_Box = new QComboBox(Shift_Calendar);
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->addItem(QString());
        month_Box->setObjectName(QString::fromUtf8("month_Box"));

        horizontalLayout->addWidget(month_Box);

        display_month_Box = new QComboBox(Shift_Calendar);
        display_month_Box->addItem(QString());
        display_month_Box->addItem(QString());
        display_month_Box->addItem(QString());
        display_month_Box->setObjectName(QString::fromUtf8("display_month_Box"));

        horizontalLayout->addWidget(display_month_Box);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(Shift_Calendar);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setBaseSize(QSize(0, 0));
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(32);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(32);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 10, -1, -1);
        pushButton = new QPushButton(Shift_Calendar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        save_Button = new QPushButton(Shift_Calendar);
        save_Button->setObjectName(QString::fromUtf8("save_Button"));

        horizontalLayout_2->addWidget(save_Button);

        auto_input_Button = new QPushButton(Shift_Calendar);
        auto_input_Button->setObjectName(QString::fromUtf8("auto_input_Button"));

        horizontalLayout_2->addWidget(auto_input_Button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Shift_Calendar);

        QMetaObject::connectSlotsByName(Shift_Calendar);
    } // setupUi

    void retranslateUi(QWidget *Shift_Calendar)
    {
        Shift_Calendar->setWindowTitle(QCoreApplication::translate("Shift_Calendar", "Widget", nullptr));
        month_Box->setItemText(0, QCoreApplication::translate("Shift_Calendar", "1", nullptr));
        month_Box->setItemText(1, QCoreApplication::translate("Shift_Calendar", "2", nullptr));
        month_Box->setItemText(2, QCoreApplication::translate("Shift_Calendar", "3", nullptr));
        month_Box->setItemText(3, QCoreApplication::translate("Shift_Calendar", "4", nullptr));
        month_Box->setItemText(4, QCoreApplication::translate("Shift_Calendar", "5", nullptr));
        month_Box->setItemText(5, QCoreApplication::translate("Shift_Calendar", "6", nullptr));
        month_Box->setItemText(6, QCoreApplication::translate("Shift_Calendar", "7", nullptr));
        month_Box->setItemText(7, QCoreApplication::translate("Shift_Calendar", "8", nullptr));
        month_Box->setItemText(8, QCoreApplication::translate("Shift_Calendar", "9", nullptr));
        month_Box->setItemText(9, QCoreApplication::translate("Shift_Calendar", "10", nullptr));
        month_Box->setItemText(10, QCoreApplication::translate("Shift_Calendar", "11", nullptr));
        month_Box->setItemText(11, QCoreApplication::translate("Shift_Calendar", "12", nullptr));

        display_month_Box->setItemText(0, QCoreApplication::translate("Shift_Calendar", "\345\211\215\345\215\212", nullptr));
        display_month_Box->setItemText(1, QCoreApplication::translate("Shift_Calendar", "\345\276\214\345\215\212", nullptr));
        display_month_Box->setItemText(2, QCoreApplication::translate("Shift_Calendar", "\345\205\250\344\275\223", nullptr));

        pushButton->setText(QCoreApplication::translate("Shift_Calendar", "+", nullptr));
        save_Button->setText(QCoreApplication::translate("Shift_Calendar", "\344\277\235\345\255\230", nullptr));
        auto_input_Button->setText(QCoreApplication::translate("Shift_Calendar", "\350\207\252\345\213\225\345\205\245\345\212\233", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shift_Calendar: public Ui_Shift_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHIFTCALENDAR_H
