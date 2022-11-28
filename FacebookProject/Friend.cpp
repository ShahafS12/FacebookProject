#include "Friend.h"

Friend::Friend(char* _fname, char* _lname, Date _dob) : fname(_strdup(_fname)), lname(_strdup(_lname)), dob(_dob) {}

void Friend::addStatus() {
	char text[MAX_STATUS];
	cout << "What is your status?" << endl;
	cin.ignore();
	cin.getline(text, MAX_STATUS);
	Status* s = new Status(text);
	checkSizeStatus();
	statuses[numOfStatus] = s;
	numOfStatus++;
}


void Friend::checkSizeStatus() {
	if (this->phyS_status == this->numOfStatus)
	{
		this->phyS_status *= 2;
		Status** tmp = new Status * [phyS_status];
		for (int i = 0; i < numOfStatus; i++)
			tmp[i] = statuses[i];

		//tmp = statuses; // copy constractur ESENIEAL 
		delete[] statuses;
		statuses = tmp;
	}
}

void Friend::PrintFriendStatus() {
	for (int i = 0; i < numOfStatus; i++)
		this->statuses[i]->printStatus();
}