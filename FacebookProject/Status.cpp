#include "Status.h"
using namespace std;

Status::Status(char* _text) : text(_strdup(_text)) {}

Status::Status(const Status& cp) {
	text = _strdup(cp.text);
	date = cp.date;
	time = cp.time;
}

Status::~Status() { delete[] text; }


void Status::printStatus() {
	// print the status
	cout << endl;
	cout << text << endl;
	this->date.printDate();
	this->time.printTime();
}
