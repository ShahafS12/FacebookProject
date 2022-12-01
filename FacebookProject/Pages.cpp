#include "Pages.h"

Pages::Pages(char* _name) : name(_strdup(_name)) {}

Pages::~Pages() {
	for (int i = 0; i < numOfStatus; i++)
		delete (status[i]);
	delete[] status;
}

void Pages::addStatus() {
	char text[MAX_STATUS];
	cout << "What is your status?" << endl;
	cin.ignore();
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
	bool alreadyFan = isFan(_friend);
	if (!alreadyFan)
	{
		chekSizeFans();
		fans[numOfFans] = _friend;
		if (sender)
			_friend->likePage(this, false);
		numOfFans++;
	}
	else
		cout << "User already likes this page" << endl;
}

bool Pages::isFan(Friend* _friend)
{
	for (int i = 0; i < numOfFans; i++)
	{
		if (_friend == fans[i])
			return true;
	}
	return false;
}

void Pages::removeFan(Friend* _friend, bool remover)
{
	bool foundFan = false;
	for (int i = 0; i < numOfFans; i++)
	{
		if (_friend == fans[i])
		{
			foundFan = true;
			if (i == numOfFans - 1)
				delete fans[i];
			else
			{
				fans[i] = fans[numOfFans - 1];
				delete fans[numOfFans - 1];
			}
			numOfFans--;
		}
		if (remover)
			_friend->unlikePage(this, false);
	}
	if (foundFan == false)
		cout << "User was not in friend list" << endl;
}