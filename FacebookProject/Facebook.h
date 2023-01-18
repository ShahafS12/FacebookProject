#include "Pages.h"
#include <vector>
#include <string>
#include "FacebookException.h"

enum menuActions { newUser = 1, addFP, addStatF, addStatP, show10Recent, showPstat, showFstat, addFriends, removeFriend, likePage, UnlikePage, showAllEntities, showFlist, showFans, leave };
enum dateCap { minDay = 1, maxDay = 31, minMonth = 1, maxMonth = 12, minYear = 1900, maxYear = 2017 };

class Facebook {
private:
	vector<Friend*> friends;
	vector<Pages*> pagesLiked;
public:
	Facebook() {};
	Facebook(const Facebook& other);
	void addUser();
	void addFanPage();
	void showMembers();
	void showPages();
	void menu();
	void leaveFacebook();
	Friend* findFriend(string fname, string lname);
	void saveData();
	void loadData();
	~Facebook();
	const Facebook& operator=(const Facebook& other);
private:
	void preformAction(int actionCode);
	void printMenu();
	Date addDate();
	bool nameExists(string fname, string lname);
	void addName(string fname, string lname);
	void checkUsersExist(int user);
	void checkPageExist(int page);
	Friend* createFriendFromFile(ifstream& file);
	Pages* CreatePageFromFile(ifstream& file);
};
