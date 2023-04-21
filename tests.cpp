#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

TEST_CASE("Minutes Since Midnight Test Cases")
{
    CHECK(minutesSinceMidnight({10, 30}) == 630);
    CHECK(minutesSinceMidnight({23, 59}) == 1439);
}

TEST_CASE("Minutes Until Test Cases")
{
    CHECK(minutesUntil({10, 30}, {11, 30}) == 60);
    CHECK(minutesUntil({10, 30}, {12, 30}) == 120);
    CHECK(minutesUntil({10, 30}, {13, 40}) == 190);
}

TEST_CASE("Add Minutes Test Cases")
{
    CHECK(addMinutes({10, 30}, 60).hour == 11);
    CHECK(addMinutes({10, 30}, 60).minute == 30);
    CHECK(addMinutes({10, 30}, 190).hour == 13);
    CHECK(addMinutes({10, 30}, 190).minute == 40);
}

TEST_CASE("Get Time Slot Test Cases")
{
    CHECK(getTimeSlot({{"Back to the Future", COMEDY, 116}, {9, 15}}) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]");
    CHECK(getTimeSlot({{"Black Panther", THRILLER, 134}, {12, 15}}) == "Black Panther THRILLER (134 min) [starts at 12:15, ends by 14:29]");
    CHECK(getTimeSlot({{"Titanic", ROMANCE, 194}, {19, 10}}) == "Titanic ROMANCE (194 min) [starts at 19:10, ends by 22:24]");
}

TEST_CASE("Schedule After Test Cases")
{
    CHECK(getTimeSlot(scheduleAfter({{"Back to the Future", COMEDY, 116}, {9, 15}}, {"Black Panther", THRILLER, 134})) == "Black Panther THRILLER (134 min) [starts at 11:11, ends by 13:25]");
    CHECK(getTimeSlot(scheduleAfter({{"Black Panther", THRILLER, 134}, {12, 15}}, {"Titanic", ROMANCE, 194})) == "Titanic ROMANCE (194 min) [starts at 14:29, ends by 17:43]");
}

TEST_CASE("Overlap Test Cases")
{
    CHECK(timeOverlap({{"Back to the Future", COMEDY, 116}, {9, 15}}, {{"Black Panther", THRILLER, 134}, {12, 15}}) == false);
    CHECK(timeOverlap({{"Titanic", ROMANCE, 194}, {19, 10}}, {{"Avengers Endgame", ACTION, 200}, {20, 35}}) == true);
}