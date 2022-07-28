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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindowClass
{
public:
    QGridLayout *gridLayout;
    QLabel *confirmPasswordLabel;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *confirmPasswordLabel_2;
    QLineEdit *telephoneNumber;
    QLabel *outputUserNameUseableLabel;
    QLabel *label_3;
    QLineEdit *confirmPassword;
    QSpacerItem *horizontalSpacer_2;
    QLabel *outputPasswordUseableLabel;
    QLineEdit *newUserName;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QLabel *newUserNameLabel;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *newPassword;
    QLabel *newPasswordLabel;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *registerButton;
    QLabel *outputConfirmPasswordUseableLabel;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QLabel *outputTelephoneUseableLabel;

    void setupUi(QWidget *SignUpWindowClass)
    {
        if (SignUpWindowClass->objectName().isEmpty())
            SignUpWindowClass->setObjectName(QString::fromUtf8("SignUpWindowClass"));
        SignUpWindowClass->resize(879, 622);
        QFont font;
        font.setItalic(false);
        SignUpWindowClass->setFont(font);
        gridLayout = new QGridLayout(SignUpWindowClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        confirmPasswordLabel = new QLabel(SignUpWindowClass);
        confirmPasswordLabel->setObjectName(QString::fromUtf8("confirmPasswordLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        confirmPasswordLabel->setFont(font1);

        gridLayout->addWidget(confirmPasswordLabel, 5, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(203, 186, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 11, 2, 1, 2);

        verticalSpacer = new QSpacerItem(20, 127, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 3, 1, 1);

        label_2 = new QLabel(SignUpWindowClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font2.setPointSize(12);
        font2.setItalic(false);
        label_2->setFont(font2);
        label_2->setFocusPolicy(Qt::NoFocus);
        label_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setLineWidth(1);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setWordWrap(true);
        label_2->setOpenExternalLinks(false);

        gridLayout->addWidget(label_2, 2, 2, 1, 3);

        confirmPasswordLabel_2 = new QLabel(SignUpWindowClass);
        confirmPasswordLabel_2->setObjectName(QString::fromUtf8("confirmPasswordLabel_2"));
        confirmPasswordLabel_2->setFont(font1);

        gridLayout->addWidget(confirmPasswordLabel_2, 7, 1, 1, 1);

        telephoneNumber = new QLineEdit(SignUpWindowClass);
        telephoneNumber->setObjectName(QString::fromUtf8("telephoneNumber"));
        telephoneNumber->setFont(font2);
        telephoneNumber->setEchoMode(QLineEdit::Normal);

        gridLayout->addWidget(telephoneNumber, 7, 2, 1, 2);

        outputUserNameUseableLabel = new QLabel(SignUpWindowClass);
        outputUserNameUseableLabel->setObjectName(QString::fromUtf8("outputUserNameUseableLabel"));
        QFont font3;
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        outputUserNameUseableLabel->setFont(font3);

        gridLayout->addWidget(outputUserNameUseableLabel, 1, 4, 1, 1);

        label_3 = new QLabel(SignUpWindowClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setFocusPolicy(Qt::NoFocus);
        label_3->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setLineWidth(1);
        label_3->setTextFormat(Qt::AutoText);
        label_3->setWordWrap(true);
        label_3->setOpenExternalLinks(false);

        gridLayout->addWidget(label_3, 6, 2, 1, 1);

        confirmPassword = new QLineEdit(SignUpWindowClass);
        confirmPassword->setObjectName(QString::fromUtf8("confirmPassword"));
        confirmPassword->setFont(font2);
        confirmPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(confirmPassword, 5, 2, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 5, 1, 1);

        outputPasswordUseableLabel = new QLabel(SignUpWindowClass);
        outputPasswordUseableLabel->setObjectName(QString::fromUtf8("outputPasswordUseableLabel"));
        outputPasswordUseableLabel->setEnabled(true);
        outputPasswordUseableLabel->setFont(font);

        gridLayout->addWidget(outputPasswordUseableLabel, 3, 4, 1, 1);

        newUserName = new QLineEdit(SignUpWindowClass);
        newUserName->setObjectName(QString::fromUtf8("newUserName"));
        newUserName->setFont(font2);

        gridLayout->addWidget(newUserName, 1, 2, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(213, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 5, 5, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 36, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 8, 2, 1, 2);

        label = new QLabel(SignUpWindowClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);
        label->setFocusPolicy(Qt::NoFocus);
        label->setContextMenuPolicy(Qt::DefaultContextMenu);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setLineWidth(1);
        label->setTextFormat(Qt::AutoText);
        label->setWordWrap(true);
        label->setOpenExternalLinks(false);

        gridLayout->addWidget(label, 4, 2, 1, 3);

        newUserNameLabel = new QLabel(SignUpWindowClass);
        newUserNameLabel->setObjectName(QString::fromUtf8("newUserNameLabel"));
        newUserNameLabel->setFont(font2);

        gridLayout->addWidget(newUserNameLabel, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 5, 0, 1, 1);

        newPassword = new QLineEdit(SignUpWindowClass);
        newPassword->setObjectName(QString::fromUtf8("newPassword"));
        newPassword->setFont(font2);
        newPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(newPassword, 3, 2, 1, 2);

        newPasswordLabel = new QLabel(SignUpWindowClass);
        newPasswordLabel->setObjectName(QString::fromUtf8("newPasswordLabel"));
        newPasswordLabel->setFont(font2);

        gridLayout->addWidget(newPasswordLabel, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 3, 5, 1, 1);

        registerButton = new QPushButton(SignUpWindowClass);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setFont(font2);

        gridLayout->addWidget(registerButton, 9, 3, 1, 1);

        outputConfirmPasswordUseableLabel = new QLabel(SignUpWindowClass);
        outputConfirmPasswordUseableLabel->setObjectName(QString::fromUtf8("outputConfirmPasswordUseableLabel"));

        gridLayout->addWidget(outputConfirmPasswordUseableLabel, 5, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 7, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 7, 5, 1, 1);

        outputTelephoneUseableLabel = new QLabel(SignUpWindowClass);
        outputTelephoneUseableLabel->setObjectName(QString::fromUtf8("outputTelephoneUseableLabel"));

        gridLayout->addWidget(outputTelephoneUseableLabel, 7, 4, 1, 1);

        QWidget::setTabOrder(newUserName, newPassword);
        QWidget::setTabOrder(newPassword, confirmPassword);
        QWidget::setTabOrder(confirmPassword, telephoneNumber);
        QWidget::setTabOrder(telephoneNumber, registerButton);

        retranslateUi(SignUpWindowClass);
        QObject::connect(newUserName, SIGNAL(textChanged(QString)), SignUpWindowClass, SLOT(checkUserNameUseable(QString)));
        QObject::connect(newPassword, SIGNAL(textChanged(QString)), SignUpWindowClass, SLOT(checkPasswordUseable(QString)));
        QObject::connect(confirmPassword, SIGNAL(textChanged(QString)), SignUpWindowClass, SLOT(checkConfirmPassword(QString)));
        QObject::connect(registerButton, SIGNAL(clicked(bool)), SignUpWindowClass, SLOT(onRegisterButtonClicked(bool)));
        QObject::connect(telephoneNumber, SIGNAL(textChanged(QString)), SignUpWindowClass, SLOT(checkTelephoneNumber(QString)));

        QMetaObject::connectSlotsByName(SignUpWindowClass);
    } // setupUi

    void retranslateUi(QWidget *SignUpWindowClass)
    {
        SignUpWindowClass->setWindowTitle(QCoreApplication::translate("SignUpWindowClass", "SignUpWindow", nullptr));
        confirmPasswordLabel->setText(QCoreApplication::translate("SignUpWindowClass", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("SignUpWindowClass", "\347\224\250\346\210\267\345\220\215\344\273\205\347\224\261\345\244\247\345\260\217\345\206\231\345\255\227\346\257\215\345\222\214\346\225\260\345\255\227\347\273\204\346\210\220\357\274\214\344\270\224\345\277\205\351\241\273\344\273\245\345\255\227\346\257\215\345\274\200\345\244\264", nullptr));
        confirmPasswordLabel_2->setText(QCoreApplication::translate("SignUpWindowClass", "\347\224\265\350\257\235", nullptr));
        outputUserNameUseableLabel->setText(QCoreApplication::translate("SignUpWindowClass", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("SignUpWindowClass", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        outputPasswordUseableLabel->setText(QCoreApplication::translate("SignUpWindowClass", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("SignUpWindowClass", "\345\257\206\347\240\201\351\234\200\350\246\201\345\214\205\345\220\253A-Z\357\274\214a-z\357\274\2140-9\345\205\266\344\270\255\344\270\244\347\247\215\347\273\204\345\220\210\357\274\214\345\271\266\344\270\224\351\225\277\345\272\246\344\273\213\344\272\2166-18\344\271\213\351\227\264", nullptr));
        newUserNameLabel->setText(QCoreApplication::translate("SignUpWindowClass", "\347\224\250\346\210\267\345\220\215", nullptr));
        newPasswordLabel->setText(QCoreApplication::translate("SignUpWindowClass", "\345\257\206\347\240\201", nullptr));
        registerButton->setText(QCoreApplication::translate("SignUpWindowClass", "\346\263\250\345\206\214", nullptr));
        outputConfirmPasswordUseableLabel->setText(QCoreApplication::translate("SignUpWindowClass", "\350\257\267\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        outputTelephoneUseableLabel->setText(QCoreApplication::translate("SignUpWindowClass", "\350\257\267\350\276\223\345\205\245\347\224\265\350\257\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindowClass: public Ui_SignUpWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
