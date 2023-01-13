#pragma once
#include "Status.h"

class videoStat : public Status {
private:
    ifstream file;
    string fileName;
public:
    videoStat(string text, string video);
    void showVideo();
    ~videoStat();
    string getPath();

};