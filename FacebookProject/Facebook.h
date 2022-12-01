#include "Pages.h"

class Facebook {
public: // ** SHOULD CHANGE IT TO PRIVATE **
	Friend** friends = new Friend*;
	int phyS_friends = 1;
	int numOfFriends = 0;
	Pages** pages = new Pages*;
	int phyS_pages = 1;
	int numOfPages = 0;
public:
	Facebook() {};
	void addDefaultData();
	void addUser();
	void checkSizeFriends();
	void checkSizePages();
	void addFanPage();
	void showMembers();
	void showPages();
	void menu();
private:
	void addDefaultPages();
	void addDefaultFriends(Pages* p1, Pages* p2, Pages* p3);
	void preformAction(int actionCode);
};
