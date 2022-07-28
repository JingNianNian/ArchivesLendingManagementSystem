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
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *userNameLineEdit;
    QSpacerItem *verticalSpacer_3;
    QPushButton *signInButton;
    QSpacerItem *horizontalSpacer_5;
    QLabel *userNameLabel;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QLineEdit *passwordLineEdit;
    QLabel *passwordLabel;
    QPushButton *signUpButton;
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
        horizontalSpacer_7 = new QSpacerItem(228, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 4, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(228, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        userNameLineEdit = new QLineEdit(LoginWidget);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(12);
        userNameLineEdit->setFont(font);

        gridLayout->addWidget(userNameLineEdit, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_3, 3, 2, 1, 1);

        signInButton = new QPushButton(LoginWidget);
        signInButton->setObjectName(QString::fromUtf8("signInButton"));
        signInButton->setFont(font);

        gridLayout->addWidget(signInButton, 1, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(228, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 4, 1, 1);

        userNameLabel = new QLabel(LoginWidget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        userNameLabel->setFont(font);
        userNameLabel->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(userNameLabel, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 148, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(228, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 227, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        passwordLineEdit = new QLineEdit(LoginWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setFont(font);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 4, 2, 1, 1);

        passwordLabel = new QLabel(LoginWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setFont(font);

        gridLayout->addWidget(passwordLabel, 4, 1, 1, 1);

        signUpButton = new QPushButton(LoginWidget);
        signUpButton->setObjectName(QString::fromUtf8("signUpButton"));
        signUpButton->setFont(font);
        signUpButton->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(signUpButton, 4, 3, 1, 1);

        LoginWindow->setCentralWidget(LoginWidget);
        statusBar = new QStatusBar(LoginWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LoginWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(userNameLineEdit, passwordLineEdit);
        QWidget::setTabOrder(passwordLineEdit, signInButton);

        retranslateUi(LoginWindow);
        QObject::connect(signInButton, SIGNAL(clicked(bool)), LoginWindow, SLOT(onSignInButtonClicked(bool)));
        QObject::connect(signUpButton, SIGNAL(clicked(bool)), LoginWindow, SLOT(onSignUpButtonClicked(bool)));

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        signInButton->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(shortcut)
        signInButton->setShortcut(QCoreApplication::translate("LoginWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        userNameLabel->setText(QCoreApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        passwordLineEdit->setText(QString());
        passwordLabel->setText(QCoreApplication::translate("LoginWindow", "\345\257\206   \347\240\201\357\274\232", nullptr));
        signUpButton->setText(QCoreApplication::translate("LoginWindow", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
