#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "Date.h"

#include "Status.h"
#include "photoStat.h"
#include "videoStat.h"

#include "Pages.h"
#include "friendException.h"
#include <vector>
#include <string>

const int MAX_STATUS = 300;
const int MAX_NAME = 15;

enum statusChoice { Text = 1, Image, Video };
class Pages;

class Friend {
private:
	string fname;
	string lname;
	Date dob;
	vector<Status*> statuses;
	vector<Friend*> friends;
	vector<Pages*> likedPages;
public:
	Friend(string _fname, string _lname, Date _dob);
	~Friend();
	void addStatus(int choice);
	void removeFriend(Friend* _friend, bool remover);
	void addFriend(Friend* _friend, bool sender);
	void PrintFriendStatus();
	void addTwoDefaultStatus();
	void getFriendName();
	void showMyFriends();
	void mostUpdatedStatuses();
	void likePage(Pages* const _toLike, bool sender);
	void unlikePage(Pages* _toUnlike, bool sender);
	const int getAmountOfFriends();
	const string getFName();
	const string getLName();
	Date getDob();
	void writeToFileFriend(ofstream& file);
	void readStatus(ifstream& file);
	bool operator>(Friend* _friend);
	const Friend& operator+=(const Friend& other);
	const Friend& operator+=(const Pages& other);
private:
	bool pageLiked(Pages* const _toLike);
};
