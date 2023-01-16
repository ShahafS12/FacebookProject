#include "Facebook.h"
using namespace std;

void Facebook::addUser()
{
	char fname[MAX_NAME], lname[MAX_NAME];
	Date d;
	cout << "Enter first name" << endl;
	cin >> fname;
	cout << "Enter last name" << endl;
	cin >> lname;
	if (nameExists(fname, lname))
		throw FacebookException(FacebookErrorCode::InvalidName);
	cout << "Enter your date of birth" << endl;
	char a = getchar(); // The only way cin working after...
		d = addDate();
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
		throw FacebookException(FacebookErrorCode::InvalidDate);
	Date res(day, month, year);
	return res;
}

void Facebook::addName(string fname, string lname)
{
	cout << "Enter first name" << endl;
	cin >> fname;
	cout << "Enter last name" << endl;
	cin >> lname;
	if (nameExists(fname, lname))
		throw FacebookException(FacebookErrorCode::InvalidName);
}

bool Facebook::nameExists(string fname, string lname)
{
	for (int i = 0; i < friends.size(); i++)
	{
		if(!(fname.compare(friends[i]->getFName())&&lname.compare(this->friends[i]->getLName())))
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
	pagesLiked.push_back(p);
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
	for (int i = 0; i < pagesLiked.size(); i++) {
		cout << i + 1 << "-";
		pagesLiked[i]->getPageName();
	}
}

void Facebook::menu()
{ // The menu of the Facebook
	int action;
	printMenu();
	cin >> action;
	preformAction(action);
	cout << "\n" << endl;
	if (action != 15) //15 means exit
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
		throw FacebookException(FacebookErrorCode::InvalidValue);
}

void Facebook::checkPageExist(int page)
{
	// check if the users exist
	if (page > pagesLiked.size() || page < 1)
		throw FacebookException(FacebookErrorCode::InvalidValue);
}

void Facebook::preformAction(int actionCode)
{//preforms action according to chosen action code
	int user,page,secondUser, choice;
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
			cout << "What kind of status you want to add?" << endl;
			cout << "1-Text status" << endl;
			cout << "2-Photo status" << endl;
			cout << "3-Video status" << endl;
			cin >> choice;
			friends[user - 1]->addStatus(choice);
			break;
		case 4:
			cout << "Choose a page" << endl;
			showPages();
			cin >> page;
			checkPageExist(page);
			cout << "What kind of status you want to add?" << endl;
			cout << "1-Text status" << endl;
			cout << "2-Photo status" << endl;
			cout << "3-Video status" << endl;
			cin >> choice;
			pagesLiked[page - 1]->addStatus(choice);
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
			pagesLiked[page - 1]->PrintPagesStatus();
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
			pagesLiked[page - 1]->addFan(friends[user - 1], true);
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
			pagesLiked[page - 1]->removeFan(friends[user - 1], true);
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
			pagesLiked[page - 1]->showMyFans();
			break;
		case 15:
			leaveFacebook();
			break;
		default:
			cout << "invalid action";
		}
	}
	catch (friendException e)
	{
		cout << e.what() << endl;
	}
	catch (pagesException e)
	{
		cout << e.what() << endl;
	}
	catch (FacebookException e)
	{
		cout << e.what() << endl;
	}
	catch (StatusException e)
	{
		cout << e.what() << endl;
	}
}

void Facebook::saveData()
{ //save data to file
	std::ofstream outFile("data.txt");
	// Write the number of friends to the file
	int numFriends = friends.size();
	Date d;
	outFile << numFriends << endl;
	for (auto _friends : friends)
	{
		_friends->writeToFileFriend(outFile);
	}
	// Write the number of pages to the file
	int numPages = pagesLiked.size();
	outFile << numPages << endl;
	for (auto _pages : pagesLiked)
	{
		_pages->writeToFilePages(outFile);
	}
	outFile.close();
}

void Facebook::loadData() {
	//load data from file
	ifstream inFile("data.txt");
	if (!inFile)
	{
		throw FacebookException(FacebookErrorCode::ErrorOpeningFile);
	}
	int numUsers, numPages;
	inFile >> numUsers;
	for (int i = 0; i < numUsers; i++)
	{
		string fName, lName;
		int month, day, year, numOfStatueses, numOfFriends, numOfFans;
		inFile >> fName >> lName >> day >> month >> year;
		Date d(month, day, year);
		Friend* f = new Friend(fName, lName, d);
		friends.push_back(f);
		inFile >> numOfStatueses;

		for (int i = 0; i < numOfStatueses; i++) {
			f->readStatus(inFile);
		}

		inFile >> numOfFriends;
		for (int i = 0; i < numOfFriends; i++) {
			inFile >> fName >> lName;
			Friend* findF = findFriend(fName, lName);
			if (findF != nullptr) {
				f->addFriend(findF, true);
			}
		}
	}
	inFile >> numPages;
	string pName, x; // x is for jumping a line in the file
	getline(inFile, x);
	for (int i = 0; i < numPages; i++) {
		getline(inFile, pName);
		Pages* p = new Pages(pName);
		pagesLiked.push_back(p);
		int numOfStatuses;
		inFile >> numOfStatuses;
		for (int i = 0; i < numOfStatuses; i++) {
			p->readStatus(inFile);
		}
		//cin.ignore();
		//getline(inFile, x);
		int numOfFans;
		inFile >> numOfFans;
 		for (int i = 0; i < numOfFans; i++) {
			string fName, lName;
			inFile >> fName >> lName;
			Friend* findF = findFriend(fName, lName);
			p->addFan(findF, true);
		}
		getline(inFile, x);
	}
}

void Facebook::leaveFacebook() {
	// Delete all the allocations + save the data to a file
	saveData();
}

Facebook::~Facebook()
{
	for (int i = 0; i < friends.size(); i++)
		delete (friends[i]);

	for (int i = 0; i < pagesLiked.size(); i++)
		delete (pagesLiked[i]);
}

Friend* Facebook::findFriend(string fname, string lname)
{ //find and return friend by name 
	for (int i = 0; i < friends.size(); i++)
	{
		if (!(fname.compare(friends[i]->getFName()) && lname.compare(this->friends[i]->getLName())))
			return (friends[i]);
	}
	return nullptr;
}