#include "LoginWindow.h"


LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	dbHelper db;
	db.openDB("localhost", "ALMSdb", "ALMStest", "123456");
	curMessage::setDbHelper(db);
}

LoginWindow::~LoginWindow()
{
	
}

int LoginWindow::onSignInButtonClicked(bool cked)
{
	if (ui.userNameLineEdit->text().isEmpty() || ui.passwordLineEdit->text().isEmpty()) {
		QMessageBox::about(NULL, "Message", "用户名或密码为空，请重新输入！");
	}
	else {
		MD5Algorithm pmd5 = MD5Algorithm(ui.passwordLineEdit->text().toStdString());
		QString userName = ui.userNameLineEdit->text(), password = QString(pmd5.returnMD5().c_str());
		if (curMessage::db.checkLogin(userName, password)) {
			QMessageBox::about(NULL, "Message", "登陆成功！");
			user curUser = curMessage::db.getUser(userName);

			MainWindow* mw = new MainWindow();
			mw->setGeometry(this->geometry());
			this->hide();
			mw->show();
			connect(mw, SIGNAL(exitWin()), this, SLOT(show()));
		}
		else {
			QMessageBox::about(NULL, "Message", "用户名或密码错误，请重新输入！");
		}
	}
	
	clearText();
	return 0;
}

int LoginWindow::onSignUpButtonClicked(bool cked)
{
	
	return 0;
}

int LoginWindow::onForgetPasswordButtonClicked(bool cked)
{
	ui.userNameLineEdit->setText("ok3");
	return 1;
}

void LoginWindow::clearText() {
	ui.userNameLineEdit->setText("");
	ui.passwordLineEdit->setText("");
}