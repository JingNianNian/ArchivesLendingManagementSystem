#include "MainWindow.h"
#include "CurMessage.h"
#include "qmessagebox.h"
#include "DataController.h"
#include "MyUtility.h"
#include "ReturnTextWidget.h"
MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	if(curMessage::curUser.getUserLevel() > 1) ui.tabWidget->setTabEnabled(3, false);
	clearContent();
	clearBorrowRecord();
}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent*)
{
	curMessage::setCurUser(user());
	emit exitWin();
}

void MainWindow::onFileContentChanged()
{
}

void MainWindow::onFileTitleChanged(QString _qS)
{
	if (_qS == "") {
		ui.outputFileTitleUseableLabel->setText("为空");
		return;
	}

	if (curMessage::db.checkFile(
		file(
			_qS,
			QString(""),
			myTime(),
			myTime(),
			QString(""),
			0, 0, 0
		)
	)) {
		ui.outputFileTitleUseableLabel->setText("存在");
	}
	else {
		ui.outputFileTitleUseableLabel->setText("可用");
	}
}

void MainWindow::onSaveTimeChanged()
{
	if (ui.fileSaveTime->dateTime() < ui.fileLoadTime->dateTime()) {
		ui.fileSaveTime->setDateTime(ui.fileLoadTime->dateTime());
	}
	if (ui.fileSaveTime->dateTime() > QDateTime::currentDateTime().addYears(100)) {
		ui.fileSaveTime->setDateTime(QDateTime::currentDateTime().addYears(100));
	}
}

void MainWindow::onLoadTimeChanged()
{
	if (ui.fileLoadTime->dateTime() < QDateTime::currentDateTime()) {
		ui.fileLoadTime->setDateTime(QDateTime::currentDateTime());
	}
	auto now = ui.fileLoadTime->dateTime();
	now.addDays(1);
	if (now > QDateTime::currentDateTime().addDays(1)) {
		ui.fileLoadTime->setDateTime(QDateTime::currentDateTime().addDays(1));
	}
	if (ui.fileSaveTime->dateTime() < ui.fileLoadTime->dateTime()) {
		ui.fileSaveTime->setDateTime(ui.fileLoadTime->dateTime());
	}
}

int  MainWindow::getSecLevel() {
	if (ui.sec0->isChecked()) {
		return 0;
	}
	else if (ui.sec1->isChecked()) {
		return 1;
	}
	else if (ui.sec2->isChecked()) {
		return 2;
	}
	else if (ui.sec3->isChecked()) {
		return 3;
	}
	return 3;
}

void MainWindow::clearContent()
{
	ui.fileTitle->setText("");
	ui.fileContent->setPlainText("");
	ui.fileLoadTime->setDateTime(myTime().toQDateTime());
	ui.fileSaveTime->setDateTime(myTime().toQDateTime());
	ui.sec3->setChecked(true);
}

void MainWindow::onSaveButtonClicked()
{
	if (ui.fileTitle->text() == "") {
		QMessageBox::about(NULL, "Message", "文件名不能为空！");
		return;
	}

	if (curMessage::db.checkFile(
		file(
			ui.fileTitle->text(),
			QString(""),
			myTime(),
			myTime(),
			QString(""),
			0, 0, 0
		)
	)) {
		QMessageBox::about(NULL, "Message", "该文件已存在，请重新命名！");
		return;
	}

	if (ui.fileContent->toPlainText() == "") {
		QMessageBox::about(NULL, "Message", "内容不能为空！");
		return;
	}

	if (curMessage::db.addFile(
		file(
			ui.fileTitle->text(),
			curMessage::curUser.getUserName(),
			myTime(ui.fileLoadTime->dateTime()),
			myTime(ui.fileSaveTime->dateTime()),
			ui.fileContent->toPlainText(),
			1, getSecLevel(), 0
		)
	)) {
		QMessageBox::about(NULL, "Message", "添加成功！");
		clearContent();
	}
	else {
		QMessageBox::about(NULL, "Message", "添加失败，请联系管理员！");
	}
}

void MainWindow::onCancelButtonClicked()
{
	clearContent();
}

QSqlTableModel* tableModel = NULL;

void MainWindow::onControlPageChanged(int page)
{
	if (tableModel != NULL) delete tableModel;

	if (page == 2) {
		tableModel = curMessage::db.getTableModel("borrowRecordTable");
		ui.borrowRecordTable->setModel(tableModel);
		ui.borrowRecordTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
		for (int i = 0; i < tableModel->rowCount(); i++) {
			for (auto j : { 3, 4 }) {
				auto idx = tableModel->index(i, j);
				int ans = tableModel->data(idx).toInt();
				myTime tm(ans);
				tableModel->setData(idx, QVariant(tm.getDateAndTime()));
			}
			for (auto j : { 5,6,7 }) {
				auto idx = tableModel->index(i, j);
				bool ans = tableModel->data(idx).isNull();
				if (!ans) {
					ans = tableModel->data(idx).toBool();
					if (ans) tableModel->setData(idx, QVariant("是"));
					else tableModel->setData(idx, QVariant("否"));
				}
				//tableModel->setData(idx, )
			}
		}
	}
	else if (page == 1) {
		 tableModel = curMessage::db.getTableModel("userTable");
		ui.userTable->setModel(tableModel);
		ui.userTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
		for (int i = 0; i < tableModel->rowCount(); i++) {
			auto idx = tableModel->index(i, 3);
			int ans = tableModel->data(idx).toInt();
			if (ans == 0) {
				tableModel->setData(idx, QVariant("系统管理员"));
			}
			else if (ans == 1) {
				tableModel->setData(idx, QVariant("管理员"));
			}
			else if (ans == 2) {
				tableModel->setData(idx, QVariant("普通用户"));
			}
		}
		
	}
	else if (page == 0) {
		 tableModel = curMessage::db.getTableModel("fileTable");
		ui.fileTable->setModel(tableModel);
		ui.fileTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
		for (int i = 0; i < tableModel->rowCount(); i++) {
			for (auto j : { 2, 3 }) {
				auto idx = tableModel->index(i, j);
				int ans = tableModel->data(idx).toInt();
				myTime tm(ans);
				tableModel->setData(idx, QVariant(tm.getDateAndTime()));
			}
			auto idx = tableModel->index(i, 5);
			int ans = tableModel->data(idx).toInt();
			int e_file = 0;
			if (ans == 0) {
				tableModel->setData(idx, QVariant("实体文件"));
			}
			else if (ans == 1) {
				e_file = 1;
				tableModel->setData(idx, QVariant("电子文件"));
			}

			idx = tableModel->index(i, 6);
			ans = tableModel->data(idx).toInt();
			if (ans == 0) {
				tableModel->setData(idx, QVariant("绝密"));
			}
			else if (ans == 1) {
				tableModel->setData(idx, QVariant("机密"));
			}
			else if (ans == 2) {
				tableModel->setData(idx, QVariant("秘密"));
			}
			else if (ans == 3) {
				tableModel->setData(idx, QVariant("普通"));
			}

			idx = tableModel->index(i, 7);
			ans = tableModel->data(idx).toInt();
			if (e_file) {
				tableModel->setData(idx, QVariant("<电子文件>"));
			}
			else {
				if (ans == 0) {
					tableModel->setData(idx, QVariant("未借出"));
				}
				else {
					tableModel->setData(idx, QVariant("已借出"));
				}
			}
			
		}
	}
}

void MainWindow::onRefreshFileButtonClicked()
{
	onControlPageChanged(0);
}

void MainWindow::onCheckOverdueFileButtonClicked()
{
	auto overdueFiles = dataControl::getOverdueFiles();
	QSet<QString> fileset;
	for (auto fname : overdueFiles) {
		fileset.insert(fname);
	}
	int rowCount = ui.fileTable->model()->rowCount();
	for (int i = 0; i < rowCount; i++) {
		auto idx = ui.fileTable->model()->index(i, 0);
		auto fname = ui.fileTable->model()->data(idx).toString();
		if (fileset.contains(fname)) {
			ui.fileTable->selectRow(i);
		}
	}
}

void MainWindow::onDeleteSelectedFileButtonClicked()
{
	qDebug() << ui.fileTable->selectionModel()->selectedRows();
	vector<QString> delFileTitle;
	for (auto i : ui.fileTable->selectionModel()->selectedRows()) {
		auto fname = ui.fileTable->model()->data(i).toString();
		delFileTitle.push_back(fname);
		qDebug() << fname;
	}
	dataControl::deleteFiles(delFileTitle);
	onControlPageChanged(0);
}

void MainWindow::onUpLevelButtonClicked()
{
	vector<QString> upUserName;
	for (auto i : ui.userTable->selectionModel()->selectedRows()) {
		auto uname = ui.userTable->model()->data(i).toString();
		upUserName.push_back(uname);
		qDebug() << uname;
	}
	dataControl::upUserLevel(upUserName);
	onControlPageChanged(1);
}

void MainWindow::onDeleteUserButtonClicked()
{
	vector<QString> deleteUserName;
	for (auto i : ui.userTable->selectionModel()->selectedRows()) {
		auto uname = ui.userTable->model()->data(i).toString();
		deleteUserName.push_back(uname);
		qDebug() << uname;
	}
	dataControl::deleteUser(deleteUserName);
	onControlPageChanged(1);
}

void MainWindow::onAcceptRecordButtonClicked()
{
	vector<QString> acceptRecord;
	for (auto i : ui.borrowRecordTable->selectionModel()->selectedRows()) {
		auto guid = ui.borrowRecordTable->model()->data(i).toString();
		acceptRecord.push_back(guid);
		qDebug() << guid;
	}
	dataControl::dealRecord(acceptRecord, 1);
	onControlPageChanged(2);
}

void MainWindow::onRefuseRecordButtonClicked()
{
	vector<QString> acceptRecord;
	for (auto i : ui.borrowRecordTable->selectionModel()->selectedRows()) {
		auto guid = ui.borrowRecordTable->model()->data(i).toString();
		acceptRecord.push_back(guid);
		qDebug() << guid;
	}
	dataControl::dealRecord(acceptRecord, 0);
	onControlPageChanged(2);
}

void MainWindow::onDownLevelButtonClicked()
{
	vector<QString> downUserName;
	for (auto i : ui.userTable->selectionModel()->selectedRows()) {
		auto uname = ui.userTable->model()->data(i).toString();
		downUserName.push_back(uname);
		qDebug() << uname;
	}
	dataControl::downUserLevel(downUserName);
	onControlPageChanged(1);
}

void MainWindow::onBorrowFileTitleChanged(QString _qS)
{
	if (_qS == "") {
		ui.outputFileExists->setText("不存在");
		borrowFileTitleIsOk = false;
		return;
	}

	if (curMessage::db.checkFile(
		file(
			_qS,
			QString(""),
			myTime(),
			myTime(),
			QString(""),
			0, 0, 0
		)
	)) {
		ui.outputFileExists->setText("存在");
		borrowFileTitleIsOk = true;
	}
	else {
		ui.outputFileExists->setText("不存在");
		borrowFileTitleIsOk = false;
	}
}

void MainWindow::onReturnTimeChanged()
{
	auto now = QDateTime::currentDateTime().addDays(1);
	if (ui.returnDateTime->dateTime() < now) {
		ui.returnDateTime->setDateTime(now);
	}
}

void MainWindow::onSubmitBorrowRecordButtonClicked()
{
	if (!borrowFileTitleIsOk) {
		QMessageBox::about(NULL, "Message", "文件不存在！");
		return;
	}
	auto guid = myUtility::getQGUID();
	auto userName = curMessage::curUser.getUserName();
	auto fileTitle = ui.borrowFileTitle->text();
	auto nowTime = myTime(QDateTime::currentDateTime().toTime_t());
	auto returnTime = myTime(ui.returnDateTime->dateTime().toTime_t());
	auto isDeal = curMessage::curUser.getUserLevel() <= 1;
	auto _bR = borrowRecord(guid, userName, fileTitle, nowTime, returnTime, isDeal, isDeal);
	auto allUserRecord = curMessage::db.getRecordByUser(curMessage::curUser.getUserName());
	for (auto bR : allUserRecord) {
		if (bR.getFileTitle() == fileTitle && bR.getIsDealWith() && bR.getDealResult() && !bR.getIsReturn()) {
			QMessageBox::about(NULL, "Message", "您已经借出此文件！");
			return;
		}
	}
	if (curMessage::db.addRecord(_bR)) {
		QMessageBox::about(NULL, "Message", "提交成功！");
		clearBorrowRecord();
	}
	else {
		QMessageBox::about(NULL, "Message", "提交失败，请联系管理员！");
	}
}

void MainWindow::clearBorrowRecord() {
	auto nowTime = QDateTime::currentDateTime();
	onReturnTimeChanged();
	ui.outputFileExists->setText("不存在");
	ui.borrowFileTitle->setText("");
}

void MainWindow::onCancelBorrowRecordButtonClicked()
{
	clearBorrowRecord();
}

void MainWindow::onRefreshBorrowRecordButtonClicked()
{
	onQueryTabChanged(0);
}

void MainWindow::onGetContentDoubleClicked(QModelIndex idx)
{
	auto GuidIdx = ui.queryBorrowRecordTable->model()->index(idx.row(), 0);
	auto Guid = ui.queryBorrowRecordTable->model()->data(GuidIdx).toString();
	auto _bR = curMessage::db.getRecordByGuid(Guid);
	if (!_bR.getIsDealWith()) {
		QMessageBox::about(NULL, "Message", "记录未处理！");
		return;
	}

	if (!_bR.getDealResult()) {
		QMessageBox::about(NULL, "Message", "记录被拒绝！");
		return;
	}
	else {
		if (_bR.getIsReturn()) {
			QMessageBox::about(NULL, "Message", "记录已归还！");
		}
		else {
			auto _f = curMessage::db.getFileByTitle(_bR.getFileTitle());
			ReturnTextWidget* mw = new ReturnTextWidget();
			mw->setGeometry(this->geometry());
			mw->show();
			mw->ui.returnText->setPlainText(_f.getFileContent());
		}
	}
}

void MainWindow::onReturnSelectRecordButtonClicked()
{
	vector<QString> returnRecord;
	for (auto i : ui.queryBorrowRecordTable->selectionModel()->selectedRows()) {
		auto guid = ui.queryBorrowRecordTable->model()->data(i).toString();
		returnRecord.push_back(guid);
		qDebug() << guid;
	}
	dataControl::returnRecord(returnRecord);
	onQueryTabChanged(0);
}

QSqlTableModel* queryModel = NULL;

void MainWindow::onQueryTabChanged(int tab)
{
	
	dataControl::checkRecordOverdue();
	if (tab == 0) {
		if (queryModel != NULL) delete queryModel;
		queryModel = new QSqlTableModel(NULL, curMessage::db.getDbObj());
		queryModel->setTable("borrowRecordTable");
		queryModel->setHeaderData(0, Qt::Horizontal, QVariant("Guid"));
		queryModel->setHeaderData(1, Qt::Horizontal, QVariant("借阅者"));
		queryModel->setHeaderData(2, Qt::Horizontal, QVariant("文件名"));
		queryModel->setHeaderData(3, Qt::Horizontal, QVariant("借阅时间"));
		queryModel->setHeaderData(4, Qt::Horizontal, QVariant("归还时间"));
		queryModel->setHeaderData(5, Qt::Horizontal, QVariant("是否处理"));
		queryModel->setHeaderData(6, Qt::Horizontal, QVariant("处理结果"));
		queryModel->setHeaderData(7, Qt::Horizontal, QVariant("是否归还"));
		queryModel->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);
		queryModel->setFilter(QString("userName = '%1'").arg(curMessage::curUser.getUserName()));
		queryModel->select();
		ui.queryBorrowRecordTable->setModel(queryModel);
		ui.queryBorrowRecordTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
		tableModel = curMessage::db.getTableModel("borrowRecordTable");
		ui.borrowRecordTable->setModel(tableModel);
		ui.borrowRecordTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
		for (int i = 0; i < queryModel->rowCount(); i++) {
			for (auto j : { 3, 4 }) {
				auto idx = queryModel->index(i, j);
				int ans = queryModel->data(idx).toInt();
				myTime tm(ans);
				queryModel->setData(idx, QVariant(tm.getDateAndTime()));
			}
			for (auto j : { 5,6,7 }) {
				auto idx = queryModel->index(i, j);
				bool ans = queryModel->data(idx).isNull();
				if (!ans) {
					ans = queryModel->data(idx).toBool();
					if (ans) queryModel->setData(idx, QVariant("是"));
					else queryModel->setData(idx, QVariant("否"));
				}
				//tableModel->setData(idx, )
			}
		}
	}
	else {
		//
	}
}

void MainWindow::onTabWidgetChanged(int cur)
{
	if (cur == 3) {
		onControlPageChanged(ui.controlBox->currentIndex());
	}
	else if (cur == 2) {
		onRefreshBorrowRecordButtonClicked();
	}
}