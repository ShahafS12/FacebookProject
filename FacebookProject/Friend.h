#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "Date.h"
#include "Status.h"
#include "Pages.h"
#include "friendException.h"
#include <vector>
#include <string>
using namespace std;

const int MAX_STATUS = 300;
const int MAX_NAME = 15;

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
	void addStatus();
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
	string getFName();
	string getLName();
	bool operator>(Friend* _friend);
	//Friend& operator+=(Friend&& _friend);

private:
	void checkIfValidAdd(Friend* const _friend);
	bool pageLiked(Pages* const _toLike);
};
