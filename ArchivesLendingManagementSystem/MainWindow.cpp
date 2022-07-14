#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
}


MainWindow::~MainWindow()
{
	
}

void MainWindow::closeEvent(QCloseEvent*)
{
	emit exitWin();
}
