#include "SignUpWindow.h"

SignUpWindow::SignUpWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
}

SignUpWindow::~SignUpWindow()
{
	
}

void SignUpWindow::closeEvent(QCloseEvent*)
{
	emit exitWin();
}
