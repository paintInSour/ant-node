#ifndef TIMEUTIL_H
#define TIMEUTIL_H
#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;


class TimeUtil
{
public:
    TimeUtil();
    static long getTime(){
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }

};

#endif // TIMEUTIL_H
