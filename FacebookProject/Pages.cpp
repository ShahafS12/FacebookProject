#include "Pages.h"

Pages::Pages(char* _name) : name(_strdup(_name)) {}

Pages::~Pages() {
	// delete constactor
	for (int i = 0; i < status.size(); i++)
		delete (status[i]);
}

void Pages::addStatus() {
	// add status to page
	char text[MAX_STATUS];
	cout << "What is your status?" << endl;
	cin.ignore();
	cin.getline(text, MAX_STATUS);
	Status* s = new Status(text);
	status.push_back(s);
}

void Pages::PrintPagesStatus() {
	// Print the page statuses
	for (int i = 0; i < status.size(); i++)
		this->status[i]->printStatus();
}

void Pages::showMyFans() {
	// print all the fans (Friends)
	for (int i = 0; i < fans.size(); i++) {
		fans[i]->getFriendName();
	}
}

void Pages::getPageName() {
	// get friend name
	cout << this->name << endl;
}

void Pages::addFan(Friend* const _friend, bool sender)
{//check if alrady a fan
	bool alreadyFan = isFan(_friend);
	if (!alreadyFan)
	{
		fans.push_back(_friend);
		if (sender)
			_friend->likePage(this, false);
	}
	else
		throw "User already likes this page";
}

bool Pages::isFan(Friend* const _friend)
{	// check if the friend is a fan and return boolean
	for (int i = 0; i < fans.size(); i++)
	{
		if (_friend == fans[i])
			return true;
	}
	return false;
}

void Pages::removeFan(Friend* const _friend, bool remover)
{	// Remove a fan from a page
	bool foundFriend = false;
	for (int i = 0; i < fans.size(); i++)
	{
		if (_friend == fans[i])
		{
			foundFriend = true;
			fans.erase(fans.begin() + i);
			if (remover)
				_friend->unlikePage(this, false);
			return;
		}
		if (!foundFriend)
			throw "User is not a fan of this page";
	}
}
