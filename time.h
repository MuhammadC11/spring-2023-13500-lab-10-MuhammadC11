#include <iostream>
#pragma once

class Time
{
public:
    int hour;
    int minute;
};

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
