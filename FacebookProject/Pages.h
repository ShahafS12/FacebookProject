#pragma once
#include "Friend.h"
#include "Status.h"

const int MAX_PAGE_NAME = 30;

class Pages {
private:
	char* name;
	Friend** fans;
	int phyS_fans = 1;
	int numOfFans = 0;
	Status** status = new Status*;
	int phyS_status = 1;
	int numOfStatus = 0;


public:
	Pages(char* _name);
	void addStatus();
	void checkSizeStatus();
	void PrintPagesStatus();
	void showMyFans();
	void getPageName();
	~Pages();
};