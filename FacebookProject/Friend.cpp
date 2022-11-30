#include "Friend.h"

Friend::Friend(char* _fname, char* _lname, Date _dob) : fname(_strdup(_fname)), lname(_strdup(_lname)), dob(_dob) {}

void Friend::addStatus() {
	char text[MAX_STATUS];
	cout << "What is your status?" << endl;
	cin.getline(text, MAX_STATUS);
	Status* s = new Status(text);
	checkSizeStatus();
	statuses[numOfStatus] = s;
	numOfStatus++;
}

void Friend::addTwoDefaultStatus()
{
	char text1[MAX_STATUS];
	strcpy(text1, fname);
	strcat(text1, "'s first status");
	Status* s1 = new Status(text1);
	checkSizeStatus();
	statuses[numOfStatus] = s1;
	numOfStatus++;
	char text2[MAX_STATUS];
	strcpy(text2, fname);
	strcat(text2, "'s second status");
	Status* s2 = new Status(text2);
	checkSizeStatus();
	statuses[numOfStatus] = s2;
	numOfStatus++;
}

void Friend::addFriend(Friend* _friend, bool sender)
{
	checkSizeFriends();
	friends[numOfFriends] = _friend;
	if (sender)
		_friend->addFriend(this, false);
	numOfFriends++;
}

void Friend::removeFriend(Friend* _friend, bool remover)
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
		if (remover)
			_friend->removeFriend(this, false);
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

void Friend::getFriendName() {
	// get friend name
	cout << this->fname << " " << this->lname << endl;
}

void Friend::showMyFriends() {
	// Print all my friends
	for (int i = 0; i < numOfFriends; i++) {
		friends[i]->getFriendName();
	}
}

void Friend::mostUpdatedStatuses() {
	// print 10 most updated statuses of all friends
	int num;
	for (int i = 0; i < numOfFriends; i++) {
		num = friends[i]->numOfStatus;
		for (int j = num; j > num - 10; j--)
			friends[i]->statuses[j]->printStatus();
	}
}