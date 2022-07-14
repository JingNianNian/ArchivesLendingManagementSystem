	#pragma once

#include <QWidget>
#include "ui_MainWindow.h"


class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	void closeEvent(QCloseEvent*);
signals:
	void exitWin();
private:
	Ui::MainWindowClass ui;
};
