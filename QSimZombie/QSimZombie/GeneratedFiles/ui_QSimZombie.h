/********************************************************************************
** Form generated from reading UI file 'QSimZombie.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSIMZOMBIE_H
#define UI_QSIMZOMBIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSimZombieClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QSimZombieClass)
    {
        if (QSimZombieClass->objectName().isEmpty())
            QSimZombieClass->setObjectName(QStringLiteral("QSimZombieClass"));
        QSimZombieClass->resize(600, 400);
        menuBar = new QMenuBar(QSimZombieClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QSimZombieClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QSimZombieClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSimZombieClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QSimZombieClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSimZombieClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QSimZombieClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QSimZombieClass->setStatusBar(statusBar);

        retranslateUi(QSimZombieClass);

        QMetaObject::connectSlotsByName(QSimZombieClass);
    } // setupUi

    void retranslateUi(QMainWindow *QSimZombieClass)
    {
        QSimZombieClass->setWindowTitle(QApplication::translate("QSimZombieClass", "QSimZombie", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QSimZombieClass: public Ui_QSimZombieClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSIMZOMBIE_H
