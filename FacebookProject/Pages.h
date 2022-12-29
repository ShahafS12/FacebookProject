#pragma once
#include "Friend.h"
#include "Status.h"
#include "pagesException.h" // problem is here
#include <vector>
using namespace std;

const int MAX_PAGE_NAME = 30;

class Friend;

class Pages {
private:
	string name;
	vector<Friend*> fans;
	vector<Status*> status;
public:
	Pages(string _name);
	void addStatus();
	void PrintPagesStatus();
	void showMyFans();
	void getPageName();
	void addFan(Friend* const _friend, bool sender);
	void removeFan(Friend* const _friend, bool sender);
	~Pages();
	int getAmountOfFans();
	bool operator>(Pages* _page);
private:
	bool isFan(Friend* const _friend);
};