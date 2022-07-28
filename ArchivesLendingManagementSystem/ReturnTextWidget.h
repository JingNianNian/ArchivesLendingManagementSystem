#pragma once

#include <QWidget>
#include "ui_ReturnTextWidget.h"

class ReturnTextWidget : public QWidget
{
	Q_OBJECT

public:
	ReturnTextWidget(QWidget *parent = nullptr);
	~ReturnTextWidget();
	Ui::ReturnTextWidgetClass ui;
	void closeEvent(QCloseEvent*);
signals:
	void exitWin();
private:
	

};
