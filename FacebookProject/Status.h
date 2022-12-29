#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"
using namespace std;

class Status {
private:
	Date date;
	Time time;
	string text;
public:
	Status(string text);
	Status(const Status& cp);
	~Status();
	void printStatus();
	bool operator==(string text);
	bool operator!=(string _text);
};