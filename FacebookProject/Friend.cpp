using namespace std;
#include "Friend.h"

Friend::Friend(string _fname, string _lname, Date _dob) : fname(_fname), lname(_lname), dob(_dob) {}

void Friend::addStatus() {
	// Add status to a user
	char text[MAX_STATUS];
	cout << "What is your status?" << endl;
	cin.ignore();
	cin.getline(text, MAX_STATUS);
	Status* s = new Status(text);
	statuses.push_back(s);
}

void Friend::addTwoDefaultStatus()
{  // add the default statuses
	string text1;
	text1 = fname;
	text1 += "'s first status";
	Status* s1 = new Status(text1);
	statuses.push_back(s1);
	string text2;
	text2 = fname;
	text2 += "'s first status";
	Status* s2 = new Status(text2);
	statuses.push_back(s2);
}

void Friend::addFriend(Friend* _friend, bool sender)
{// connects between two users after checking they werent friends before
	if (this == _friend)
		throw friendException(ErrorCode::selfFriend);
	for (int i = 0; i < friends.size(); i++)
	{
		if (_friend == friends[i])
			throw friendException(ErrorCode::alreadyFriends);
	}
		friends.push_back(_friend);
		if (sender)
			_friend->addFriend(this, false);
}

Friend& Friend::operator+=(Friend&& _friend)
{
	this->addFriend(&_friend, true);
	return *this;
}

void Friend::removeFriend(Friend* _friend, bool remover)
{// checks if two users are friends, removes friendship if they are
	bool foundFriend = false;
	for (int i = 0; i < friends.size(); i++)
	{
		if (_friend == friends[i])
		{
			foundFriend = true;
			friends.erase(friends.begin() + i);
			if (remover)
				_friend->removeFriend(this, false);
			return;
		}
	}
	if (foundFriend == false)
		throw friendException(ErrorCode::notFriends);
}

void Friend::unlikePage(Pages* _toUnlike, bool remover)
{
	bool foundPage = false;
	for (int i = 0; i < likedPages.size(); i++)
	{
		if (_toUnlike == likedPages[i])
		{
			foundPage = true;
			likedPages.erase(likedPages.begin() + i);
			if (remover)
				_toUnlike->removeFan(this, false);
			return;
		}
	}
	if (!foundPage)
		throw friendException(ErrorCode::pageNotLiked);
}

void Friend::likePage(Pages* const _toLike, bool sender)
{//checks if page is already liked, likes it if it doesnt
	bool alreadyLiked = pageLiked(_toLike);
	if (!alreadyLiked)
	{
		likedPages.push_back(_toLike);
		if (sender)
			_toLike->addFan(this, false);
	}
	else
		throw friendException(ErrorCode::pageAlreadyLiked);
}

bool Friend::pageLiked(Pages* const _toLike)
{//checks if user already like this pages
	for (int i = 0; i < likedPages.size(); i++)
	{
		if (_toLike == likedPages[i])
			return true;
	}
	return false;
}

void Friend::PrintFriendStatus() {
	// print the statuses
	for (int i = statuses.size() - 1; i >= 0; i--)
		this->statuses[i]->printStatus();
}

void Friend::getFriendName() {
	// get friend name
	cout << this->fname << " " << this->lname << endl;
}

string Friend::getFName()
{
	return this->fname;
}

string Friend::getLName()
{
	return this->lname;
}

void Friend::showMyFriends() {
	// Print all my friends
	for (int i = 0; i < friends.size(); i++) {
		friends[i]->getFriendName();
	}
}

void Friend::mostUpdatedStatuses() {
	// print 10 most updated statuses of all friends
	int num, x = 10;
	for (int i = 0; i < friends.size(); i++) {
		num = friends[i]->statuses.size() - 1;
		for (int j = num; j>=0 && x>=0; j-- , x--)
			friends[i]->statuses[j]->printStatus();
	}
}

Friend::~Friend() {
	// delete constractor
	for (int i = 0; i < statuses.size(); i++)
			delete (statuses[i]);
}