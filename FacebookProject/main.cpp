#include "Facebook.h"

int main() {
	Facebook f;
	f.addDefaultData();
	f.friends[0]->PrintFriendStatus();
	f.friends[2]->PrintFriendStatus();
	return 0;
}