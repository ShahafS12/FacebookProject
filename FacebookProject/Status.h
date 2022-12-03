#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "Date.h"
#include "Time.h"

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