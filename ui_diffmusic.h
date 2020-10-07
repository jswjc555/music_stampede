/********************************************************************************
** Form generated from reading UI file 'diffmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFMUSIC_H
#define UI_DIFFMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiffMusic
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *perfect_lable;
    QLCDNumber *lcdNumber;
    QLabel *main_back;
    QProgressBar *HD;
    QWidget *page_2;
    QLabel *check_label_up;
    QLabel *check_label_down;
    QLabel *check_label_right;
    QLabel *check_label_left;

    void setupUi(QWidget *DiffMusic)
    {
        if (DiffMusic->objectName().isEmpty())
            DiffMusic->setObjectName(QStringLiteral("DiffMusic"));
        DiffMusic->resize(850, 800);
        stackedWidget = new QStackedWidget(DiffMusic);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 850, 800));
        stackedWidget->setFrameShadow(QFrame::Raised);
        stackedWidget->setLineWidth(1);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        perfect_lable = new QLabel(page);
        perfect_lable->setObjectName(QStringLiteral("perfect_lable"));
        perfect_lable->setGeometry(QRect(620, 90, 181, 61));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        perfect_lable->setFont(font);
        perfect_lable->setAlignment(Qt::AlignCenter);
        lcdNumber = new QLCDNumber(page);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(620, 20, 181, 71));
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        main_back = new QLabel(page);
        main_back->setObjectName(QStringLiteral("main_back"));
        main_back->setGeometry(QRect(0, 0, 560, 800));
        HD = new QProgressBar(page);
        HD->setObjectName(QStringLiteral("HD"));
        HD->setGeometry(QRect(670, 220, 41, 521));
        HD->setStyleSheet(QLatin1String("QProgressBar {   border: 2px solid grey;   border-radius: 5px;   background-color: yellow;}\n"
"\n"
"QProgressBar {   border: 2px solid grey;   border-radius: 5px;   text-align: center;}\n"
"\n"
""));
        HD->setValue(100);
        HD->setOrientation(Qt::Vertical);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        check_label_up = new QLabel(DiffMusic);
        check_label_up->setObjectName(QStringLiteral("check_label_up"));
        check_label_up->setGeometry(QRect(140, 650, 140, 150));
        check_label_up->setFont(font);
        check_label_up->setAlignment(Qt::AlignCenter);
        check_label_down = new QLabel(DiffMusic);
        check_label_down->setObjectName(QStringLiteral("check_label_down"));
        check_label_down->setGeometry(QRect(280, 650, 140, 150));
        check_label_down->setFont(font);
        check_label_down->setAlignment(Qt::AlignCenter);
        check_label_right = new QLabel(DiffMusic);
        check_label_right->setObjectName(QStringLiteral("check_label_right"));
        check_label_right->setGeometry(QRect(420, 650, 140, 150));
        check_label_right->setFont(font);
        check_label_right->setAlignment(Qt::AlignCenter);
        check_label_left = new QLabel(DiffMusic);
        check_label_left->setObjectName(QStringLiteral("check_label_left"));
        check_label_left->setGeometry(QRect(0, 650, 140, 150));
        check_label_left->setFont(font);
        check_label_left->setAlignment(Qt::AlignCenter);

        retranslateUi(DiffMusic);

        QMetaObject::connectSlotsByName(DiffMusic);
    } // setupUi

    void retranslateUi(QWidget *DiffMusic)
    {
        DiffMusic->setWindowTitle(QApplication::translate("DiffMusic", "Form", Q_NULLPTR));
        perfect_lable->setText(QApplication::translate("DiffMusic", "TextLabel", Q_NULLPTR));
        main_back->setText(QApplication::translate("DiffMusic", "TextLabel", Q_NULLPTR));
        check_label_up->setText(QString());
        check_label_down->setText(QApplication::translate("DiffMusic", "TextLabel", Q_NULLPTR));
        check_label_right->setText(QApplication::translate("DiffMusic", "TextLabel", Q_NULLPTR));
        check_label_left->setText(QApplication::translate("DiffMusic", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DiffMusic: public Ui_DiffMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFMUSIC_H
