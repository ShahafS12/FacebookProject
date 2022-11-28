#include "Facebook.h"

void Facebook::addUser()
{
	char fname[15], lname[15];
	short int day, month, year;

	cout << "Enter first name" << endl;
	cin >> fname;
	cout << "Enter last name" << endl;
	cin >> lname;
	cout << "Enter your date of birth" << endl;
	cout << "Day:"; cin >> day;
	cout << "Month:"; cin >> month;
	cout << "Year:"; cin >> year;
	Date d(day, month, year);
	Friend* f = new Friend(fname, lname, d);
	checkSizeFriends();
	friends[numOfFriends] = f; // constracor copy 
	numOfFriends++;
}

void Facebook::addFanPage() {
	char name[MAX_PAGE_NAME];
	cout << "Enter name of fan page: " << endl;
	cin.getline(name, MAX_PAGE_NAME);
	Pages* p = new Pages(name);
	checkSizePages();
	pages[numOfPages] = p;
	numOfPages++;
}


void Facebook::checkSizePages() {
	if (this->phyS_pages == this->numOfPages)
	{
		this->phyS_pages *= 2;
		Pages** tmp = new Pages * [phyS_pages];

		for (int i = 0; i < numOfPages; i++)
			tmp[i] = pages[i];

		delete[] pages;
		pages = tmp;
	}
}
void Facebook::checkSizeFriends() {
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