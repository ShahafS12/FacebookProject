#include "photoStat.h"

photoStat::photoStat(string text, string pic) : Status(text,2),fileName(pic) {
	file.open(pic);
}

photoStat::~photoStat() { file.close(); }

void photoStat::showPicture() {
	system(("start " + fileName).c_str());
}

void photoStat::printStatus()
{
    // print the status
    cout << endl;
    cout << this->getText() << endl;
    this->getDate().printDate();
    this->getTime().printTime();
    this->showPicture();
}

string photoStat::getPath() {
	return fileName;
}