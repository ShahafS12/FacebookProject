#include "Facebook.h"
using namespace std;

void Facebook::addUser()
{
	char fname[MAX_NAME], lname[MAX_NAME];
	Date d;
	try
	{
		addName(fname, lname);
	}
	catch (const char* msg)
	{
		cout << msg << " try again:" << endl;
		addName(fname, lname);
	}
	cout << "Enter your date of birth" << endl;
	char a = getchar(); // The only way cin working after...
	try
	{
		d = addDate();
	}
	catch (const char* msg)
	{
		cout << msg << " try again:" << endl;
		d = addDate();
	}
	Friend* f = new Friend(fname, lname, d);
	friends.push_back(f); // constracor copy 
}

Date Facebook::addDate()
{
	short int day, month, year;
	cout << "Day:"; cin >> day;
	cout << "Month:"; cin >> month;
	cout << "Year:"; cin >> year;
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2017)
		throw "Invalid date";
	Date res(day, month, year);
	return res;
}

void Facebook::addName(char* fname,char* lname)
{
	cout << "Enter first name" << endl;
	cin >> fname;
	cout << "Enter last name" << endl;
	cin >> lname;
	if (nameExists(fname, lname))
		throw "Name already in use";
}

bool Facebook::nameExists(char* fname, char* lname)
{
	for (int i = 0; i < friends.size(); i++)
	{
		if(!strcmp(fname,this->friends[i]->getFName())&& !strcmp(lname, this->friends[i]->getLName()))
			return true;
	}
	return false;
}

void Facebook::addFanPage() {
	// Add fan page to pages on facebook
	char name[MAX_PAGE_NAME];
	cout << "Enter name of fan page: " << endl;
	char a = getchar(); // The only way cin working after...
	cin.getline(name, MAX_PAGE_NAME);
	Pages* p = new Pages(name);
	pages.push_back(p);
}


void Facebook::addDefaultData()
{ // add deafalt data to facebook
	addDefaultPages();
	addDefaultFriends(pages[0],pages[1],pages[2]);
}

void Facebook::addDefaultPages()
{   // A function to add default pages
	char pname1[MAX_PAGE_NAME] = "Justin to israel";
	char pname2[MAX_PAGE_NAME] = "Hapshuta";
	char pname3[MAX_PAGE_NAME] = "Lemons cummunity";
	Pages* p1 = new Pages(pname1);
	pages.push_back(p1);
	Pages* p2 = new Pages(pname2);
	pages.push_back(p2);
	Pages* p3 = new Pages(pname3);
	pages.push_back(p3);
}

void Facebook::addDefaultFriends(Pages* p1, Pages* p2, Pages* p3)
{// still needs to like pages for those friends
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
	f1->likePage(p1,true);
	f1->likePage(p2, true);
	friends.push_back(f1);
	Friend* f2 = new Friend(fname2, lname2, d2);
	f2->addTwoDefaultStatus();
	f2->likePage(p3, true);
	f2->addFriend(f1,true);
	friends.push_back(f2);
	Friend* f3 = new Friend(fname3, lname3, d3);
	f3->addTwoDefaultStatus();
	f3->likePage(p1, true);
	f3->addFriend(f2,true);
	friends.push_back(f3);
}

void Facebook::showMembers() {
	// Print all members in Facebook
	for (int i = 0; i < friends.size(); i++) {
		cout << i+1<<"-";
		friends[i]->getFriendName();
	}
}

void Facebook::showPages() {
	// Print all pages in Facebook
	for (int i = 0; i < pages.size(); i++) {
		cout << i + 1 << "-";
		pages[i]->getPageName();
	}
}

void Facebook::menu()
{ // The menu of the Facebook
	int action;
	printMenu();
	cin >> action;
	preformAction(action);
	cout << "\n" << endl;
	if (action != 15)//15 means exit
		menu();
}

void Facebook::printMenu()
{//prints actions menu for user to pick from
	cout << "Welcome to Facebook.\nChoose action" << endl;
	cout << "1-add new user" << endl;
	cout << "2-add new fan page" << endl;
	cout << "3-add new status to a friend" << endl;
	cout << "4-add new status to a page" << endl;
	cout << "5-show my friends 10 recent statuses" << endl;
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
}

void Facebook::checkUsersExist(int user)
{
	// check if the users exist
	if (user > friends.size() || user < 1)
		throw "invalid values";
}

void Facebook::checkPageExist(int page)
{
	// check if the users exist
	if (page > pages.size() || page < 1)
		throw "invalid values";
}

void Facebook::preformAction(int actionCode)
{//preforms action according to chosen action code
	int user,page,secondUser;
	try
	{
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
			checkUsersExist(user);
			friends[user - 1]->addStatus();
			break;
		case 4:
			cout << "Choose a page" << endl;
			showPages();
			cin >> page;
			checkPageExist(page);
			pages[page - 1]->addStatus();
			break;
		case 5:
			cout << "Choose a user" << endl;
			showMembers();
			cin >> user;
			checkUsersExist(user);
			friends[user - 1]->mostUpdatedStatuses();
			break;
		case 6:
			cout << "Choose a page" << endl;
			showPages();
			cin >> page;
			checkPageExist(page);
			pages[page - 1]->PrintPagesStatus();
			break;
		case 7:
			cout << "Choose a user" << endl;
			showMembers();
			cin >> user;
			checkUsersExist(user);
			friends[user - 1]->PrintFriendStatus();
			break;
		case 8:
			cout << "Choose two users to connect - Type both numbers" << endl;
			showMembers();
			cin >> user;
			cin >> secondUser;
			checkUsersExist(secondUser);
			checkUsersExist(user);
			friends[user - 1]->addFriend(friends[secondUser - 1], true);
			break;
		case 9:
			cout << "Choose two users remove friendship" << endl;
			showMembers();
			cin >> user;
			cin >> secondUser;
			checkUsersExist(secondUser);
			checkUsersExist(user);
			friends[user - 1]->removeFriend(friends[secondUser - 1], true);
			break;
		case 10:
			cout << "Choose a page to like" << endl;
			showPages();
			cin >> page;
			checkPageExist(page);
			cout << "choose a user to like chosen page" << endl;
			showMembers();
			cin >> user;
			checkUsersExist(user);
			pages[page - 1]->addFan(friends[user - 1], true);
			break;
		case 11:
			cout << "Choose a page to unlike" << endl;
			showPages();
			cin >> page;
			checkPageExist(page);
			cout << "choose a user to unlike chosen page" << endl;
			showMembers();
			cin >> user;
			checkUsersExist(user);
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
			checkUsersExist(user);
			friends[user - 1]->showMyFriends();
			break;
		case 14:
			cout << "Choose a page" << endl;
			showPages();
			cin >> page;
			checkPageExist(page);
			pages[page - 1]->showMyFans();
			break;
		case 15:
			leaveFacebook();
			break;
		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

void Facebook::leaveFacebook() {
	// Delete all the allocations
	for (int i = 0; i < friends.size(); i++)
			delete (friends[i]);

	for (int i = 0; i < pages.size(); i++)
		delete (pages[i]);

	exit(1);
}