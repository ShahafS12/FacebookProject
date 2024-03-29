using namespace std;
#include "Friend.h"

	
Friend::Friend(string& _fname, string& _lname, Date& _dob) : fname(_fname), lname(_lname), dob(_dob) {}


Friend::Friend(const Friend& other) {
	// copy ctor
	*this = other;
}

const Friend& Friend::operator=(const Friend& other) {
	// operator = 
	if (this != &other)
	{
		fname = other.fname;
		lname = other.lname;
		dob = other.dob;
		friends.assign(other.friends.begin(), other.friends.end());
		statuses.assign(other.statuses.begin(), other.statuses.end());
		likedPages.assign(other.likedPages.begin(), other.likedPages.end());

	}
	return *this;
}


void Friend::addStatus(int choice) {
	// Add status to a user
	if (statusChoice::Text < choice && choice > statusChoice::Video)
		throw StatusException(ErrorCodeStatus::InvalidChoice);
	cout << "What is your status?" << endl;
	string text;
	photoStat* s;
	videoStat* v;
	Status* u;
	string path;
	cin.ignore();
	getline(cin,text);
	switch (choice)
	{
		case statusChoice::Image:
			cout << "Enter photo path" << endl;
			getline(cin, path);
			s = new photoStat(text, path);
			statuses.push_back(s);
			break;
		case statusChoice::Video:
			cout << "Enter video path" << endl;
			getline(cin, path);
			v = new videoStat(text, path);
			statuses.push_back(v);
			break;
		default: 
			u = new Status(text);
			statuses.push_back(u);
			break;
		break;
	}

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

bool Friend::operator>(Friend* _friend) {
	if (this->getAmountOfFriends() > _friend->getAmountOfFriends())
		return true;
	else
		return false;
}

bool Friend::operator>(Pages* _page)
{
	if (this->getAmountOfFriends() > _page->getAmountOfFans())
		return true;
	else
		return false;
}

const int Friend::getAmountOfFriends() const
{
	return friends.size();
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

void Friend::PrintFriendStatus() const
{
	// print the statuses
	for (int i = statuses.size() - 1; i >= 0; i--)
		this->statuses[i]->printStatus();
}

void Friend::getFriendName() const
{
	// get friend name
	cout << this->fname << " " << this->lname << endl;
}

const string Friend::getFName() const
{
	return this->fname;
}

const string Friend::getLName() const
{
	return this->lname;
}

void Friend::showMyFriends() const
{
	// Print all my friends
	for (int i = 0; i < friends.size(); i++) {
		friends[i]->getFriendName();
	}
}

void Friend::mostUpdatedStatuses() const
{
	// print 10 most updated statuses of all friends
	int num, x = 10;
	for (int i = 0; i < friends.size(); i++) {
		num = friends[i]->statuses.size() - 1;
		for (int j = num; j>=0 && x>=0; j-- , x--)
			friends[i]->statuses[j]->printStatus();
	}
}

Date Friend::getDob() const
{//returns the date of birth
	return this->dob;
}

Friend& Friend::operator+=(const Friend& other)
{
	this->addFriend((Friend*)&other,true);
	return *this;
}


Friend& Friend::operator+=(const Pages& other)
{
	this->likePage((Pages*)&other,true);
	return *this;
}

Friend::~Friend() {
	// delete constractor
	for (int i = 0; i < statuses.size(); i++)
			delete (statuses[i]);
}

void Friend::writeToFileFriend(ofstream& file)
{
	Date d = getDob();
	file << fname << " ";
	file << lname << " ";
	file << d.getDay() << " ";
	file << d.getMonth() << " ";
	file << d.getYear() << " ";
	file << statuses.size() << " ";
	for (int i = 0; i < statuses.size(); i++)
	{
		file << statuses[i]->getType();
		file << statuses[i]->getText();
		if (statuses[i]->getType() == statusChoice::Image)
		{
			photoStat* p = (photoStat*)statuses[i];
			file << p->getPath() << " ";
		}
		else if (statuses[i]->getType() == statusChoice::Video)
		{
			videoStat* v = (videoStat*)statuses[i];
			file << v->getPath() << " ";
		}
		file << endl;
	}
	file << friends.size() << " ";
	for (int i = 0; i < friends.size(); i++)
	{
		file << friends[i]->getFName() << " ";
		file << friends[i]->getLName() << " ";
	}
	file << endl; // end of friend! seperate by new line
}

void Friend::readStatus(ifstream& file) {
	// read statuses from file
	int type;
	string statusText;
	string path;
	file >> type;
	getline(file , statusText);
	if (type == statusChoice::Image)
	{
		getline(file, path);
		photoStat* photoStatus = new photoStat(statusText, path);
		statuses.push_back(photoStatus);
	}
	else if (type == statusChoice::Video)
	{
		getline(file, path);
		videoStat* videoStatus = new videoStat(statusText, path);
		statuses.push_back(videoStatus);
	}
	else
	{
		Status* s = new Status(statusText);
		statuses.push_back(s);
	}
}

void Friend::showPagesLiked() {
	// show the pages the user liked
	for (int i = 0; i < likedPages.size(); i++)
		likedPages[i]->getPageName() ;
}