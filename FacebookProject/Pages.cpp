#include "Pages.h"

Pages::Pages(string& _name) : name(_name) {}

Pages::~Pages() {
	// delete constructor
	for (int i = 0; i < status.size(); i++)
		delete (status[i]);
}

void Pages::addStatus(int choice) {
	// add status to page
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
		status.push_back(s);
		break;
	case statusChoice::Video:
		cout << "Enter video path" << endl;
		getline(cin, path);
		v = new videoStat(text, path);
		status.push_back(v);
		break;
	default:
		u = new Status(text);
		status.push_back(u);
		break;
		break;
	}

}

void Pages::PrintPagesStatus()  const
{
	// Print the page statuses
	int statType;
	for (int i = 0; i < status.size(); i++)
	{
		status[i]->printStatus();
	}
}

void Pages::showMyFans() const
{
	// print all the fans (Friends)
	for (int i = 0; i < fans.size(); i++) {
		fans[i]->getFriendName();
	}
}

void Pages::getPageName() const
{
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
		throw pagesException(ErrorCodePages::pageAlreadyLike);
}

bool Pages::isFan(Friend* const _friend) const
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
	}
		if (!foundFriend)
			throw pagesException(ErrorCodePages::notFan);
}

bool Pages::operator>(Pages* _page) {
	if (this->getAmountOfFans() > _page->getAmountOfFans())
		return true;
	else
		return false;
}

const int Pages::getAmountOfFans() {
	return this->fans.size();
}

void Pages::writeToFilePages(ofstream& file) {
	// write to file
	file << this->name << " ";
	file << endl;
	file << this->status.size() << " " << endl;
	for (int i = 0; i < this->status.size(); i++)
	{
		file << this->status[i]->getType() << " ";
		file << this->status[i]->getText() << " " << endl;
		if (this->status[i]->getType() == statusChoice::Image)
		{
			photoStat* p = (photoStat*)status[i];
			file << p->getPath() << " ";
		}
		else if (this->status[i]->getType() == statusChoice::Video)
		{
			videoStat* v = (videoStat*)status[i];
			file << v->getPath() << " ";
		}
		file << endl;
	}
	file << this->fans.size() << " ";
	for (int i = 0; i < fans.size(); i++) {
		file << fans[i]->getFName() << " ";
		file << fans[i]->getLName() << " ";
	}
	file << endl;
}


void Pages::readStatus(ifstream& file) {
	// read statuses from file
	int type;
	string statusText;
	string path;
	file >> type;
	getline(file, statusText);
	if (type == statusChoice::Image)
	{
		getline(file, path);
		photoStat* photoStatus = new photoStat(statusText, path);
		status.push_back(photoStatus);
	}
	else if (type == statusChoice::Video)
	{
		getline(file, path);
		videoStat* videoStatus = new videoStat(statusText, path);
		status.push_back(videoStatus);
	}
	else
	{
		Status* s = new Status(statusText);
		status.push_back(s);
	}
}