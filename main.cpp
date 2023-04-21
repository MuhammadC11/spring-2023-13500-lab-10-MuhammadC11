#include <iostream>
#include "time.h"

int main()
{
    Time t1;
    t1.hour = 10;
    t1.minute = 30;

    Time t2;
    t2.hour = 11;
    t2.minute = 30;

    std::cout << minutesSinceMidnight(t1) << std::endl;
    std::cout << minutesSinceMidnight(t2) << std::endl;
    std::cout << minutesUntil(t1, t2) << std::endl;

    return 0;
}