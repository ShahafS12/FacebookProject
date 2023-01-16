#pragma once
#include "Status.h"

class photoStat : public Status {
private:
    ifstream file;
    string fileName;

public:
    photoStat(string text, string pic);
    void showPicture();
	void printStatus() override;
    ~photoStat();
	string getPath();
};