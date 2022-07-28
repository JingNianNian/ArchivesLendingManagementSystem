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
		ui.outputFileTitleUseableLabel->setText("Ϊ��");
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
		ui.outputFileTitleUseableLabel->setText("����");
	}
	else {
		ui.outputFileTitleUseableLabel->setText("����");
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
		QMessageBox::about(NULL, "Message", "�ļ�������Ϊ�գ�");
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
		QMessageBox::about(NULL, "Message", "���ļ��Ѵ��ڣ�������������");
		return;
	}

	if (ui.fileContent->toPlainText() == "") {
		QMessageBox::about(NULL, "Message", "���ݲ���Ϊ�գ�");
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
		QMessageBox::about(NULL, "Message", "��ӳɹ���");
		clearContent();
	}
	else {
		QMessageBox::about(NULL, "Message", "���ʧ�ܣ�����ϵ����Ա��");
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
					if (ans) tableModel->setData(idx, QVariant("��"));
					else tableModel->setData(idx, QVariant("��"));
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
				tableModel->setData(idx, QVariant("ϵͳ����Ա"));
			}
			else if (ans == 1) {
				tableModel->setData(idx, QVariant("����Ա"));
			}
			else if (ans == 2) {
				tableModel->setData(idx, QVariant("��ͨ�û�"));
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
				tableModel->setData(idx, QVariant("ʵ���ļ�"));
			}
			else if (ans == 1) {
				e_file = 1;
				tableModel->setData(idx, QVariant("�����ļ�"));
			}

			idx = tableModel->index(i, 6);
			ans = tableModel->data(idx).toInt();
			if (ans == 0) {
				tableModel->setData(idx, QVariant("����"));
			}
			else if (ans == 1) {
				tableModel->setData(idx, QVariant("����"));
			}
			else if (ans == 2) {
				tableModel->setData(idx, QVariant("����"));
			}
			else if (ans == 3) {
				tableModel->setData(idx, QVariant("��ͨ"));
			}

			idx = tableModel->index(i, 7);
			ans = tableModel->data(idx).toInt();
			if (e_file) {
				tableModel->setData(idx, QVariant("<�����ļ�>"));
			}
			else {
				if (ans == 0) {
					tableModel->setData(idx, QVariant("δ���"));
				}
				else {
					tableModel->setData(idx, QVariant("�ѽ��"));
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
		ui.outputFileExists->setText("������");
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
		ui.outputFileExists->setText("����");
		borrowFileTitleIsOk = true;
	}
	else {
		ui.outputFileExists->setText("������");
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
		QMessageBox::about(NULL, "Message", "�ļ������ڣ�");
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
			QMessageBox::about(NULL, "Message", "���Ѿ�������ļ���");
			return;
		}
	}
	if (curMessage::db.addRecord(_bR)) {
		QMessageBox::about(NULL, "Message", "�ύ�ɹ���");
		clearBorrowRecord();
	}
	else {
		QMessageBox::about(NULL, "Message", "�ύʧ�ܣ�����ϵ����Ա��");
	}
}

void MainWindow::clearBorrowRecord() {
	auto nowTime = QDateTime::currentDateTime();
	onReturnTimeChanged();
	ui.outputFileExists->setText("������");
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
		QMessageBox::about(NULL, "Message", "��¼δ����");
		return;
	}

	if (!_bR.getDealResult()) {
		QMessageBox::about(NULL, "Message", "��¼���ܾ���");
		return;
	}
	else {
		if (_bR.getIsReturn()) {
			QMessageBox::about(NULL, "Message", "��¼�ѹ黹��");
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
		queryModel->setHeaderData(1, Qt::Horizontal, QVariant("������"));
		queryModel->setHeaderData(2, Qt::Horizontal, QVariant("�ļ���"));
		queryModel->setHeaderData(3, Qt::Horizontal, QVariant("����ʱ��"));
		queryModel->setHeaderData(4, Qt::Horizontal, QVariant("�黹ʱ��"));
		queryModel->setHeaderData(5, Qt::Horizontal, QVariant("�Ƿ���"));
		queryModel->setHeaderData(6, Qt::Horizontal, QVariant("������"));
		queryModel->setHeaderData(7, Qt::Horizontal, QVariant("�Ƿ�黹"));
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
					if (ans) queryModel->setData(idx, QVariant("��"));
					else queryModel->setData(idx, QVariant("��"));
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