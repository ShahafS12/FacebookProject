#pragma once
#include <iostream>
using namespace std;

#include "Date.h"
#include "Status.h"

const int MAX_STATUS = 300;

class Friend {
private:
	char* fname;
	char* lname;
	Date dob;
	Status** statuses = new Status*;
	int phyS_status = 1;
	int numOfStatus = 0;
	Friend** friends;
	//Pages** pages;

public:
	Friend(char* _fname, char* _lname, Date _dob);
	void addStatus();
	void checkSizeStatus();
	void PrintFriendStatus();
};

