#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"
int minutesSinceMidnight(Time time)
{
    return time.hour * 60 + time.minute; // 60 minutes in an hour so we multiply the hour by 60 and add the minutes to get the total minutes
}

int minutesUntil(Time earlier, Time later)
{
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier); // we can use the previous function to get the minutes since midnight for both times and subtract them to get the difference
}

Time addMinutes(Time time0, int min)
{
    time0.minute += min;             // add the minutes to the time
    time0.hour += time0.minute / 60; // if the minutes are greater than 60, we add the quotient to the hour
    time0.minute %= 60;              // we take the remainder of the minutes to get the minutes that are less than 60
    time0.hour %= 24;                // we take the remainder of the hour to get the hour that is less than 24
    return time0;
}

void printMovie(Movie mv)
{
    std::string g;
    switch (mv.genre)
    {
    case ACTION:
        g = "ACTION";
        break;
    case COMEDY:
        g = "COMEDY";
        break;
    case DRAMA:
        g = "DRAMA";
        break;
    case ROMANCE:
        g = "ROMANCE";
        break;
    case THRILLER:
        g = "THRILLER";
        break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

std::string getTimeSlot(TimeSlot ts)
{
    std::string g;
    switch (ts.movie.genre)
    {
    case ACTION:
        g = "ACTION";
        break;
    case COMEDY:
        g = "COMEDY";
        break;
    case DRAMA:
        g = "DRAMA";
        break;
    case ROMANCE:
        g = "ROMANCE";
        break;
    case THRILLER:
        g = "THRILLER";
        break;
    }
    return ts.movie.title + " " + g + " (" + std::to_string(ts.movie.duration) + " min) [starts at " + std::to_string(ts.startTime.hour) + ":" + std::to_string(ts.startTime.minute) + ", ends by " + std::to_string(addMinutes(ts.startTime, ts.movie.duration).hour) + ":" + std::to_string(addMinutes(ts.startTime, ts.movie.duration).minute) + "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    TimeSlot t;
    t.movie = nextMovie;
    t.startTime = addMinutes(ts.startTime, ts.movie.duration);
    return t;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    if (minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime)) // if the first time slot starts before the second time slot
    {
        if (minutesSinceMidnight(ts1.startTime) + ts1.movie.duration > minutesSinceMidnight(ts2.startTime)) // if the first time slot ends after the second time slot starts
        {
            return true; // then there is an overlap between the two time slots
        }
    }
    else
    {
        if (minutesSinceMidnight(ts2.startTime) + ts2.movie.duration > minutesSinceMidnight(ts1.startTime)) // if the second time slot ends after the first time slot starts
        {
            return true; // then there is an overlap between the two time slots
        }
    }
    return false; // if there is no overlap between the two time slots
}

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
    Time t3 = addMinutes(t1, 75);
    std::cout << t3.hour << ":" << t3.minute << std::endl;

    return 0;
}