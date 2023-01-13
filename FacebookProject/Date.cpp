#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <chrono>
#include <iostream>
#include <ctime>
using namespace std;

Date::Date(short int _day, short int _month, short int _year) : day(_day), month(_month), year(_year) {}

Date::Date() {
    std::time_t t = std::time(0);  // get time now
    std::tm* now = std::localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
}

void Date::printDate() {
    cout << day << "." << month << "." << year << endl;
}

short int Date::getDay() {
	return day;
}
short int Date::getMonth() {
	return month;
}
short int Date::getYear() {
	return year;
}