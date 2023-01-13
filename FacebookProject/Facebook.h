#include "Pages.h"
#include <vector>
#include <string>
#include "FacebookException.h"

using namespace std;

class Facebook {
private:
	vector<Friend*> friends;
	vector<Pages*> pagesLiked;
public:
	Facebook() {};
	void addDefaultData();
	void addUser();
	void addFanPage();
	void showMembers();
	void showPages();
	void menu();
	void leaveFacebook();
	Friend* findFriend(string fname, string lname);
	void saveData();
	void loadData();
private:
	void addDefaultPages();
	void addDefaultFriends(Pages* p1, Pages* p2, Pages* p3);
	void preformAction(int actionCode);
	void printMenu();
	Date addDate();
	bool nameExists(string fname, string lname);
	void addName(string fname, string lname);
	void checkUsersExist(int user);
	void checkPageExist(int page);
};