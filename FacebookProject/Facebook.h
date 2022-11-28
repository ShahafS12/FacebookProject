#include "Pages.h"

class Facebook {
public:
	Friend** friends = new Friend*;
	int phyS_friends = 1;
	int numOfFriends = 0;
	Pages** pages = new Pages*;
	int phyS_pages = 1;
	int numOfPages = 0;
public:
	Facebook() {};
	void addUser();
	void checkSizeFriends();
	void checkSizePages();
	void addFanPage();
};
