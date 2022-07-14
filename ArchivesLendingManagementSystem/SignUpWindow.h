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
signals:
	void exitWin();
private:
	Ui::SignUpWindowClass ui;
};
