#pragma once
#include <string>
using namespace std;
class Ticket {
private:
 string showTitle;
 string buyerName;
 int seatNumber;
 static int nextId;
 int ticketId;
public:
 Ticket();
 Ticket(const string& title, const string& buyer, int seat);
 void displayTicketInfo() const;
 int getTicketId() const;
 string getShowTitle() const;
};
