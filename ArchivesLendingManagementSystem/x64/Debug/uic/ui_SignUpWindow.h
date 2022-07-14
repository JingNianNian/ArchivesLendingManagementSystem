/********************************************************************************
** Form generated from reading UI file 'SignUpWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindowClass
{
public:

    void setupUi(QWidget *SignUpWindowClass)
    {
        if (SignUpWindowClass->objectName().isEmpty())
            SignUpWindowClass->setObjectName(QString::fromUtf8("SignUpWindowClass"));
        SignUpWindowClass->resize(600, 400);

        retranslateUi(SignUpWindowClass);

        QMetaObject::connectSlotsByName(SignUpWindowClass);
    } // setupUi

    void retranslateUi(QWidget *SignUpWindowClass)
    {
        SignUpWindowClass->setWindowTitle(QCoreApplication::translate("SignUpWindowClass", "SignUpWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindowClass: public Ui_SignUpWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
