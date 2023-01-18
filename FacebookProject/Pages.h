#pragma once
#include <iostream>
#include "Friend.h"
#include "Status.h"
#include "pagesException.h" // problem is here
#include <vector>
#include <string>

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
	Pages(const Pages& other);
	void addStatus(int choice);
	void PrintPagesStatus() const;
	void showMyFans() const;
	void getPageName() const;
	void addFan(Friend* const _friend, bool sender);
	void removeFan(Friend* const _friend, bool sender);
	~Pages();
	const int getAmountOfFans();
	void writeToFilePages(ofstream& file);
	bool operator>(Pages* _page);
	void readStatus(ifstream& file);
	const Pages& operator=(const Pages& other);
private:
	bool isFan(Friend* const _friend) const;
};