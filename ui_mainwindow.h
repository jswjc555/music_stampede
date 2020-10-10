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
    QPushButton *pushButton;
    QWidget *mode_page;
    QLabel *background_mode;
    QPushButton *mode_normal_button;
    QPushButton *mode_hard_button;
    QPushButton *mode_back_button;
    QLabel *music_choose;
    QPushButton *roll_music_button;
    QPushButton *mode_hp_button;

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
        challenge->setGeometry(QRect(20, 545345, 93, 28));
        pushButton = new QPushButton(start_page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 7657, 93, 28));
        stackedWidget->addWidget(start_page);
        mode_page = new QWidget();
        mode_page->setObjectName(QStringLiteral("mode_page"));
        background_mode = new QLabel(mode_page);
        background_mode->setObjectName(QStringLiteral("background_mode"));
        background_mode->setGeometry(QRect(0, 0, 800, 1000));
        mode_normal_button = new QPushButton(mode_page);
        mode_normal_button->setObjectName(QStringLiteral("mode_normal_button"));
        mode_normal_button->setGeometry(QRect(175, 60, 175, 175));
        mode_hard_button = new QPushButton(mode_page);
        mode_hard_button->setObjectName(QStringLiteral("mode_hard_button"));
        mode_hard_button->setGeometry(QRect(175, 255, 175, 175));
        mode_back_button = new QPushButton(mode_page);
        mode_back_button->setObjectName(QStringLiteral("mode_back_button"));
        mode_back_button->setGeometry(QRect(320, 660, 175, 51));
        music_choose = new QLabel(mode_page);
        music_choose->setObjectName(QStringLiteral("music_choose"));
        music_choose->setGeometry(QRect(360, 410, 161, 61));
        music_choose->setStyleSheet(QStringLiteral("color:rgb(255,255,255)"));
        roll_music_button = new QPushButton(mode_page);
        roll_music_button->setObjectName(QStringLiteral("roll_music_button"));
        roll_music_button->setGeometry(QRect(390, 530, 91, 91));
        mode_hp_button = new QPushButton(mode_page);
        mode_hp_button->setObjectName(QStringLiteral("mode_hp_button"));
        mode_hp_button->setGeometry(QRect(175, 450, 175, 175));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(22);
        mode_hp_button->setFont(font);
        stackedWidget->addWidget(mode_page);
        background_mode->raise();
        mode_normal_button->raise();
        mode_hard_button->raise();
        mode_back_button->raise();
        roll_music_button->raise();
        mode_hp_button->raise();
        music_choose->raise();
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
        challenge->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        background_mode->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        mode_normal_button->setText(QString());
        mode_hard_button->setText(QString());
        mode_back_button->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        music_choose->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">\347\202\271\346\255\214</p></body></html>", Q_NULLPTR));
        roll_music_button->setText(QApplication::translate("MainWindow", "roll", Q_NULLPTR));
        mode_hp_button->setText(QApplication::translate("MainWindow", "HP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
