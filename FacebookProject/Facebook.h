#include "Pages.h"
#include <vector>
#include <string>
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
