#include "Facebook.h"

int main() {
	Facebook f;
	f.addFanPage();
	f.pages[0]->addStatus();
	f.pages[0]->addStatus();

	f.pages[0]->PrintPagesStatus();
	//f.addDefaultData();
	//f.menu();
	return 0;
}