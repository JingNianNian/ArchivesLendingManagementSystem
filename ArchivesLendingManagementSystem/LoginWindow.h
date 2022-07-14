#pragma once

#include <QtWidgets/qmainwindow.h>
#include "ui_LoginWindow.h"
#include <qmessagebox.h>
#include "MainWindow.h"
#include "MD5Algorithm.h"
#include "DBHelper.h"
class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = nullptr);
	~LoginWindow();
	void clearText();
private slots:
	int onSignInButtonClicked(bool);
	int onSignUpButtonClicked(bool);
	int onForgetPasswordButtonClicked(bool);
private:
	Ui::LoginWindow ui;
	dbHelper db;
	
};
