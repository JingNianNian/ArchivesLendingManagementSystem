#pragma once
#include "ALMSHeaderFiles.h"
#include "User.h"
class curMessage {
private:
	static user& curUser;
public:
	static void setCurUser(user& _u) {
		curUser = _u;
	}
};