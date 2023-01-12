/********************************************************************************
** Form generated from reading UI file 'propertydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTYDIALOG_H
#define UI_PROPERTYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PropertyDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QCheckBox *shift_time_checkbox_1;
    QCheckBox *shift_time_checkbox_2;
    QSpacerItem *verticalSpacer;
    QLineEdit *shift_time_line_2;
    QLineEdit *shift_time_line_1;
    QLineEdit *shift_time_line_3;
    QCheckBox *shift_time_checkbox_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QSpinBox *shift_num_box_1;
    QSpinBox *shift_num_box_2;
    QSpinBox *shift_num_box_3;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *name_line;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *thu_check;
    QCheckBox *fri_check;
    QCheckBox *sun_check;
    QCheckBox *sat_check;
    QCheckBox *wed_check;
    QCheckBox *mon_check;
    QCheckBox *tue_check;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *holiday_line;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PropertyDialog)
    {
        if (PropertyDialog->objectName().isEmpty())
            PropertyDialog->setObjectName(QString::fromUtf8("PropertyDialog"));
        PropertyDialog->resize(621, 344);
        horizontalLayout_4 = new QHBoxLayout(PropertyDialog);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(PropertyDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(14);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        shift_time_checkbox_1 = new QCheckBox(PropertyDialog);
        shift_time_checkbox_1->setObjectName(QString::fromUtf8("shift_time_checkbox_1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shift_time_checkbox_1->sizePolicy().hasHeightForWidth());
        shift_time_checkbox_1->setSizePolicy(sizePolicy);
        shift_time_checkbox_1->setBaseSize(QSize(0, 0));
        shift_time_checkbox_1->setTabletTracking(false);
        shift_time_checkbox_1->setIconSize(QSize(15, 15));

        gridLayout->addWidget(shift_time_checkbox_1, 1, 1, 1, 1);

        shift_time_checkbox_2 = new QCheckBox(PropertyDialog);
        shift_time_checkbox_2->setObjectName(QString::fromUtf8("shift_time_checkbox_2"));
        sizePolicy.setHeightForWidth(shift_time_checkbox_2->sizePolicy().hasHeightForWidth());
        shift_time_checkbox_2->setSizePolicy(sizePolicy);
        shift_time_checkbox_2->setBaseSize(QSize(0, 0));
        shift_time_checkbox_2->setTabletTracking(false);
        shift_time_checkbox_2->setIconSize(QSize(15, 15));

        gridLayout->addWidget(shift_time_checkbox_2, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        shift_time_line_2 = new QLineEdit(PropertyDialog);
        shift_time_line_2->setObjectName(QString::fromUtf8("shift_time_line_2"));
        QFont font1;
        font1.setPointSize(11);
        shift_time_line_2->setFont(font1);
        shift_time_line_2->setFrame(false);

        gridLayout->addWidget(shift_time_line_2, 2, 0, 1, 1);

        shift_time_line_1 = new QLineEdit(PropertyDialog);
        shift_time_line_1->setObjectName(QString::fromUtf8("shift_time_line_1"));
        shift_time_line_1->setFont(font1);
        shift_time_line_1->setFrame(false);

        gridLayout->addWidget(shift_time_line_1, 1, 0, 1, 1);

        shift_time_line_3 = new QLineEdit(PropertyDialog);
        shift_time_line_3->setObjectName(QString::fromUtf8("shift_time_line_3"));
        shift_time_line_3->setFont(font1);
        shift_time_line_3->setFrame(false);

        gridLayout->addWidget(shift_time_line_3, 3, 0, 1, 1);

        shift_time_checkbox_3 = new QCheckBox(PropertyDialog);
        shift_time_checkbox_3->setObjectName(QString::fromUtf8("shift_time_checkbox_3"));
        sizePolicy.setHeightForWidth(shift_time_checkbox_3->sizePolicy().hasHeightForWidth());
        shift_time_checkbox_3->setSizePolicy(sizePolicy);
        shift_time_checkbox_3->setBaseSize(QSize(0, 0));
        shift_time_checkbox_3->setTabletTracking(false);
        shift_time_checkbox_3->setIconSize(QSize(15, 15));

        gridLayout->addWidget(shift_time_checkbox_3, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        label_5 = new QLabel(PropertyDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        shift_num_box_1 = new QSpinBox(PropertyDialog);
        shift_num_box_1->setObjectName(QString::fromUtf8("shift_num_box_1"));
        shift_num_box_1->setValue(3);

        gridLayout->addWidget(shift_num_box_1, 1, 2, 1, 1);

        shift_num_box_2 = new QSpinBox(PropertyDialog);
        shift_num_box_2->setObjectName(QString::fromUtf8("shift_num_box_2"));

        gridLayout->addWidget(shift_num_box_2, 2, 2, 1, 1);

        shift_num_box_3 = new QSpinBox(PropertyDialog);
        shift_num_box_3->setObjectName(QString::fromUtf8("shift_num_box_3"));

        gridLayout->addWidget(shift_num_box_3, 3, 2, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        line_3 = new QFrame(PropertyDialog);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(PropertyDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        name_line = new QLineEdit(PropertyDialog);
        name_line->setObjectName(QString::fromUtf8("name_line"));
        name_line->setFont(font1);

        horizontalLayout->addWidget(name_line);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line = new QFrame(PropertyDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_2 = new QLabel(PropertyDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(false);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        thu_check = new QCheckBox(PropertyDialog);
        thu_check->setObjectName(QString::fromUtf8("thu_check"));
        thu_check->setFont(font1);

        horizontalLayout_2->addWidget(thu_check);

        fri_check = new QCheckBox(PropertyDialog);
        fri_check->setObjectName(QString::fromUtf8("fri_check"));
        fri_check->setFont(font1);

        horizontalLayout_2->addWidget(fri_check);

        sun_check = new QCheckBox(PropertyDialog);
        sun_check->setObjectName(QString::fromUtf8("sun_check"));
        sun_check->setFont(font1);

        horizontalLayout_2->addWidget(sun_check);

        sat_check = new QCheckBox(PropertyDialog);
        sat_check->setObjectName(QString::fromUtf8("sat_check"));
        sat_check->setFont(font1);

        horizontalLayout_2->addWidget(sat_check);

        wed_check = new QCheckBox(PropertyDialog);
        wed_check->setObjectName(QString::fromUtf8("wed_check"));
        wed_check->setFont(font1);

        horizontalLayout_2->addWidget(wed_check);

        mon_check = new QCheckBox(PropertyDialog);
        mon_check->setObjectName(QString::fromUtf8("mon_check"));
        mon_check->setFont(font1);

        horizontalLayout_2->addWidget(mon_check);

        tue_check = new QCheckBox(PropertyDialog);
        tue_check->setObjectName(QString::fromUtf8("tue_check"));
        tue_check->setFont(font1);

        horizontalLayout_2->addWidget(tue_check);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        line_2 = new QFrame(PropertyDialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(PropertyDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        holiday_line = new QLineEdit(PropertyDialog);
        holiday_line->setObjectName(QString::fromUtf8("holiday_line"));
        holiday_line->setFont(font1);

        horizontalLayout_3->addWidget(holiday_line);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        pushButton = new QPushButton(PropertyDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        buttonBox = new QDialogButtonBox(PropertyDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        horizontalLayout_4->addLayout(verticalLayout_2);


        retranslateUi(PropertyDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PropertyDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PropertyDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PropertyDialog);
    } // setupUi

    void retranslateUi(QDialog *PropertyDialog)
    {
        PropertyDialog->setWindowTitle(QCoreApplication::translate("PropertyDialog", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("PropertyDialog", "\345\213\244\345\213\231\346\231\202\351\226\223", nullptr));
        shift_time_checkbox_1->setText(QString());
        shift_time_checkbox_2->setText(QString());
        shift_time_line_2->setText(QCoreApplication::translate("PropertyDialog", "-\346\234\252\345\256\237\350\243\205-", nullptr));
        shift_time_line_1->setText(QCoreApplication::translate("PropertyDialog", "18", nullptr));
        shift_time_line_3->setText(QCoreApplication::translate("PropertyDialog", "-\346\234\252\345\256\237\350\243\205-", nullptr));
        shift_time_checkbox_3->setText(QString());
        label_5->setText(QCoreApplication::translate("PropertyDialog", "\345\277\205\350\246\201\344\272\272\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("PropertyDialog", "\345\220\215\345\211\215", nullptr));
        label_2->setText(QCoreApplication::translate("PropertyDialog", "\345\233\272\345\256\232\343\201\247\345\205\245\343\202\214\343\202\213\346\233\234\346\227\245", nullptr));
        thu_check->setText(QCoreApplication::translate("PropertyDialog", "\346\234\250", nullptr));
        fri_check->setText(QCoreApplication::translate("PropertyDialog", "\351\207\221", nullptr));
        sun_check->setText(QCoreApplication::translate("PropertyDialog", "\346\227\245", nullptr));
        sat_check->setText(QCoreApplication::translate("PropertyDialog", "\345\234\237", nullptr));
        wed_check->setText(QCoreApplication::translate("PropertyDialog", "\346\260\264", nullptr));
        mon_check->setText(QCoreApplication::translate("PropertyDialog", "\346\234\210", nullptr));
        tue_check->setText(QCoreApplication::translate("PropertyDialog", "\347\201\253", nullptr));
        label_3->setText(QCoreApplication::translate("PropertyDialog", "\344\274\221\346\232\207\345\270\214\346\234\233\346\227\245", nullptr));
        pushButton->setText(QCoreApplication::translate("PropertyDialog", "\345\211\212\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PropertyDialog: public Ui_PropertyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTYDIALOG_H
