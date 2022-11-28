#include "Friend.h"

Friend::Friend(char* _fname, char* _lname, Date _dob) : fname(_strdup(_fname)), lname(_strdup(_lname)), dob(_dob) {}

void Friend::addStatus() {
	char text[MAX_STATUS];
	cout << "What is your status?" << endl;
	cin.ignore();
	cin.getline(text, MAX_STATUS);
	Status* s = new Status(text);
	checkSizeStatus();
	statuses[numOfStatus] = s;
	numOfStatus++;
}

void Friend::addFriend(Friend* _friend)
{
	checkSizeFriends();
	friends[numOfFriends] = _friend;
	numOfFriends++;
}

void Friend::removeFriend(Friend* _friend)
{
	bool foundFriend = false;
	for (int i = 0; i < numOfFriends; i++)
	{
		if (_friend == friends[i])
		{
			foundFriend = true;
			if (i == numOfFriends - 1)
				delete friends[i];
			else
			{
				friends[i] = friends[numOfFriends - 1];
				delete friends[numOfFriends - 1];
			}
			numOfFriends--;
		}
	}
	if (foundFriend == false)
		cout << "User was not in friend list" << endl;
}


void Friend::checkSizeStatus() {
	if (this->phyS_status == this->numOfStatus)
	{
		this->phyS_status *= 2;
		Status** tmp = new Status * [phyS_status];
		for (int i = 0; i < numOfStatus; i++)
			tmp[i] = statuses[i];
		delete[] statuses;
		statuses = tmp;
	}
}

void Friend::checkSizeFriends()
{
	if (this->phyS_friends == this->numOfFriends)
	{
		this->phyS_friends *= 2;
		Friend** tmp = new Friend * [phyS_friends];
		for (int i = 0; i < numOfFriends; i++)
			tmp[i] = friends[i];
		delete[] friends;
		friends = tmp;
	}
}

void Friend::PrintFriendStatus() {
	for (int i = 0; i < numOfStatus; i++)
		this->statuses[i]->printStatus();
}