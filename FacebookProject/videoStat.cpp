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