/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *LoginWidget;
    QGridLayout *gridLayout;
    QLabel *userNameLabel;
    QLineEdit *passwordLineEdit;
    QLabel *passwordLabel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *userNameLineEdit;
    QPushButton *signInButton;
    QSpacerItem *verticalSpacer;
    QPushButton *forgetPasswordButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *signUpButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(901, 569);
        LoginWidget = new QWidget(LoginWindow);
        LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        gridLayout = new QGridLayout(LoginWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        userNameLabel = new QLabel(LoginWidget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(12);
        userNameLabel->setFont(font);
        userNameLabel->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(userNameLabel, 1, 1, 1, 1);

        passwordLineEdit = new QLineEdit(LoginWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setFont(font);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 3, 2, 1, 1);

        passwordLabel = new QLabel(LoginWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setFont(font);

        gridLayout->addWidget(passwordLabel, 3, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(228, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(228, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 148, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 2, 1, 1);

        userNameLineEdit = new QLineEdit(LoginWidget);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));
        userNameLineEdit->setFont(font);

        gridLayout->addWidget(userNameLineEdit, 1, 2, 1, 1);

        signInButton = new QPushButton(LoginWidget);
        signInButton->setObjectName(QString::fromUtf8("signInButton"));
        signInButton->setFont(font);

        gridLayout->addWidget(signInButton, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 227, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        forgetPasswordButton = new QPushButton(LoginWidget);
        forgetPasswordButton->setObjectName(QString::fromUtf8("forgetPasswordButton"));
        forgetPasswordButton->setFont(font);

        gridLayout->addWidget(forgetPasswordButton, 3, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(228, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 4, 1, 1);

        signUpButton = new QPushButton(LoginWidget);
        signUpButton->setObjectName(QString::fromUtf8("signUpButton"));
        signUpButton->setFont(font);
        signUpButton->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(signUpButton, 2, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(228, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(228, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_3, 2, 2, 1, 1);

        LoginWindow->setCentralWidget(LoginWidget);
        statusBar = new QStatusBar(LoginWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LoginWindow->setStatusBar(statusBar);

        retranslateUi(LoginWindow);
        QObject::connect(signInButton, SIGNAL(clicked(bool)), LoginWindow, SLOT(onSignInButtonClicked(bool)));
        QObject::connect(signUpButton, SIGNAL(clicked(bool)), LoginWindow, SLOT(onSignUpButtonClicked(bool)));
        QObject::connect(forgetPasswordButton, SIGNAL(clicked(bool)), LoginWindow, SLOT(onForgetPasswordButtonClicked(bool)));

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        userNameLabel->setText(QCoreApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        passwordLineEdit->setText(QString());
        passwordLabel->setText(QCoreApplication::translate("LoginWindow", "\345\257\206   \347\240\201\357\274\232", nullptr));
        signInButton->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        forgetPasswordButton->setText(QCoreApplication::translate("LoginWindow", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        signUpButton->setText(QCoreApplication::translate("LoginWindow", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H