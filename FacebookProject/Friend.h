#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;

#include "Date.h"
#include "Status.h"
#include "Pages.h"

const int MAX_STATUS = 300;
const int MAX_NAME = 15;

class Pages;

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
	Pages** likedPages = new Pages*;
	int phyS_pages = 1;
	int numOfLikedPages = 0;

public:
	Friend(char* _fname, char* _lname, Date _dob);
	~Friend();
	void addStatus();
	void removeFriend(Friend* _friend, bool remover);
	void addFriend(Friend* _friend, bool sender);
	void checkSizeStatus();
	void checkSizeFriends();
	void checkSizePages();
	void PrintFriendStatus();
	void addTwoDefaultStatus();
	void getFriendName();
	void showMyFriends();
	void mostUpdatedStatuses();
	void likePage(Pages* const _toLike, bool sender);
	void unlikePage(Pages* _toUnlike, bool sender);
private:
	bool checkIfFriends(Friend* const _friend);
	bool pageLiked(Pages* const _toLike);
};
