#include "SignUpWindow.h"
#include "CurMessage.h"
#include "qmessagebox.h"
#include "MD5Algorithm.h"
SignUpWindow::SignUpWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
}

SignUpWindow::~SignUpWindow()
{
	
}

void SignUpWindow::onRegisterButtonClicked(bool c) {
	if (userNameOk && userPasswordOk && phoneNumberOk && confirmPasswordOk) {
		if (curMessage::db.addUser(
			user(ui.newUserName->text(),
				MD5Algorithm(ui.newPassword->text().toStdString()).returnMD5().c_str(),
				ui.telephoneNumber->text(),
				2)
		)) {
			//log success
			QMessageBox::about(NULL, "Message", "注册成功，请返回登陆！");
		}
		else {
			QMessageBox::about(NULL, "Message", "注册失败，请重新检查！");
		}
	}
	else {
		QMessageBox::about(NULL, "Message", "注册失败，请重新检查！");
	}
}

void SignUpWindow::checkPasswordUseable(QString _password) {
	if (_password == "") {
		ui.outputPasswordUseableLabel->setText(QString("请输入密码"));
		userPasswordOk = false;
		return;
	}
	if (_password.size() < 6 || _password.size() > 18) {
		ui.outputPasswordUseableLabel->setText(QString("长度错误"));
		userPasswordOk = false;
		return;
	}
	bool A = false, a = false, one = false, other = false;
	for (auto s : _password) {
		if (s >= 'A' && s <= 'Z') A = true;
		else if (s >= 'a' && s <= 'z') a = true;
		else if (s >= '0' && s <= '9') one = true;
		else other = true;
	}
	if (other) {
		ui.outputPasswordUseableLabel->setText(QString("字符错误"));
		userPasswordOk = false;
		return;
	}

	if ((A && a) || (A && one) || (a && one)) {
		ui.outputPasswordUseableLabel->setText(QString("密码可用"));
		userPasswordOk = true;
		if (ui.confirmPasswordLabel->text().size()) {
			checkConfirmPassword(ui.confirmPassword->text());
		}
	}
	else {
		ui.outputPasswordUseableLabel->setText(QString("类型不足"));
		userPasswordOk = false;
	}
}

void SignUpWindow::checkUserNameUseable(QString _userName) {
	if (_userName == "") {
		ui.outputUserNameUseableLabel->setText(QString("请输入用户名"));
		userNameOk = false;
		return;
	}
	if (_userName[0] >= '0' && _userName[0] <= '9') {
		ui.outputUserNameUseableLabel->setText(QString("不能以数字开头"));
		userNameOk = false;
		return;
	}

	bool A = false, a = false, one = false, other = false;
	for (auto s : _userName) {
		if (s >= 'A' && s <= 'Z') A = true;
		else if (s >= 'a' && s <= 'z') a = true;
		else if (s >= '0' && s <= '9') one = true;
		else other = true;
	}
	if (other) {
		ui.outputUserNameUseableLabel->setText(QString("字符错误"));
		userNameOk = false;
		return;
	}
	if (curMessage::db.checkUser(
		user(ui.newUserName->text(),
			QString(""),
			QString(""),
			3)
	)) {
		ui.outputUserNameUseableLabel->setText(QString("用户名已被注册"));
		userNameOk = false;
	}
	else {
		ui.outputUserNameUseableLabel->setText(QString("用户名可用"));
		userNameOk = true;
	}
}

void SignUpWindow::checkConfirmPassword(QString _confirmPassword) {
	if (_confirmPassword == "") {
		ui.outputConfirmPasswordUseableLabel->setText(QString("请输入密码"));
		confirmPasswordOk = false;
		return;
	}
	if (ui.newPassword->text() == _confirmPassword) {
		ui.outputConfirmPasswordUseableLabel->setText(QString("密码正确"));
		confirmPasswordOk = true;
	}
	else {
		ui.outputConfirmPasswordUseableLabel->setText(QString("密码错误"));
		confirmPasswordOk = false;
	}
}

void SignUpWindow::checkTelephoneNumber(QString _telephone) {
	if (_telephone == "") {
		ui.outputTelephoneUseableLabel->setText(QString("请输入电话"));
		phoneNumberOk = false;
		return;
	}
	if (_telephone.size() != 11) {
		ui.outputTelephoneUseableLabel->setText(QString("长度错误"));
		phoneNumberOk = false;
		return;
	}
	bool one = false, other = false;
	for (auto s : _telephone) {
		if (s >= '0' && s <= '9') one = true;
		else other = true;
	}
	if (other) {
		ui.outputTelephoneUseableLabel->setText(QString("字符错误"));
		phoneNumberOk = false;
		return;
	}
	if(one) {
		ui.outputTelephoneUseableLabel->setText(QString("电话正确"));
		phoneNumberOk = true;
		return;
	}
}

void SignUpWindow::closeEvent(QCloseEvent*)
{
	emit exitWin();
}
