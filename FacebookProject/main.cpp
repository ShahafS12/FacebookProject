#include "Facebook.h"

int main() {
	Facebook f;
	f.addUser();
	f.friends[0]->addStatus();
	f.friends[0]->addStatus();
	f.friends[0]->addStatus();
	f.friends[0]->addStatus();
	f.friends[0]->addStatus();


	f.friends[0]->PrintFriendStatus();
	return 0;
}