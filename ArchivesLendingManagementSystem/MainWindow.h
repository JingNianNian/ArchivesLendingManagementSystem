	#pragma once

#include <QWidget>
#include "ui_MainWindow.h"


class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
	void closeEvent(QCloseEvent*);

signals:
	void exitWin();
private:
	Ui::MainWindowClass ui;
	int getSecLevel();
	void clearContent();
private slots:
	/*
		QObject::connect(fileContent, SIGNAL(textChanged()), MainWindowClass, SLOT(onFileContentChanged()));
		QObject::connect(fileTitle, SIGNAL(textChanged(QString)), MainWindowClass, SLOT(onFileTitleChanged(QString)));
		QObject::connect(fileSaveTime, SIGNAL(dateTimeChanged(QDateTime)), MainWindowClass, SLOT(onSaveTimeChanged(QDateTime)));
		QObject::connect(fileLoadTime, SIGNAL(dateTimeChanged(QDateTime)), MainWindowClass, SLOT(onLoadTimeChanged(QDateTime)));
		QObject::connect(tabWidget, SIGNAL(tabBarClicked(int)), MainWindowClass, SLOT(onTabWidgetChanged()));
		QObject::connect(saveButtonBox, SIGNAL(accepted()), MainWindowClass, SLOT(onSaveButtonClicked()));
		QObject::connect(saveButtonBox, SIGNAL(rejected()), MainWindowClass, SLOT(onCancelButtonClicked()));

		QObject::connect(refreshFile, SIGNAL(clicked()), MainWindowClass, SLOT(onRefreshFileButtonClicked()));
		QObject::connect(checkOverdueFile, SIGNAL(clicked()), MainWindowClass, SLOT(onCheckOverdueFileButtonClicked()));
		QObject::connect(deleteSelectedFile, SIGNAL(clicked()), MainWindowClass, SLOT(onDeleteSelectedFileButtonClicked()));
		QObject::connect(upLevel, SIGNAL(clicked()), MainWindowClass, SLOT(onUpLevelButtonClicked()));
		QObject::connect(downLevel, SIGNAL(clicked()), MainWindowClass, SLOT(onDownLevelButtonClicked()));
		QObject::connect(deleteUser, SIGNAL(clicked()), MainWindowClass, SLOT(onDeleteUserButtonClicked()));
		QObject::connect(acceptRecordButton, SIGNAL(clicked()), MainWindowClass, SLOT(onAcceptRecordButtonClicked()));
		QObject::connect(refuseRecordButton, SIGNAL(clicked()), MainWindowClass, SLOT(onRefuseRecordButtonClicked()));
	*/
	void onTabWidgetChanged(int cur);
	void onFileContentChanged();
	void onFileTitleChanged(QString);
	void onSaveTimeChanged();
	void onLoadTimeChanged();
	void onSaveButtonClicked();
	void onCancelButtonClicked();
	void onControlPageChanged(int);
	void onRefreshFileButtonClicked();
	void onCheckOverdueFileButtonClicked();
	void onDeleteSelectedFileButtonClicked();
	void onUpLevelButtonClicked();
	void onDeleteUserButtonClicked();
	void onAcceptRecordButtonClicked();
	void onRefuseRecordButtonClicked();
	void onDownLevelButtonClicked();

};