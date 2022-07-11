#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ArchivesLendingManagementSystem.h"
#include "DBHelper.h"
class ArchivesLendingManagementSystem : public QMainWindow
{
    Q_OBJECT

public:
    ArchivesLendingManagementSystem(QWidget *parent = nullptr);
    ~ArchivesLendingManagementSystem();

private:
    Ui::ArchivesLendingManagementSystemClass ui;
    dbHelper db;
    user curUser;
};
