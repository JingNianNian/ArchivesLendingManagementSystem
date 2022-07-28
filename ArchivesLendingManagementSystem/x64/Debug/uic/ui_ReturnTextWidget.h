/********************************************************************************
** Form generated from reading UI file 'ReturnTextWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETURNTEXTWIDGET_H
#define UI_RETURNTEXTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReturnTextWidgetClass
{
public:
    QGridLayout *gridLayout;
    QTextEdit *returnText;

    void setupUi(QWidget *ReturnTextWidgetClass)
    {
        if (ReturnTextWidgetClass->objectName().isEmpty())
            ReturnTextWidgetClass->setObjectName(QString::fromUtf8("ReturnTextWidgetClass"));
        ReturnTextWidgetClass->resize(600, 400);
        gridLayout = new QGridLayout(ReturnTextWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        returnText = new QTextEdit(ReturnTextWidgetClass);
        returnText->setObjectName(QString::fromUtf8("returnText"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(10);
        returnText->setFont(font);

        gridLayout->addWidget(returnText, 0, 0, 1, 1);


        retranslateUi(ReturnTextWidgetClass);

        QMetaObject::connectSlotsByName(ReturnTextWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ReturnTextWidgetClass)
    {
        ReturnTextWidgetClass->setWindowTitle(QCoreApplication::translate("ReturnTextWidgetClass", "ReturnTextWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReturnTextWidgetClass: public Ui_ReturnTextWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETURNTEXTWIDGET_H
