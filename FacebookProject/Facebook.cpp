#include "Facebook.h"

void Facebook::addUser()
{
	char fname[MAX_NAME], lname[MAX_NAME];
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

void Facebook::addDefaultData()
{
	addDefaultPages();
	addDefaultFriends();
}

void Facebook::addDefaultPages()
{
	char pname1[MAX_PAGE_NAME] = "Justin to israel";
	char pname2[MAX_PAGE_NAME] = "Hapshuta";
	char pname3[MAX_PAGE_NAME] = "Lemons cummunity";
	Pages* p1 = new Pages(pname1);
	checkSizePages();
	pages[numOfPages] = p1;
	numOfPages++;
	Pages* p2 = new Pages(pname2);
	checkSizePages();
	pages[numOfPages] = p2;
	numOfPages++;
	Pages* p3 = new Pages(pname3);
	checkSizePages();
	pages[numOfPages] = p3;
	numOfPages++;
}

void Facebook::addDefaultFriends()
{//still needs to like pages for those friends
	Date d1(19, 9, 1999);
	Date d2(1, 11, 1997);
	Date d3(1, 4, 1985);
	char fname1[MAX_NAME] = "Shahaf";
	char fname2[MAX_NAME] = "Tomer";
	char fname3[MAX_NAME] = "Justin";
	char lname1[MAX_NAME] = "Shabo";
	char lname2[MAX_NAME] = "Klein";
	char lname3[MAX_NAME] = "Bieber";
	Friend* f1 = new Friend(fname1, lname1, d1);
	f1->addTwoDefaultStatus();
	checkSizeFriends();
	friends[numOfFriends] = f1;
	numOfFriends++;
	Friend* f2 = new Friend(fname2, lname2, d2);
	f2->addTwoDefaultStatus();
	f2->addFriend(f1);
	checkSizeFriends();
	friends[numOfFriends] = f2;
	numOfFriends++;
	Friend* f3 = new Friend(fname3, lname3, d3);
	f3->addTwoDefaultStatus();
	f3->addFriend(f2);
	checkSizeFriends();
	friends[numOfFriends] = f3;
	numOfFriends++;
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