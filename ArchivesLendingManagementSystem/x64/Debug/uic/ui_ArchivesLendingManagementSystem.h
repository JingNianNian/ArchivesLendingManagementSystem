/********************************************************************************
** Form generated from reading UI file 'ArchivesLendingManagementSystem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCHIVESLENDINGMANAGEMENTSYSTEM_H
#define UI_ARCHIVESLENDINGMANAGEMENTSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArchivesLendingManagementSystemClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ArchivesLendingManagementSystemClass)
    {
        if (ArchivesLendingManagementSystemClass->objectName().isEmpty())
            ArchivesLendingManagementSystemClass->setObjectName(QString::fromUtf8("ArchivesLendingManagementSystemClass"));
        ArchivesLendingManagementSystemClass->resize(600, 400);
        menuBar = new QMenuBar(ArchivesLendingManagementSystemClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ArchivesLendingManagementSystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ArchivesLendingManagementSystemClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ArchivesLendingManagementSystemClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ArchivesLendingManagementSystemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ArchivesLendingManagementSystemClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ArchivesLendingManagementSystemClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ArchivesLendingManagementSystemClass->setStatusBar(statusBar);

        retranslateUi(ArchivesLendingManagementSystemClass);

        QMetaObject::connectSlotsByName(ArchivesLendingManagementSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *ArchivesLendingManagementSystemClass)
    {
        ArchivesLendingManagementSystemClass->setWindowTitle(QCoreApplication::translate("ArchivesLendingManagementSystemClass", "ArchivesLendingManagementSystem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArchivesLendingManagementSystemClass: public Ui_ArchivesLendingManagementSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCHIVESLENDINGMANAGEMENTSYSTEM_H
