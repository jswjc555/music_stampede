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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *start_page;
    QPushButton *start_game;
    QLabel *movie_label;
    QPushButton *exit_game;
    QPushButton *challenge;
    QWidget *main_page;

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
        start_game->setGeometry(QRect(150, 300, 250, 50));
        movie_label = new QLabel(start_page);
        movie_label->setObjectName(QStringLiteral("movie_label"));
        movie_label->setGeometry(QRect(0, 0, 800, 1000));
        exit_game = new QPushButton(start_page);
        exit_game->setObjectName(QStringLiteral("exit_game"));
        exit_game->setGeometry(QRect(150, 400, 250, 50));
        challenge = new QPushButton(start_page);
        challenge->setObjectName(QStringLiteral("challenge"));
        challenge->setGeometry(QRect(150, 500, 250, 50));
        stackedWidget->addWidget(start_page);
        main_page = new QWidget();
        main_page->setObjectName(QStringLiteral("main_page"));
        stackedWidget->addWidget(main_page);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        start_game->setText(QString());
        movie_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        exit_game->setText(QString());
        challenge->setText(QApplication::translate("MainWindow", "\346\214\221\346\210\230\346\250\241\345\274\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
