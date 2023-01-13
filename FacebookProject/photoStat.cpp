#include "photoStat.h"

photoStat::photoStat(string text, string pic) : Status(text,2),fileName(pic) {
	file.open(pic);
}

photoStat::~photoStat() { file.close(); }

void photoStat::showPicture() {
	system(("start " + fileName).c_str());
}

string photoStat::getPath() {
	return fileName;
}