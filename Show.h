#pragma once
#include <string>
using namespace std;
class Show {
private:
 string title;
 string date;
 string time;
 int duration;
 bool hasIntermission;
 string* actors;
 int actorCount;
 int availableSeats;
 string description;
public:
 Show();
 Show(const string& t, const string& d, const string& ti, int du, bool hi, string*
a, int ac, int seats, const string& desc);
 Show(const Show& other);
 Show& operator=(const Show& other);
 ~Show();
 void displayShowInfo() const;
 string getTitle() const;
 string getDate() const;
 string* getActors() const;
 int getActorCount() const;
 int getAvailableSeats() const;
 // Бронювання місця (зменшення кількості доступних місць)
 void bookSeat();
};
