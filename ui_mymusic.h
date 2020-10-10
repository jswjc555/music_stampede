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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMusic
{
public:
    QStackedWidget *stackedWidget;
    QWidget *play_page;
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
    QPushButton *stop_button;
    QLabel *pattern_label;
    QLabel *combo_left;
    QLabel *combo_right;
    QLabel *cheng_label;
    QLabel *check_label_right;
    QLabel *check_label_left;
    QLabel *check_label_up;
    QLabel *check_label_down;
    QProgressBar *HP;
    QLabel *right_right_label;
    QLabel *menlian_label;
    QWidget *end_page;
    QLabel *end_label;
    QPushButton *end_close;
    QPushButton *to_main;
    QWidget *qiege_page;
    QLabel *background;
    QLabel *dianbo;

    void setupUi(QWidget *MyMusic)
    {
        if (MyMusic->objectName().isEmpty())
            MyMusic->setObjectName(QStringLiteral("MyMusic"));
        MyMusic->resize(850, 800);
        stackedWidget = new QStackedWidget(MyMusic);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 850, 800));
        play_page = new QWidget();
        play_page->setObjectName(QStringLiteral("play_page"));
        perfect_lable = new QLabel(play_page);
        perfect_lable->setObjectName(QStringLiteral("perfect_lable"));
        perfect_lable->setGeometry(QRect(610, 460, 201, 91));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        perfect_lable->setFont(font);
        perfect_lable->setAlignment(Qt::AlignCenter);
        lcdNumber = new QLCDNumber(play_page);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(620, 160, 181, 71));
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        main_back = new QLabel(play_page);
        main_back->setObjectName(QStringLiteral("main_back"));
        main_back->setGeometry(QRect(0, 0, 560, 800));
        bar_label = new QLabel(play_page);
        bar_label->setObjectName(QStringLiteral("bar_label"));
        bar_label->setGeometry(QRect(0, 484, 560, 190));
        left_gif = new QLabel(play_page);
        left_gif->setObjectName(QStringLiteral("left_gif"));
        left_gif->setGeometry(QRect(0, 429, 140, 70));
        up_gif = new QLabel(play_page);
        up_gif->setObjectName(QStringLiteral("up_gif"));
        up_gif->setGeometry(QRect(140, 429, 140, 70));
        down_gif = new QLabel(play_page);
        down_gif->setObjectName(QStringLiteral("down_gif"));
        down_gif->setGeometry(QRect(280, 429, 140, 70));
        right_gif = new QLabel(play_page);
        right_gif->setObjectName(QStringLiteral("right_gif"));
        right_gif->setGeometry(QRect(420, 429, 140, 70));
        down_cover = new QLabel(play_page);
        down_cover->setObjectName(QStringLiteral("down_cover"));
        down_cover->setGeometry(QRect(0, 575, 560, 245));
        up_dis = new QLabel(play_page);
        up_dis->setObjectName(QStringLiteral("up_dis"));
        up_dis->setGeometry(QRect(152, 576, 120, 120));
        left_dis = new QLabel(play_page);
        left_dis->setObjectName(QStringLiteral("left_dis"));
        left_dis->setGeometry(QRect(16, 576, 120, 120));
        down_dis = new QLabel(play_page);
        down_dis->setObjectName(QStringLiteral("down_dis"));
        down_dis->setGeometry(QRect(288, 576, 120, 120));
        right_dis = new QLabel(play_page);
        right_dis->setObjectName(QStringLiteral("right_dis"));
        right_dis->setGeometry(QRect(424, 576, 120, 120));
        stop_button = new QPushButton(play_page);
        stop_button->setObjectName(QStringLiteral("stop_button"));
        stop_button->setGeometry(QRect(630, 630, 121, 121));
        pattern_label = new QLabel(play_page);
        pattern_label->setObjectName(QStringLiteral("pattern_label"));
        pattern_label->setGeometry(QRect(640, 0, 121, 121));
        combo_left = new QLabel(play_page);
        combo_left->setObjectName(QStringLiteral("combo_left"));
        combo_left->setGeometry(QRect(690, 310, 51, 51));
        combo_right = new QLabel(play_page);
        combo_right->setObjectName(QStringLiteral("combo_right"));
        combo_right->setGeometry(QRect(750, 310, 51, 51));
        cheng_label = new QLabel(play_page);
        cheng_label->setObjectName(QStringLiteral("cheng_label"));
        cheng_label->setGeometry(QRect(630, 310, 51, 51));
        check_label_right = new QLabel(play_page);
        check_label_right->setObjectName(QStringLiteral("check_label_right"));
        check_label_right->setGeometry(QRect(420, 637, 140, 180));
        check_label_right->setFont(font);
        check_label_right->setAlignment(Qt::AlignCenter);
        check_label_left = new QLabel(play_page);
        check_label_left->setObjectName(QStringLiteral("check_label_left"));
        check_label_left->setGeometry(QRect(0, 637, 140, 180));
        check_label_left->setFont(font);
        check_label_left->setAlignment(Qt::AlignCenter);
        check_label_up = new QLabel(play_page);
        check_label_up->setObjectName(QStringLiteral("check_label_up"));
        check_label_up->setGeometry(QRect(140, 637, 140, 180));
        check_label_up->setFont(font);
        check_label_up->setAlignment(Qt::AlignCenter);
        check_label_down = new QLabel(play_page);
        check_label_down->setObjectName(QStringLiteral("check_label_down"));
        check_label_down->setGeometry(QRect(280, 637, 140, 180));
        check_label_down->setFont(font);
        check_label_down->setAlignment(Qt::AlignCenter);
        HP = new QProgressBar(play_page);
        HP->setObjectName(QStringLiteral("HP"));
        HP->setGeometry(QRect(603, 472, 221, 21));
        HP->setStyleSheet(QLatin1String("\n"
"QProgressBar {\n"
"   border: 2px solid grey;\n"
"   border-radius: 5px;\n"
"   background-color: white;\n"
"}\n"
" \n"
"QProgressBar::chunk {\n"
"   background-color: red;\n"
"   width: 20px;\n"
"}\n"
" \n"
"QProgressBar {\n"
"   border: 2px solid grey;\n"
"   border-radius: 5px;\n"
"   text-align: center;\n"
"}"));
        HP->setMinimum(-10);
        HP->setValue(100);
        HP->setTextDirection(QProgressBar::TopToBottom);
        right_right_label = new QLabel(play_page);
        right_right_label->setObjectName(QStringLiteral("right_right_label"));
        right_right_label->setGeometry(QRect(560, 0, 290, 800));
        menlian_label = new QLabel(play_page);
        menlian_label->setObjectName(QStringLiteral("menlian_label"));
        menlian_label->setGeometry(QRect(0, 0, 560, 240));
        stackedWidget->addWidget(play_page);
        end_page = new QWidget();
        end_page->setObjectName(QStringLiteral("end_page"));
        end_label = new QLabel(end_page);
        end_label->setObjectName(QStringLiteral("end_label"));
        end_label->setGeometry(QRect(290, 100, 271, 281));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(48);
        end_label->setFont(font1);
        end_label->setAlignment(Qt::AlignCenter);
        end_close = new QPushButton(end_page);
        end_close->setObjectName(QStringLiteral("end_close"));
        end_close->setGeometry(QRect(300, 560, 250, 50));
        to_main = new QPushButton(end_page);
        to_main->setObjectName(QStringLiteral("to_main"));
        to_main->setGeometry(QRect(302, 457, 251, 51));
        stackedWidget->addWidget(end_page);
        qiege_page = new QWidget();
        qiege_page->setObjectName(QStringLiteral("qiege_page"));
        background = new QLabel(qiege_page);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(1, 4, 851, 801));
        background->setStyleSheet(QStringLiteral("background-color:rgb(0,0,0);"));
        dianbo = new QLabel(qiege_page);
        dianbo->setObjectName(QStringLiteral("dianbo"));
        dianbo->setGeometry(QRect(0, 380, 841, 171));
        stackedWidget->addWidget(qiege_page);

        retranslateUi(MyMusic);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyMusic);
    } // setupUi

    void retranslateUi(QWidget *MyMusic)
    {
        MyMusic->setWindowTitle(QApplication::translate("MyMusic", "Form", Q_NULLPTR));
        perfect_lable->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        main_back->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        bar_label->setText(QString());
        left_gif->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        up_gif->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        down_gif->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        right_gif->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        down_cover->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        up_dis->setText(QString());
        left_dis->setText(QString());
        down_dis->setText(QString());
        right_dis->setText(QString());
        stop_button->setText(QString());
        pattern_label->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        combo_left->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        combo_right->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        cheng_label->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        check_label_right->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        check_label_left->setText(QString());
        check_label_up->setText(QString());
        check_label_down->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        HP->setFormat(QString());
        right_right_label->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        menlian_label->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
        end_label->setText(QApplication::translate("MyMusic", "<html><head/><body><p align=\"center\">\347\273\223\346\235\237</p></body></html>", Q_NULLPTR));
        end_close->setText(QApplication::translate("MyMusic", "\345\205\263\351\227\255\346\270\270\346\210\217", Q_NULLPTR));
        to_main->setText(QApplication::translate("MyMusic", "\345\233\236\345\210\260\344\270\273\347\252\227\345\217\243", Q_NULLPTR));
        background->setText(QString());
        dianbo->setText(QApplication::translate("MyMusic", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyMusic: public Ui_MyMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMUSIC_H
