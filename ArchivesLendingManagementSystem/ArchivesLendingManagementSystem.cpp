#include "ArchivesLendingManagementSystem.h"
#include "DBHelper.h"

ArchivesLendingManagementSystem::ArchivesLendingManagementSystem(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    db = dbHelper();
    db.openDB("localhost", "ALMSdb", "ALMStest", "123456");
    db.setFileUserName(file(
        QString("testfile1"),
        QString("test1"),
        myTime(1657592605),
        myTime(1657593238),
        QString("jdhgkahgilhawilghiuhiuhsdiuaghihi"),
        1,
        0,
        0
    ));
}

ArchivesLendingManagementSystem::~ArchivesLendingManagementSystem()
{
    
}

