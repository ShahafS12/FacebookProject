#include "Pages.h"

Pages::Pages(char* _name) : name(_strdup(_name)) {}


void Pages::addStatus() {
	char text[MAX_STATUS];
	cout << "What is your status?" << endl;
	cin.ignore();
	cin.getline(text, MAX_STATUS);
	Status* s = new Status(text);
	checkSizeStatus();
	status[numOfStatus] = s;
	numOfStatus++;
}


void Pages::checkSizeStatus() {
	if (this->phyS_status == this->numOfStatus)
	{
		this->phyS_status *= 2;
		Status** tmp = new Status * [phyS_status];

		for (int i = 0; i < numOfStatus; i++)
			tmp[i] = status[i];

		delete[] status;
		status = tmp;
	}
}

void Pages::PrintPagesStatus() {
	// Print the page statuses
	for (int i = 0; i < numOfStatus; i++)
		this->status[i]->printStatus();
}

void Pages::showMyFans() {
	// print all the fans (Friends)
	for (int i = 0; i < numOfFans; i++) {
		fans[i]->getFriendName();
	}
}

void Pages::getPageName() {
	// get friend name
	cout << this->name << endl;
}