#include "ArchivesLendingManagementSystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ArchivesLendingManagementSystem w;
    w.show();
    return a.exec();
}
