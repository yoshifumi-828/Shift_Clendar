/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

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

class Ui_Widget
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
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(640, 640);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 20, -1, 20);
        year_Box = new QSpinBox(Widget);
        year_Box->setObjectName(QString::fromUtf8("year_Box"));
        year_Box->setMinimum(2023);
        year_Box->setMaximum(2099);

        horizontalLayout->addWidget(year_Box);

        month_Box = new QComboBox(Widget);
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

        display_month_Box = new QComboBox(Widget);
        display_month_Box->addItem(QString());
        display_month_Box->addItem(QString());
        display_month_Box->addItem(QString());
        display_month_Box->setObjectName(QString::fromUtf8("display_month_Box"));

        horizontalLayout->addWidget(display_month_Box);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(Widget);
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
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        month_Box->setItemText(0, QCoreApplication::translate("Widget", "1", nullptr));
        month_Box->setItemText(1, QCoreApplication::translate("Widget", "2", nullptr));
        month_Box->setItemText(2, QCoreApplication::translate("Widget", "3", nullptr));
        month_Box->setItemText(3, QCoreApplication::translate("Widget", "4", nullptr));
        month_Box->setItemText(4, QCoreApplication::translate("Widget", "5", nullptr));
        month_Box->setItemText(5, QCoreApplication::translate("Widget", "6", nullptr));
        month_Box->setItemText(6, QCoreApplication::translate("Widget", "7", nullptr));
        month_Box->setItemText(7, QCoreApplication::translate("Widget", "8", nullptr));
        month_Box->setItemText(8, QCoreApplication::translate("Widget", "9", nullptr));
        month_Box->setItemText(9, QCoreApplication::translate("Widget", "10", nullptr));
        month_Box->setItemText(10, QCoreApplication::translate("Widget", "11", nullptr));
        month_Box->setItemText(11, QCoreApplication::translate("Widget", "12", nullptr));

        display_month_Box->setItemText(0, QCoreApplication::translate("Widget", "\345\211\215\345\215\212", nullptr));
        display_month_Box->setItemText(1, QCoreApplication::translate("Widget", "\345\276\214\345\215\212", nullptr));
        display_month_Box->setItemText(2, QCoreApplication::translate("Widget", "\345\205\250\344\275\223", nullptr));

        pushButton->setText(QCoreApplication::translate("Widget", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
