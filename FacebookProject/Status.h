#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;
#include "Date.h"
#include "Time.h"
// check the include thing that Iris talked about.

class Status {
private:
	Date date;
	Time time;
	char* text;
public:
	Status(char* text);
	Status(const Status& cp);
	~Status();
	void printStatus();
};