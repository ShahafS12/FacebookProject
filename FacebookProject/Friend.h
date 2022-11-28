#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;

#include "Date.h"
#include "Status.h"

const int MAX_STATUS = 300;
const int MAX_NAME = 15;

class Friend {
private:
	char* fname;
	char* lname;
	Date dob;
	Status** statuses = new Status*;
	int phyS_status = 1;
	int numOfStatus = 0;
	Friend** friends = new Friend*;
	int phyS_friends = 1;
	int numOfFriends = 0;
	//Pages** pages;

public:
	Friend(char* _fname, char* _lname, Date _dob);
	void addStatus();
	void removeFriend(Friend* _friend);
	void addFriend(Friend* _friend);
	void checkSizeStatus();
	void checkSizeFriends();
	void PrintFriendStatus();
	void addTwoDefaultStatus();
};

