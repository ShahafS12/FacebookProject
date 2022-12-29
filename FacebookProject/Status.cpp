#include "Status.h"
using namespace std;

Status::Status(string _text) : text(_text) {}

Status::Status(const Status& cp) {
	text = cp.text;
	date = cp.date;
	time = cp.time;
}

Status::~Status() {}


void Status::printStatus() {
	// print the status
	cout << endl;
	cout << text << endl;
	this->date.printDate();
	this->time.printTime();
}

bool Status::operator==(string _text) {
	return text.compare(_text);
}

bool Status::operator!=(string _text) {
	return !(text.compare(_text));
}