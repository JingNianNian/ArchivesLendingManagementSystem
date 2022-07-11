#include "ArchivesLendingManagementSystem.h"
#include "DBHelper.h"

ArchivesLendingManagementSystem::ArchivesLendingManagementSystem(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    db = dbHelper();
    db.openDB("localhost", "ALMSdb", "ALMStest", "123456");
    db.setUserPassword(user("test1", "123456", "18965423547", 2));
}

ArchivesLendingManagementSystem::~ArchivesLendingManagementSystem()
{
    
}

