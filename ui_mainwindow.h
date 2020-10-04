/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *start_page;
    QPushButton *start_game;
    QLabel *movie_lable;
    QPushButton *exit_game;
    QWidget *main_page;
    QLCDNumber *lcdNumber;
    QLabel *check_label_left;
    QLabel *check_label_up;
    QLabel *check_label_down;
    QLabel *check_label_right;
    QLabel *perfect_lable;
    QLabel *main_back_label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 1031);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 1001));
        start_page = new QWidget();
        start_page->setObjectName(QStringLiteral("start_page"));
        start_game = new QPushButton(start_page);
        start_game->setObjectName(QStringLiteral("start_game"));
        start_game->setGeometry(QRect(275, 350, 250, 50));
        movie_lable = new QLabel(start_page);
        movie_lable->setObjectName(QStringLiteral("movie_lable"));
        movie_lable->setGeometry(QRect(0, 0, 800, 1000));
        exit_game = new QPushButton(start_page);
        exit_game->setObjectName(QStringLiteral("exit_game"));
        exit_game->setGeometry(QRect(275, 500, 250, 50));
        stackedWidget->addWidget(start_page);
        main_page = new QWidget();
        main_page->setObjectName(QStringLiteral("main_page"));
        lcdNumber = new QLCDNumber(main_page);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(10, 20, 181, 71));
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        check_label_left = new QLabel(main_page);
        check_label_left->setObjectName(QStringLiteral("check_label_left"));
        check_label_left->setGeometry(QRect(0, 900, 200, 100));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        check_label_left->setFont(font);
        check_label_left->setAlignment(Qt::AlignCenter);
        check_label_up = new QLabel(main_page);
        check_label_up->setObjectName(QStringLiteral("check_label_up"));
        check_label_up->setGeometry(QRect(200, 900, 200, 100));
        check_label_up->setFont(font);
        check_label_up->setAlignment(Qt::AlignCenter);
        check_label_down = new QLabel(main_page);
        check_label_down->setObjectName(QStringLiteral("check_label_down"));
        check_label_down->setGeometry(QRect(400, 900, 200, 100));
        check_label_down->setFont(font);
        check_label_down->setAlignment(Qt::AlignCenter);
        check_label_right = new QLabel(main_page);
        check_label_right->setObjectName(QStringLiteral("check_label_right"));
        check_label_right->setGeometry(QRect(600, 900, 200, 100));
        check_label_right->setFont(font);
        check_label_right->setAlignment(Qt::AlignCenter);
        perfect_lable = new QLabel(main_page);
        perfect_lable->setObjectName(QStringLiteral("perfect_lable"));
        perfect_lable->setGeometry(QRect(212, 23, 341, 61));
        perfect_lable->setFont(font);
        perfect_lable->setAlignment(Qt::AlignCenter);
        main_back_label = new QLabel(main_page);
        main_back_label->setObjectName(QStringLiteral("main_back_label"));
        main_back_label->setGeometry(QRect(0, 0, 800, 1000));
        stackedWidget->addWidget(main_page);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        start_game->setText(QString());
        movie_lable->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        exit_game->setText(QString());
        check_label_left->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        check_label_up->setText(QString());
        check_label_down->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        check_label_right->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        perfect_lable->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        main_back_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
