#include "Status.h"

Status::Status(char* _text) : text(_strdup(_text)) {}

Status::Status(const Status& cp) {
	text = _strdup(cp.text);
	date = cp.date;
	time = cp.time;
}

void Status::printStatus() {
	cout << endl;
	cout << text << endl;
	this->date.printDate();
	this->time.printTime();
}
