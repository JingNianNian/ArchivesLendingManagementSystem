#pragma once
#include <qstring.h>
#include "ALMSHeaderFiles.h"
class myUtility {
private:
    static string GuidToString(const GUID& guid)
    {
        char buf[64] = { 0 };
        sprintf_s(buf, sizeof(buf),
            "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
            guid.Data1, guid.Data2, guid.Data3,
            guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
            guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
        return std::string(buf);
    }
public:
    static QString getQGUID() {
        return QString(getGUID().c_str());
    }
	static string getGUID()
    {
        string ret;
        GUID guid;
        HRESULT h = CoCreateGuid(&guid);
        if (h == S_OK) {
            ret = GuidToString(guid);
            auto ans = string("");
            for (auto c : ret) {
                if (c == '{' || c == '}') continue;
                ans += c;
            }
            return ans;
        }
        else {
            return "";
        }
    }
};