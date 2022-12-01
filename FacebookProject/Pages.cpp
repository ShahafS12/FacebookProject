#include "Pages.h"

Pages::Pages(char* _name) : name(_strdup(_name)) {}


void Pages::addStatus() {
	char text[MAX_STATUS];
	cout << "What is your status?" << endl;
	cin.getline(text, MAX_STATUS);
	Status* s = new Status(text);
	checkSizeStatus();
	status[numOfStatus] = s;
	numOfStatus++;
}


void Pages::checkSizeStatus() {
	if (this->phyS_status == this->numOfStatus)
	{
		this->phyS_status *= 2;
		Status** tmp = new Status * [phyS_status];

		for (int i = 0; i < numOfStatus; i++)
			tmp[i] = status[i];

		delete[] status;
		status = tmp;
	}
}

void Pages::PrintPagesStatus() {
	// Print the page statuses
	for (int i = 0; i < numOfStatus; i++)
		this->status[i]->printStatus();
}

void Pages::showMyFans() {
	// print all the fans (Friends)
	for (int i = 0; i < numOfFans; i++) {
		fans[i]->getFriendName();
	}
}

void Pages::getPageName() {
	// get friend name
	cout << this->name << endl;
}

void Pages::chekSizeFans()
{
	if (this->phyS_fans == this->numOfFans)
	{
		this->phyS_fans *= 2;
		Friend** tmp = new Friend * [phyS_fans];
		for (int i = 0; i < numOfFans; i++)
			tmp[i] = fans[i];
		delete[] fans;
		fans = tmp;
	}
}

void Pages::addFan(Friend* _friend, bool sender)
{//check if alrady a fan
	chekSizeFans();
	fans[numOfFans] = _friend;
	if (sender)
		_friend->likePage(this,false);
		numOfFans++;
}