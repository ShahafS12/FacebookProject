using namespace std;
#include "Friend.h"

Friend::Friend(char* _fname, char* _lname, Date _dob) : fname(_strdup(_fname)), lname(_strdup(_lname)), dob(_dob) {}

void Friend::addStatus() {
	// Add status to a user
	char text[MAX_STATUS];
	cout << "What is your status?" << endl;
	cin.ignore();
	cin.getline(text, MAX_STATUS);
	Status* s = new Status(text);
	checkSizeStatus();
	statuses[numOfStatus] = s;
	numOfStatus++;
}

void Friend::addTwoDefaultStatus()
{  // add the default statuses
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
{// connects between two users after checking they werent friends before
	bool alreadyFriends = checkIfFriends(_friend);
	if (!alreadyFriends)
	{
		checkSizeFriends();
		friends[numOfFriends] = _friend;
		if (sender)
			_friend->addFriend(this, false);
		numOfFriends++;
	}
	else
		cout << "Users already friends" << endl;
}

bool Friend::checkIfFriends(Friend* const _friend)
{//checks if two users are friends
	for (int i = 0; i < numOfFriends; i++)
	{
		if (_friend == friends[i])
			return true;
	}
	return false;
}

void Friend::removeFriend(Friend* _friend, bool remover)
{// checks if two users are friends, removes friendship if they are
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

void Friend::unlikePage(Pages* _toUnlike, bool remover)
{
	bool foundPage = false;
	for (int i = 0; i < numOfLikedPages; i++)
	{
		if (_toUnlike == likedPages[i])
		{
			foundPage = true;
			for (int j = i; j < numOfLikedPages - 1; j++)
			{
				likedPages[j] = likedPages[j + 1];
			}
			numOfLikedPages--;
			if (remover)
				_toUnlike->removeFan(this, false);
			return;
		}
	}
	if(!foundPage)
		cout << "Page not prevously liked" << endl;
}

void Friend::likePage(Pages* const _toLike, bool sender)
{//checks if page is already liked, likes it if it doesnt
	bool alreadyLiked = pageLiked(_toLike);
	if (!alreadyLiked)
	{
		checkSizePages();
		likedPages[numOfLikedPages] = _toLike;
		if (sender)
			_toLike->addFan(this, false);
		numOfLikedPages++;
	}
	else
		cout << "Page already liked" << endl;
}

bool Friend::pageLiked(Pages* const _toLike)
{
	for (int i = 0; i < numOfFriends; i++)
	{
		if (_toLike == likedPages[i])
			return true;
	}
	return false;
}

void Friend::checkSizeStatus() {
	// check the size of the array - if needed allocate more 
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

void Friend::checkSizePages() {
	// check the size of the array - if needed allocate more 

	if (this->phyS_pages == this->numOfLikedPages)
	{
		this->phyS_pages *= 2;
		Pages** tmp = new Pages * [phyS_pages];
		for (int i = 0; i < numOfLikedPages; i++)
			tmp[i] = likedPages[i];
		delete[] likedPages;
		likedPages = tmp;
	}
}

void Friend::checkSizeFriends()
{ 	// check the size of the array - if needed allocate more 

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
	// print the statuses
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
	int num, x = 10;
	for (int i = 0; i < numOfFriends; i++) {
		num = friends[i]->numOfStatus -1;
		for (int j = num; j>=0 && x>=0; j-- , x--)
			friends[i]->statuses[j]->printStatus();
	}
}

Friend::~Friend() {
	// delete constractor
	for (int i = 0; i < numOfStatus; i++)
			delete (statuses[i]);
	delete[] statuses;

	delete[] friends;
}