#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

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

    Movie movie1 = {"Transformers: Revenge of The Fallen", ACTION, 116};
    Movie movie2 = {"Avengers: Infinity War", ACTION, 134};
    Movie movie3 = {"Demon Slayer: Mugen Train", THRILLER, 194};
    Movie movie5 = {"Avengers Endgame", ACTION, 200};
    TimeSlot morning = {movie1, Time{9, 15}};
    TimeSlot daytime = {movie2, Time{12, 15}};
    TimeSlot evening = {movie1, Time{16, 45}};

    TimeSlot dusk = {movie3, Time{19, 10}};
    TimeSlot night = {movie5, Time{20, 35}};
    std::cout << getTimeSlot(morning) << std::endl; // should print Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
    std::cout << getTimeSlot(daytime) << std::endl; // should print Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]
    std::cout << getTimeSlot(evening) << std::endl; // should print Black Panther ACTION (134 min) [starts at 16:45, ends by 18:41]
    std::cout << getTimeSlot(dusk) << std::endl;    // should print Titanic ROMANCE (194 min) [starts at 19:10, ends by 22:24]
    std::cout << getTimeSlot(night) << std::endl;   // should print Avengers Endgame ACTION (200 min) [starts at 20:45, ends by 23:05]
    // test scheduleAfter
    TimeSlot nextSlot = scheduleAfter(morning, movie2);
    std::cout << getTimeSlot(nextSlot) << std::endl; // should print Black Panther THRILLER (134 min) [starts at 11:11, ends by 13:25]
    // test bool timeOverlap
    std::cout << timeOverlap(morning, daytime) << std::endl; // should print 0
    std::cout << timeOverlap(daytime, evening) << std::endl; // should print 0
    std::cout << timeOverlap(dusk, night) << std::endl;      // should print 1 bc dusk ends at 22:24 but night starts at 20:45

    return 0;
}