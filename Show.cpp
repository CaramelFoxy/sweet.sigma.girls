#include "Show.h"
#include <iostream>
using namespace std;
Show::Show()
 : title(""), date(""), time(""), duration(0), hasIntermission(false),
 actors(nullptr), actorCount(0), availableSeats(0), description("") {}
Show::Show(const string& t, const string& d, const string& ti, int du, bool hi,
string* a, int ac, int seats, const string& desc)
 : title(t), date(d), time(ti), duration(du), hasIntermission(hi),
 actorCount(ac), availableSeats(seats), description(desc)
{
 if (actorCount > 0) {
 actors = new string[actorCount];
 for (int i = 0; i < actorCount; ++i) {
 actors[i] = a[i];
 }
 }
 else {
 actors = nullptr;
 }
}
Show::Show(const Show& other)
 : title(other.title), date(other.date), time(other.time),
 duration(other.duration), hasIntermission(other.hasIntermission),
 actorCount(other.actorCount), availableSeats(other.availableSeats),
 description(other.description)
{
 if (actorCount > 0) {
 actors = new string[actorCount];
 for (int i = 0; i < actorCount; ++i) {
 actors[i] = other.actors[i];
 }
 }
 else {
 actors = nullptr;
 }
}
Show& Show::operator=(const Show& other) {
 if (this != &other) {
 title = other.title;
 date = other.date;
 time = other.time;
 duration = other.duration;
 hasIntermission = other.hasIntermission;
 availableSeats = other.availableSeats;
 description = other.description;
 delete[] actors;
 actorCount = other.actorCount;
 if (actorCount > 0) {
 actors = new string[actorCount];
 for (int i = 0; i < actorCount; ++i) {
 actors[i] = other.actors[i];
 }
 }
 else {
 actors = nullptr;
 }
 }
 return *this;
}
Show::~Show() {
 delete[] actors;
}
void Show::displayShowInfo() const {
 cout << "\033[1;34mНазва: \033[0m" << title
 << "\n\033[1;34mДата: \033[0m" << date
 << "\n\033[1;34mЧас: \033[0m" << time
 << "\n\033[1;34mТривалість: \033[0m" << duration << " хвилин"
 << "\n\033[1;34mАнтракт: \033[0m" << (hasIntermission ? "Так" : "Ні")
 << "\n\033[1;34mДоступні місця: \033[0m" << availableSeats
 << "\n\033[1;34mОпис: \033[0m" << description << "\n";
}
string Show::getTitle() const { return title; }
string Show::getDate() const { return date; }
string* Show::getActors() const { return actors; }
int Show::getActorCount() const { return actorCount; }
int Show::getAvailableSeats() const { return availableSeats; }
void Show::bookSeat() {
 if (availableSeats > 0) {
 availableSeats--;
 cout << "\033[1;32mМісце успішно заброньовано!\n\033[0m";
 }
 else {
 cout << "\033[1;31mНемає доступних місць!\n\033[0m";
 }
}
