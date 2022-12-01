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
	char a = getchar(); // The only way cin working after...
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
	addDefaultFriends(pages[0],pages[1],pages[2]);
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

void Facebook::addDefaultFriends(Pages* p1, Pages* p2, Pages* p3)
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
	//f1->likePage(p1,true);
	//f1->likePage(p2, true);
	checkSizeFriends();
	friends[numOfFriends] = f1;
	numOfFriends++;
	Friend* f2 = new Friend(fname2, lname2, d2);
	f2->addTwoDefaultStatus();
	//f2->likePage(p3, true);
	f2->addFriend(f1,true);
	checkSizeFriends();
	friends[numOfFriends] = f2;
	numOfFriends++;
	Friend* f3 = new Friend(fname3, lname3, d3);
	f3->addTwoDefaultStatus();
	//f3->likePage(p1, true);
	f3->addFriend(f2,true);
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

void Facebook::showMembers() {
	// Print all members in Facebook
	for (int i = 0; i < numOfFriends; i++) {
		cout << i+1<<"-";
		friends[i]->getFriendName();
	}
}

void Facebook::showPages() {
	// Print all pages in Facebook
	for (int i = 0; i < numOfPages; i++) {
		cout << i + 1 << "-";
		pages[i]->getPageName();
	}
}

void Facebook::menu()
{
	int action;
	cout << "Welcome to Facebook.\nChoose action" << endl;
	cout << "1-add new user" << endl;
	cout << "2-add new fan page" << endl;
	cout << "3-add new status to a friend" << endl;
	cout << "4-add new status to a page" << endl;
	cout << "5-show friend 10 recent statuses" << endl;
	cout << "6-show page's statuses" << endl;
	cout << "7-show friend's feed" << endl;
	cout << "8-add a friend" << endl;
	cout << "9-remove a friend" << endl;
	cout << "10-like a page" << endl;
	cout << "11-unlike a page" << endl;
	cout << "12-show all users and pages" << endl;
	cout << "13-show a friend's friend list" << endl;
	cout << "14-show fans of a page" << endl;
	cout << "15-exit\n" << endl;
	cin >> action;
	preformAction(action);
}

void Facebook::preformAction(int actionCode)
{
	int user,page,secondUser;
	switch (actionCode)
	{
	case 1:
		addUser();
		break;
	case 2:
		addFanPage();
		break;
	case 3:
		cout << "Choose a user" << endl;
		showMembers();
		cin >> user;
		friends[user - 1]->addStatus();
		break;
	case 4:
		cout << "Choose a page" << endl;
		showPages();
		cin >> page;
		pages[page - 1]->addStatus();
		break;
	case 5:
		cout << "Choose a user" << endl;
		showMembers();
		cin >> user;
		friends[user - 1]->mostUpdatedStatuses();
		break;
	case 6:
		cout << "Choose a page" << endl;
		showPages();
		cin >> page;
		pages[page - 1]->PrintPagesStatus();
		break;
	case 7:
		cout << "Choose a user" << endl;
		showMembers();
		cin >> user;
		friends[user - 1]->PrintFriendStatus();
		break;
	case 8:
		cout << "Choose two users to connect" << endl;
		showMembers();
		cin >> user;
		cin >> secondUser;
		friends[user - 1]->addFriend(friends[secondUser - 1], true);
		break;
	case 9:
		cout << "Choose two users remove friendship" << endl;
		showMembers();
		cin >> user;
		cin >> secondUser;
		friends[user - 1]->removeFriend(friends[secondUser - 1], true);
		break;
	case 10:
		cout << "Choose a page to like" << endl;
		showPages();
		cin >> page;
		cout << "choose a user to like chosen page" << endl;
		showMembers();
		cin >> user;
		pages[page - 1]->addFan(friends[user - 1], true);
		break;
	case 11:
		cout << "Choose a page to unlike" << endl;
		showPages();
		cin >> page;
		cout << "choose a user to unlike chosen page" << endl;
		showMembers();
		cin >> user;
		pages[page - 1]->removeFan(friends[user - 1], true);
		break;
	case 12:
		cout << "Users:" << endl;
		showMembers();
		cout << "Pages:" << endl;
		showPages();
		break;
	case 13:
		cout << "Choose a user" << endl;
		showMembers();
		cin >> user;
		friends[user - 1]->showMyFriends();
		break;
	case 14:
		cout << "Choose a page" << endl;
		showPages();
		cin >> page;
		pages[page - 1]->showMyFans();
		break;
	case 15:
		exit();
		break;
	}
}

void Facebook::exit() {
	// Delete all the allocations
	for (int i = 0; i < numOfFriends; i++)
			delete (friends[i]);
	delete[] friends;

	for (int i = 0; i < numOfPages; i++)
		delete (pages[i]);
	delete[] pages;
}