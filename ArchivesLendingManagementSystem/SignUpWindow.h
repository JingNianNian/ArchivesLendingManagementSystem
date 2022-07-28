#pragma once

#include <QWidget>
#include "ui_SignUpWindow.h"

class SignUpWindow : public QWidget
{
	Q_OBJECT

public:
	SignUpWindow(QWidget *parent = nullptr);
	~SignUpWindow();
	void closeEvent(QCloseEvent*);
	/*
	QObject::connect(newUserName, SIGNAL(textChanged(QString)), SignUpWindowClass, SLOT(checkUserNameUseable(QString)));
        QObject::connect(newPassword, SIGNAL(textChanged(QString)), SignUpWindowClass, SLOT(checkPasswordUseable(QString)));
        QObject::connect(confirmPassword, SIGNAL(textChanged(QString)), SignUpWindowClass, SLOT(checkConfirmPassword(QString)));
        QObject::connect(registerButton, SIGNAL(clicked(bool)), SignUpWindowClass, SLOT(onRegisterButtonClicked(bool)));
	*/
private slots:
	
	void checkPasswordUseable(QString _password);
	void checkConfirmPassword(QString _confirmPassword);
	void onRegisterButtonClicked(bool clicked);
	void checkTelephoneNumber(QString _telephone);
	void checkUserNameUseable(QString _userName);
signals:
	void exitWin();
private:
	Ui::SignUpWindowClass ui;
	bool userNameOk = false;
	bool userPasswordOk = false;
	bool confirmPasswordOk = false;
	bool phoneNumberOk = false;
};
