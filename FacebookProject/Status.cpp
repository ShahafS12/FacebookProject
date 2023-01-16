#include "Status.h"
using namespace std;

Status::Status(string _text,int _type) : text(_text),type(_type) {}

Status::Status(const Status& cp) {
	text = cp.text;
	date = cp.date;
	time = cp.time;
}

Status::~Status() {}


void Status::printStatus() 
{
	// print the status
	cout << endl;
	cout << text << endl;
	this->date.printDate();
	this->time.printTime();
}

Date Status::getDate() const
{
	return date;
}
Time Status::getTime() const
{
	return time;
}

bool Status::operator==(string _text) {
	return text.compare(_text);
}

bool Status::operator!=(string _text) {
	return !(text.compare(_text));
}

int Status::getType() const
{ // return the type of the status
	return type;
}

string Status::getText() const {
	// return the text of the status
	return text;
}

