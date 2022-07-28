/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *mainMenu;
    QWidget *entryPage;
    QGridLayout *gridLayout_3;
    QLabel *outputFileTitleUseableLabel;
    QLabel *contentLabel;
    QLineEdit *fileTitle;
    QGroupBox *secLevelRadioButtonBox;
    QGridLayout *gridLayout_2;
    QRadioButton *sec1;
    QRadioButton *sec0;
    QRadioButton *sec3;
    QRadioButton *sec2;
    QDateTimeEdit *fileSaveTime;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *fileContent;
    QLabel *fileTitleLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *secLevelLabel;
    QDateTimeEdit *fileLoadTime;
    QLabel *fileLoadTimeLabel;
    QLabel *fileSaveTimeLabel;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *saveButtonBox;
    QWidget *queryPage;
    QWidget *controlPage;
    QGridLayout *gridLayout_4;
    QToolBox *controlBox;
    QWidget *fileControl;
    QGridLayout *gridLayout_7;
    QPushButton *refreshFile;
    QPushButton *checkOverdueFile;
    QPushButton *deleteSelectedFile;
    QTableView *fileTable;
    QWidget *manageControl;
    QGridLayout *gridLayout_6;
    QPushButton *deleteUser;
    QTableView *userTable;
    QPushButton *upLevel;
    QPushButton *downLevel;
    QWidget *borrowRecordControl;
    QGridLayout *gridLayout_5;
    QTableView *borrowRecordTable;
    QPushButton *acceptRecordButton;
    QPushButton *refuseRecordButton;

    void setupUi(QWidget *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1022, 653);
        gridLayout = new QGridLayout(MainWindowClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(MainWindowClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setUsesScrollButtons(true);
        mainMenu = new QWidget();
        mainMenu->setObjectName(QString::fromUtf8("mainMenu"));
        tabWidget->addTab(mainMenu, QString());
        entryPage = new QWidget();
        entryPage->setObjectName(QString::fromUtf8("entryPage"));
        gridLayout_3 = new QGridLayout(entryPage);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        outputFileTitleUseableLabel = new QLabel(entryPage);
        outputFileTitleUseableLabel->setObjectName(QString::fromUtf8("outputFileTitleUseableLabel"));

        gridLayout_3->addWidget(outputFileTitleUseableLabel, 0, 9, 1, 1);

        contentLabel = new QLabel(entryPage);
        contentLabel->setObjectName(QString::fromUtf8("contentLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(12);
        contentLabel->setFont(font);

        gridLayout_3->addWidget(contentLabel, 2, 0, 1, 1);

        fileTitle = new QLineEdit(entryPage);
        fileTitle->setObjectName(QString::fromUtf8("fileTitle"));
        fileTitle->setFont(font);

        gridLayout_3->addWidget(fileTitle, 0, 2, 1, 7);

        secLevelRadioButtonBox = new QGroupBox(entryPage);
        secLevelRadioButtonBox->setObjectName(QString::fromUtf8("secLevelRadioButtonBox"));
        gridLayout_2 = new QGridLayout(secLevelRadioButtonBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sec1 = new QRadioButton(secLevelRadioButtonBox);
        sec1->setObjectName(QString::fromUtf8("sec1"));
        sec1->setFont(font);

        gridLayout_2->addWidget(sec1, 0, 2, 1, 1);

        sec0 = new QRadioButton(secLevelRadioButtonBox);
        sec0->setObjectName(QString::fromUtf8("sec0"));
        sec0->setFont(font);

        gridLayout_2->addWidget(sec0, 0, 0, 1, 1);

        sec3 = new QRadioButton(secLevelRadioButtonBox);
        sec3->setObjectName(QString::fromUtf8("sec3"));
        sec3->setFont(font);
        sec3->setCheckable(true);
        sec3->setChecked(true);

        gridLayout_2->addWidget(sec3, 0, 4, 1, 1);

        sec2 = new QRadioButton(secLevelRadioButtonBox);
        sec2->setObjectName(QString::fromUtf8("sec2"));
        sec2->setFont(font);

        gridLayout_2->addWidget(sec2, 0, 3, 1, 1);


        gridLayout_3->addWidget(secLevelRadioButtonBox, 1, 8, 1, 2);

        fileSaveTime = new QDateTimeEdit(entryPage);
        fileSaveTime->setObjectName(QString::fromUtf8("fileSaveTime"));
        fileSaveTime->setMinimumSize(QSize(176, 27));
        fileSaveTime->setMaximumSize(QSize(176, 27));
        fileSaveTime->setFont(font);
        fileSaveTime->setDateTime(QDateTime(QDate(2022, 12, 31), QTime(23, 59, 59)));

        gridLayout_3->addWidget(fileSaveTime, 1, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(44, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        fileContent = new QTextEdit(entryPage);
        fileContent->setObjectName(QString::fromUtf8("fileContent"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(11);
        fileContent->setFont(font1);

        gridLayout_3->addWidget(fileContent, 3, 0, 1, 10);

        fileTitleLabel = new QLabel(entryPage);
        fileTitleLabel->setObjectName(QString::fromUtf8("fileTitleLabel"));
        fileTitleLabel->setFont(font);

        gridLayout_3->addWidget(fileTitleLabel, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(44, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 6, 1, 1);

        secLevelLabel = new QLabel(entryPage);
        secLevelLabel->setObjectName(QString::fromUtf8("secLevelLabel"));
        secLevelLabel->setFont(font);

        gridLayout_3->addWidget(secLevelLabel, 1, 7, 1, 1);

        fileLoadTime = new QDateTimeEdit(entryPage);
        fileLoadTime->setObjectName(QString::fromUtf8("fileLoadTime"));
        fileLoadTime->setMinimumSize(QSize(176, 27));
        fileLoadTime->setMaximumSize(QSize(176, 27));
        fileLoadTime->setFont(font);
        fileLoadTime->setDateTime(QDateTime(QDate(2022, 11, 30), QTime(23, 59, 59)));

        gridLayout_3->addWidget(fileLoadTime, 1, 2, 1, 1);

        fileLoadTimeLabel = new QLabel(entryPage);
        fileLoadTimeLabel->setObjectName(QString::fromUtf8("fileLoadTimeLabel"));
        fileLoadTimeLabel->setFont(font);

        gridLayout_3->addWidget(fileLoadTimeLabel, 1, 0, 1, 2);

        fileSaveTimeLabel = new QLabel(entryPage);
        fileSaveTimeLabel->setObjectName(QString::fromUtf8("fileSaveTimeLabel"));
        fileSaveTimeLabel->setFont(font);

        gridLayout_3->addWidget(fileSaveTimeLabel, 1, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(945, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 1, 1, 9);

        saveButtonBox = new QDialogButtonBox(entryPage);
        saveButtonBox->setObjectName(QString::fromUtf8("saveButtonBox"));
        saveButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(saveButtonBox, 4, 8, 1, 1);

        tabWidget->addTab(entryPage, QString());
        queryPage = new QWidget();
        queryPage->setObjectName(QString::fromUtf8("queryPage"));
        tabWidget->addTab(queryPage, QString());
        controlPage = new QWidget();
        controlPage->setObjectName(QString::fromUtf8("controlPage"));
        gridLayout_4 = new QGridLayout(controlPage);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        controlBox = new QToolBox(controlPage);
        controlBox->setObjectName(QString::fromUtf8("controlBox"));
        fileControl = new QWidget();
        fileControl->setObjectName(QString::fromUtf8("fileControl"));
        fileControl->setGeometry(QRect(0, 0, 980, 514));
        gridLayout_7 = new QGridLayout(fileControl);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        refreshFile = new QPushButton(fileControl);
        refreshFile->setObjectName(QString::fromUtf8("refreshFile"));

        gridLayout_7->addWidget(refreshFile, 1, 0, 1, 1);

        checkOverdueFile = new QPushButton(fileControl);
        checkOverdueFile->setObjectName(QString::fromUtf8("checkOverdueFile"));

        gridLayout_7->addWidget(checkOverdueFile, 1, 1, 1, 1);

        deleteSelectedFile = new QPushButton(fileControl);
        deleteSelectedFile->setObjectName(QString::fromUtf8("deleteSelectedFile"));

        gridLayout_7->addWidget(deleteSelectedFile, 1, 2, 1, 1);

        fileTable = new QTableView(fileControl);
        fileTable->setObjectName(QString::fromUtf8("fileTable"));

        gridLayout_7->addWidget(fileTable, 0, 0, 1, 3);

        controlBox->addItem(fileControl, QString::fromUtf8("\346\226\207\344\273\266\346\225\260\346\215\256\347\256\241\347\220\206"));
        manageControl = new QWidget();
        manageControl->setObjectName(QString::fromUtf8("manageControl"));
        manageControl->setGeometry(QRect(0, 0, 980, 514));
        gridLayout_6 = new QGridLayout(manageControl);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        deleteUser = new QPushButton(manageControl);
        deleteUser->setObjectName(QString::fromUtf8("deleteUser"));

        gridLayout_6->addWidget(deleteUser, 1, 2, 1, 1);

        userTable = new QTableView(manageControl);
        userTable->setObjectName(QString::fromUtf8("userTable"));

        gridLayout_6->addWidget(userTable, 0, 0, 1, 3);

        upLevel = new QPushButton(manageControl);
        upLevel->setObjectName(QString::fromUtf8("upLevel"));

        gridLayout_6->addWidget(upLevel, 1, 0, 1, 1);

        downLevel = new QPushButton(manageControl);
        downLevel->setObjectName(QString::fromUtf8("downLevel"));

        gridLayout_6->addWidget(downLevel, 1, 1, 1, 1);

        controlBox->addItem(manageControl, QString::fromUtf8("\347\224\250\346\210\267\346\235\203\351\231\220\347\256\241\347\220\206"));
        borrowRecordControl = new QWidget();
        borrowRecordControl->setObjectName(QString::fromUtf8("borrowRecordControl"));
        gridLayout_5 = new QGridLayout(borrowRecordControl);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        borrowRecordTable = new QTableView(borrowRecordControl);
        borrowRecordTable->setObjectName(QString::fromUtf8("borrowRecordTable"));

        gridLayout_5->addWidget(borrowRecordTable, 0, 0, 1, 2);

        acceptRecordButton = new QPushButton(borrowRecordControl);
        acceptRecordButton->setObjectName(QString::fromUtf8("acceptRecordButton"));

        gridLayout_5->addWidget(acceptRecordButton, 1, 0, 1, 1);

        refuseRecordButton = new QPushButton(borrowRecordControl);
        refuseRecordButton->setObjectName(QString::fromUtf8("refuseRecordButton"));

        gridLayout_5->addWidget(refuseRecordButton, 1, 1, 1, 1);

        controlBox->addItem(borrowRecordControl, QString::fromUtf8("\345\200\237\351\230\205\350\256\260\345\275\225\347\256\241\347\220\206"));

        gridLayout_4->addWidget(controlBox, 0, 1, 1, 1);

        tabWidget->addTab(controlPage, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(MainWindowClass);
        QObject::connect(fileContent, SIGNAL(textChanged()), MainWindowClass, SLOT(onFileContentChanged()));
        QObject::connect(fileTitle, SIGNAL(textChanged(QString)), MainWindowClass, SLOT(onFileTitleChanged(QString)));
        QObject::connect(fileSaveTime, SIGNAL(editingFinished()), MainWindowClass, SLOT(onSaveTimeChanged()));
        QObject::connect(fileLoadTime, SIGNAL(editingFinished()), MainWindowClass, SLOT(onLoadTimeChanged()));
        QObject::connect(tabWidget, SIGNAL(tabBarClicked(int)), MainWindowClass, SLOT(onTabWidgetChanged(int)));
        QObject::connect(saveButtonBox, SIGNAL(accepted()), MainWindowClass, SLOT(onSaveButtonClicked()));
        QObject::connect(saveButtonBox, SIGNAL(rejected()), MainWindowClass, SLOT(onCancelButtonClicked()));
        QObject::connect(controlBox, SIGNAL(currentChanged(int)), MainWindowClass, SLOT(onControlPageChanged(int)));
        QObject::connect(refreshFile, SIGNAL(clicked()), MainWindowClass, SLOT(onRefreshFileButtonClicked()));
        QObject::connect(checkOverdueFile, SIGNAL(clicked()), MainWindowClass, SLOT(onCheckOverdueFileButtonClicked()));
        QObject::connect(deleteSelectedFile, SIGNAL(clicked()), MainWindowClass, SLOT(onDeleteSelectedFileButtonClicked()));
        QObject::connect(upLevel, SIGNAL(clicked()), MainWindowClass, SLOT(onUpLevelButtonClicked()));
        QObject::connect(downLevel, SIGNAL(clicked()), MainWindowClass, SLOT(onDownLevelButtonClicked()));
        QObject::connect(deleteUser, SIGNAL(clicked()), MainWindowClass, SLOT(onDeleteUserButtonClicked()));
        QObject::connect(acceptRecordButton, SIGNAL(clicked()), MainWindowClass, SLOT(onAcceptRecordButtonClicked()));
        QObject::connect(refuseRecordButton, SIGNAL(clicked()), MainWindowClass, SLOT(onRefuseRecordButtonClicked()));

        tabWidget->setCurrentIndex(3);
        controlBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QWidget *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(mainMenu), QCoreApplication::translate("MainWindowClass", "\344\270\273\351\241\265", nullptr));
        outputFileTitleUseableLabel->setText(QCoreApplication::translate("MainWindowClass", "\344\270\272\347\251\272", nullptr));
        contentLabel->setText(QCoreApplication::translate("MainWindowClass", "\346\255\243\346\226\207\357\274\232", nullptr));
        secLevelRadioButtonBox->setTitle(QString());
        sec1->setText(QCoreApplication::translate("MainWindowClass", "\347\247\230\345\257\206", nullptr));
        sec0->setText(QCoreApplication::translate("MainWindowClass", "\347\273\235\345\257\206", nullptr));
        sec3->setText(QCoreApplication::translate("MainWindowClass", "\346\231\256\351\200\232", nullptr));
        sec2->setText(QCoreApplication::translate("MainWindowClass", "\346\234\272\345\257\206", nullptr));
        fileSaveTime->setDisplayFormat(QCoreApplication::translate("MainWindowClass", "yyyy/M/d hh:mm:ss", nullptr));
        fileTitleLabel->setText(QCoreApplication::translate("MainWindowClass", "\346\241\243\346\241\210\345\220\215\347\247\260\357\274\232", nullptr));
        secLevelLabel->setText(QCoreApplication::translate("MainWindowClass", "\344\277\235\345\257\206\347\255\211\347\272\247\357\274\232", nullptr));
        fileLoadTime->setDisplayFormat(QCoreApplication::translate("MainWindowClass", "yyyy/M/d hh:mm:ss", nullptr));
        fileLoadTimeLabel->setText(QCoreApplication::translate("MainWindowClass", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        fileSaveTimeLabel->setText(QCoreApplication::translate("MainWindowClass", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(entryPage), QCoreApplication::translate("MainWindowClass", "\345\275\225\345\205\245", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(queryPage), QCoreApplication::translate("MainWindowClass", "\346\237\245\350\257\242", nullptr));
        refreshFile->setText(QCoreApplication::translate("MainWindowClass", "\345\210\267\346\226\260\346\226\207\344\273\266", nullptr));
        checkOverdueFile->setText(QCoreApplication::translate("MainWindowClass", "\346\243\200\346\237\245\350\277\207\346\234\237\346\226\207\344\273\266", nullptr));
        deleteSelectedFile->setText(QCoreApplication::translate("MainWindowClass", "\345\210\240\351\231\244\351\200\211\344\270\255\346\226\207\344\273\266", nullptr));
        controlBox->setItemText(controlBox->indexOf(fileControl), QCoreApplication::translate("MainWindowClass", "\346\226\207\344\273\266\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        deleteUser->setText(QCoreApplication::translate("MainWindowClass", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        upLevel->setText(QCoreApplication::translate("MainWindowClass", "\346\217\220\345\215\207\346\235\203\351\231\220", nullptr));
        downLevel->setText(QCoreApplication::translate("MainWindowClass", "\351\231\215\344\275\216\346\235\203\351\231\220", nullptr));
        controlBox->setItemText(controlBox->indexOf(manageControl), QCoreApplication::translate("MainWindowClass", "\347\224\250\346\210\267\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        acceptRecordButton->setText(QCoreApplication::translate("MainWindowClass", "\346\211\271\345\207\206\351\200\211\344\270\255", nullptr));
        refuseRecordButton->setText(QCoreApplication::translate("MainWindowClass", "\346\213\222\347\273\235\351\200\211\344\270\255", nullptr));
        controlBox->setItemText(controlBox->indexOf(borrowRecordControl), QCoreApplication::translate("MainWindowClass", "\345\200\237\351\230\205\350\256\260\345\275\225\347\256\241\347\220\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(controlPage), QCoreApplication::translate("MainWindowClass", "\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
