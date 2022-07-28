#include "ReturnTextWidget.h"

ReturnTextWidget::ReturnTextWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
}

ReturnTextWidget::~ReturnTextWidget()
{
	
}

void ReturnTextWidget::closeEvent(QCloseEvent*)
{
	emit exitWin();
}
