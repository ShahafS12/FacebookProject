#pragma once
#include "Friend.h"
#include "Status.h"
using namespace std;

const int MAX_PAGE_NAME = 30;

class Friend;

class Pages {
private:
	char* name;
	Friend** fans = new Friend*;
	int phyS_fans = 1;
	int numOfFans = 0;
	Status** status = new Status*;
	int phyS_status = 1;
	int numOfStatus = 0;


public:
	Pages(char* _name);
	void addStatus();
	void checkSizeStatus();
	void chekSizeFans();
	void PrintPagesStatus();
	void showMyFans();
	void getPageName();
	void addFan(Friend* const _friend, bool sender);
	void removeFan(Friend* const _friend, bool sender); // ** ASK Shahaf about const **
	~Pages();
private:
	bool isFan(Friend* const _friend);
};