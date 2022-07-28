#include "DataController.h"
#include "CurMessage.h"
void dataControl::deleteFiles(vector<QString> list)
{
	if (curMessage::curUser.getUserLevel() <= 1) {
		for (auto fname : list) {
			auto f = file(fname, QString(""), myTime(), myTime(), QString(""), 0, 0, 0);
			curMessage::db.deleteFile(f);
		}
		return;
	}
	else {
		return;
	}
	
}

void dataControl::upUserLevel(vector<QString> list)
{
	if (curMessage::curUser.getUserLevel() == 0) {
		for (auto uname : list) {
			auto u = curMessage::db.getUser(uname);
			if (u.getUserName() == curMessage::curUser.getUserName()) {
				myLog::writeWarningLog(QString("Cannot change yourself [From dataControl::downUserLevel]") +
					QString(" [by %1] ").arg(curMessage::curUser.getUserName()));
				continue;
			}
			if (u.getUserLevel() <= 1) {
				myLog::writeWarningLog(QString("Incorrect permission promotion [From dataControl::upUserLevel]") + 
					QString(" [by %1] ").arg(curMessage::curUser.getUserName()) + 
					QString(" [to %1]").arg(u.getUserName()));
				continue;
			}
			else {
				u.setUserLevel(u.getUserLevel() - 1);
			}
			curMessage::db.setUserLevel(u);
		}
	}
	else {
		myLog::writeWarningLog(QString("Not authorized to operate [From dataControl::upUserLevel]") +
			QString(" [by %1] ").arg(curMessage::curUser.getUserName()));
	}
}

void dataControl::downUserLevel(vector<QString> list)
{
	if (curMessage::curUser.getUserLevel() == 0) {
		for (auto uname : list) {
			auto u = curMessage::db.getUser(uname);
			if (u.getUserName() == curMessage::curUser.getUserName()) {
				myLog::writeWarningLog(QString("Cannot change yourself [From dataControl::downUserLevel]") +
					QString(" [by %1] ").arg(curMessage::curUser.getUserName()));
				continue;
			}

			if (u.getUserLevel() >= 2) {
				myLog::writeWarningLog(QString("Incorrect permission reduction [From dataControl::downUserLevel]") +
					QString(" [by %1] ").arg(curMessage::curUser.getUserName()) +
					QString(" [to %1]").arg(u.getUserName()));
				continue;
			}
			else {
				u.setUserLevel(u.getUserLevel() + 1);
			}
			curMessage::db.setUserLevel(u);
		}
	}
	else {
		myLog::writeWarningLog(QString("Not authorized to operate [From dataControl::downUserLevel]") +
			QString(" [by %1] ").arg(curMessage::curUser.getUserName()));
	}
}

void dataControl::deleteUser(vector<QString> list)
{
	if (curMessage::curUser.getUserLevel() == 0) {
		for (auto uname : list) {
			auto u = curMessage::db.getUser(uname);
			if (u.getUserName() == curMessage::curUser.getUserName()) {
				myLog::writeWarningLog(QString("Cannot delete yourself [From dataControl::deleteUser]") +
					QString(" [by %1] ").arg(curMessage::curUser.getUserName()));
				continue;
			}
			else {
				curMessage::db.deleteUser(u);
			}
		}
		return;
	}
	else {
		myLog::writeWarningLog(QString("Not authorized to operate [From dataControl::deleteUser]") +
			QString(" [by %1] ").arg(curMessage::curUser.getUserName()));
	}
}

void dataControl::dealRecord(vector<QString> list, bool isOk)
{
	if (curMessage::curUser.getUserLevel() <= 1) {
		for (auto guid : list) {
			auto record = curMessage::db.getRecordByGuid(guid);
			if (record.getIsDealWith()) {
				myLog::writeWarningLog(QString("Record %1 has been processed [From dataControl::dealRecord]").arg(guid) +
					QString(" [by %1] ").arg(curMessage::curUser.getUserName()));
			}
			else {
				myLog::writeInfoLog(QString("%1 Record %2 [From dataControl::dealRecord]").arg(isOk ? "Accept" : "Refuse").arg(record.getGuid()) +
					QString(" [by %1] ").arg(curMessage::curUser.getUserName()));
				record.setIsDealWith(true);
				record.setDealResult(isOk);
				record.setIsReturn(false);
				curMessage::db.setIsDealWith(record);
				curMessage::db.setDealResult(record);
				curMessage::db.setIsReturn(record);
			}
		}
	}
	else {
		myLog::writeWarningLog(QString("Not authorized to operate [From dataControl::dealRecord]") +
			QString(" [by %1] ").arg(curMessage::curUser.getUserName()));
	}
}

vector<QString> dataControl::getOverdueFiles()
{
	if (curMessage::curUser.getUserLevel() <= 1) {
		vector<QString> ret;
		auto files = curMessage::db.getAllFile();
		auto nowTime = QDateTime::currentDateTime().toTime_t();
		for (auto file : files) {
			if (file.getSaveTime().getTimeStamp().toInt() < nowTime) {
				ret.push_back(file.getFileTitle());
			}
		}
		return ret;
	}
	else {
		myLog::writeWarningLog(QString("Not authorized to operate [From dataControl::upUserLevel]") +
			QString(" [by %1] ").arg(curMessage::curUser.getUserName()));
		return vector<QString>();
	}
}
