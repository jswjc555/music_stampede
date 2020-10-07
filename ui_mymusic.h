/********************************************************************************
** Form generated from reading UI file 'mymusic.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMUSIC_H
#define UI_MYMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMusic
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *perfect_lable;
    QLCDNumber *lcdNumber;
    QLabel *main_back;
    QLabel *bar_label;
    QLabel *left_gif;
    QLabel *up_gif;
    QLabel *down_gif;
    QLabel *right_gif;
    QLabel *down_cover;
    QLabel *up_dis;
    QLabel *left_dis;
    QLabel *down_dis;
    QLabel *right_dis;
    QWidget *page_2;
    QLabel *check_label_right;
    QLabel *check_label_left;
    QLabel *check_label_up;
    QLabel *check_label_down;

    void setupUi(QWidget *MyMusic)
    {
        if (MyMusic->objectName().isEmpty())
            MyMusic->setObjectName(QStringLiteral("MyMusic"));
        MyMusic->resize(850, 800);
        stackedWidget = new QStackedWidget(MyMusic);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 850, 800));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        perfect_lable = new QLabel(page);
        perfect_lable->setObjectName(QStringLiteral("perfect_lable"));
        perfect_lable->setGeometry(QRect(610, 100, 181, 61));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        perfect_lable->setFont(font);
        perfect_lable->setAlignment(Qt::AlignCenter);
        lcdNumber = new QLCDNumber(page);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(600, 20, 181, 71));
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        main_back = new QLabel(page);
        main_back->setObjectName(QStringLiteral("main_back"));
        main_back->setGeometry(QRect(0, 0, 560, 800));
        bar_label = new QLabel(page);
        bar_label->setObjectName(QStringLiteral("bar_label"));
        bar_label->setGeometry(QRect(0, 484, 560, 190));
        left_gif = new QLabel(page);
        left_gif->setObjectName(QStringLiteral("left_gif"));
        left_gif->setGeometry(QRect(0, 429, 140, 70));
        up_gif = new QLabel(page);
        up_gif->setObjectName(QStringLiteral("up_gif"));
        up_gif->setGeometry(QRect(140, 429, 140, 70));
        down_gif = new QLabel(page);
        down_gif->setObjectName(QStringLiteral("down_gif"));
        down_gif->setGeometry(QRect(280, 429, 140, 70));
        right_gif = new QLabel(page);
        right_gif->setObjectName(QStringLiteral("right_gif"));
        right_gif->setGeometry(QRect(420, 429, 140, 70));
        down_cover = new QLabel(page);
        down_cover->setObjectName(QStringLiteral("down_cover"));
        down_cover->setGeometry(QRect(0, 575, 560, 245));
        up_dis = new QLabel(page);
        up_dis->setObjectName(QStringLiteral("up_dis"));
        up_dis->setGeometry(QRect(152, 576, 120, 120));
        left_dis = new QLabel(page);
        left_dis->setObjectName(QStringLiteral("left_dis"));
        left_dis->setGeometry(QRect(16, 576, 120, 120));
        down_dis = new QLabel(page);
        down_dis->setObjectName(QStringLiteral("down_dis"));
        down_dis->setGeometry(QRect(288, 576, 120, 120));
        right_dis = new QLabel(page);
        right_dis->setObjectName(QStringLiteral("right_dis"));
        right_dis->setGeometry(QRect(424, 576, 120, 120));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        check_label_right = new QLabel(MyMusic);
        check_label_right->setObjectName(QStringLiteral("check_label_right"));
        check_label_right->setGeometry(QRect(420, 637, 140, 180));
        check_label_right->setFont(font);
        check_label_right->setAlignment(Qt::AlignCenter);
        check_label_left = new QLabel(MyMusic);
        check_label_left->setObjectName(QStringLiteral("check_label_left"));
        check_label_left->setGeometry(QRect(0, 637, 140, 180));
        check_label_left->setFont(font);
        check_label_left->setAlignment(Qt::AlignCenter);
        check_label_up = new QLabel(MyMusic);
        check_label_up->setObjectName(QStringLiteral("check_label_up"));
        check_label_up->setGeometry(QRect(140, 637, 140, 180));
        check_label_up->setFont(font);
        check_label_up->setAlignment(Qt::AlignCenter);
        check_label_down = new QLabel(MyMusic);
        check_label_down->setObjectName(QStringLiteral("check_label_down"));
        check_label_down->setGeometry(QRect(280, 637, 140, 180));
        check_label_down->setFont(font);
        check_label_down->setAlignment(Qt::AlignCenter);

        retranslateUi(MyMusic);

        QMetaObject::connectSlotsByName(MyMusic);
    } // setupUi

    void retranslateUi(QWidget *MyMusic)
    {
        MyMusic->setWindowTitle(QApplication::translate("MyMusic", "Form", Q_NULLPTR));
        perfect_lable->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        main_back->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        bar_label->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        left_gif->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        up_gif->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        down_gif->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        right_gif->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        down_cover->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        up_dis->setText(QString());
        left_dis->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        down_dis->setText(QString());
        right_dis->setText(QString());
        check_label_right->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        check_label_left->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        check_label_up->setText(QString());
        check_label_down->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyMusic: public Ui_MyMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMUSIC_H
