#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include <chrono>
#include <iostream>
#include <ctime>
using namespace std;

Time::Time() {
    std::time_t t = std::time(0);  // get time now
    std::tm* now = std::localtime(&t);
    hour = now->tm_hour;
    minute = now->tm_min;
}

void Time::printTime() {
    cout << hour << ":" << minute << endl;
}