#pragma once

class Date {
private:
	short int day, month, year;
public:
	Date(short int _day, short int _month, short int _year);
	Date();
	short int getDay();
	short int getMonth();
	short int getYear();
	Date getDate();
	void printDate();
	const Date& operator=(const Date& other);
};

