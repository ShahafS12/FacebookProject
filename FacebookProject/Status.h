#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"
#include <fstream>
#include "StatusException.h"

using namespace std;

class Status {
private:
	Date date;
	Time time;
	string text;
	int type=1;
public:
	Status() = default;
	Status(string text,int _type=1);
	Status(const Status& cp);
	virtual ~Status();
	int getType() const;
	string getText() const;
	Date getDate() const;
	Time getTime() const;
	virtual void printStatus();
	bool operator==(string text);
	bool operator!=(string _text);
};