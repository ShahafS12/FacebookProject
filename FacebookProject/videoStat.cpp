#include "videoStat.h"

videoStat::videoStat(string text, string video) : Status(text,3), fileName(video) {
	file.open(video);
}

videoStat::~videoStat() { file.close(); }

void videoStat::showVideo() {
	system(("start " + fileName).c_str());
}

string videoStat::getPath() {
	return fileName;
}

void videoStat::printStatus()
{
    // print the status
    cout << endl;
    cout << this->getText() << endl;
    this->getDate().printDate();
    this->getTime().printTime();
    this->showVideo();
}