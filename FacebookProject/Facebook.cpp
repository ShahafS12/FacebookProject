#include "Facebook.h"
using namespace std;

Facebook::Facebook(const Facebook& other) {
	// copy ctor
	*this = other;
}

const Facebook& Facebook::operator=(const Facebook& other) {
	// operator = 
	if (this != &other)
	{
		friends.assign(other.friends.begin(), other.friends.end());
		pagesLiked.assign(other.pagesLiked.begin(), other.pagesLiked.end());
	}
	return *this;
}

void Facebook::addUser()
{
	string fname,lname;
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
	if (day < minDay || day > maxDay || month < minMonth || month > maxMonth || year < minYear || year > maxYear)
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
	string name;
	cout << "Enter name of fan page: " << endl;
	char a = getchar(); // The only way cin working after...
	getline(cin, name);
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
	if (action != 16) //15 means exit
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
	cout << "15-show pages of user liked" << endl;
	cout << "16-exit\n" << endl;
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
		case newUser:
			addUser();
			break;
		case addFP:
			addFanPage();
			break;
		case addStatF:
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
		case addStatP:
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
		case show10Recent:
			cout << "Choose a user" << endl;
			showMembers();
			cin >> user;
			checkUsersExist(user);
			friends[user - 1]->mostUpdatedStatuses();
			break;
		case showPstat:
			cout << "Choose a page" << endl;
			showPages();
			cin >> page;
			checkPageExist(page);
			pagesLiked[page - 1]->PrintPagesStatus();
			break;
		case showFstat:
			cout << "Choose a user" << endl;
			showMembers();
			cin >> user;
			checkUsersExist(user);
			friends[user - 1]->PrintFriendStatus();
			break;
		case addFriends:
			cout << "Choose two users to connect - Type both numbers" << endl;
			showMembers();
			cin >> user;
			cin >> secondUser;
			checkUsersExist(secondUser);
			checkUsersExist(user);
			friends[user - 1]->addFriend(friends[secondUser - 1], true);
			break;
		case removeFriend:
			cout << "Choose two users remove friendship" << endl;
			showMembers();
			cin >> user;
			cin >> secondUser;
			checkUsersExist(secondUser);
			checkUsersExist(user);
			friends[user - 1]->removeFriend(friends[secondUser - 1], true);
			break;
		case likePage:
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
		case UnlikePage:
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
		case showAllEntities:
			cout << "Users:" << endl;
			showMembers();
			cout << "Pages:" << endl;
			showPages();
			break;
		case showFlist:
			cout << "Choose a user" << endl;
			showMembers();
			cin >> user;
			checkUsersExist(user);
			friends[user - 1]->showMyFriends();
			break;
		case showFans:
			cout << "Choose a page" << endl;
			showPages();
			cin >> page;
			checkPageExist(page);
			pagesLiked[page - 1]->showMyFans();
			break;
		case showPagesOfUser:
			cout << "Choose a user" << endl;
			showMembers();
			cin >> user;
			showPagesOf(user - 1);
			break;
		case leave:
			leaveFacebook();
			break;
		default:
			cout << "invalid action";
		}
	}
	catch (friendException& e)
	{
		cout << e.what() << endl;
	}
	catch (pagesException& e)
	{
		cout << e.what() << endl;
	}
	catch (FacebookException& e)
	{
		cout << e.what() << endl;
	}
	catch (StatusException& e)
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
		Friend* f = createFriendFromFile(inFile);
		friends.push_back(f);
	}
	inFile >> numPages;
	string pName, x; // x is for jumping a line in the file
	getline(inFile, x);
	for (int i = 0; i < numPages; i++) {
		Pages* p = CreatePageFromFile(inFile);
		pagesLiked.push_back(p);
		getline(inFile, x);
	}
}

Friend* Facebook::createFriendFromFile(ifstream& file)
{
	string fName, lName;
	int month, day, year, numOfStatueses, numOfFriends, numOfFans;
	file >> fName >> lName >> day >> month >> year;
	Date d(month, day, year);
	Friend* f = new Friend(fName, lName, d);
	file >> numOfStatueses;

	for (int i = 0; i < numOfStatueses; i++) {
		f->readStatus(file);
	}

	file >> numOfFriends;
	for (int i = 0; i < numOfFriends; i++) {
		file >> fName >> lName;
		Friend* findF = findFriend(fName, lName);
		if (findF != nullptr) {
			f->addFriend(findF, true);
		}
	}
	return f;
}

Pages* Facebook::CreatePageFromFile(ifstream& file)
{
	string pName;
	int numOfStatuses, numOfFans;
	getline(file, pName);
	Pages* p = new Pages(pName);
	file >> numOfStatuses;
	for (int i = 0; i < numOfStatuses; i++) {
		p->readStatus(file);
	}
	file >> numOfFans;
	for (int i = 0; i < numOfFans; i++) {
		string fName, lName;
		file >> fName >> lName;
		Friend* findF = findFriend(fName, lName);
		p->addFan(findF, true);
	}
	return p;
}

void Facebook::leaveFacebook() {
	//save the data to a file before allocations are deleted
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

void Facebook::showPagesOf(int user) {
	// show the pages that a friend liked
	checkUsersExist(user);
	friends[user]->showPagesLiked();
}