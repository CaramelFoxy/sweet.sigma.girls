#include "Ticket.h"
#include <iostream>
using namespace std;
int Ticket::nextId = 1;
Ticket::Ticket() : showTitle(""), buyerName(""), seatNumber(0), ticketId(nextId++) {}
Ticket::Ticket(const string& title, const string& buyer, int seat)
 : showTitle(title), buyerName(buyer), seatNumber(seat), ticketId(nextId++) {}
void Ticket::displayTicketInfo() const {
 cout << "\033[1;33mНомер квитка: \033[0m" << ticketId
 << "\n\033[1;33mВистава: \033[0m" << showTitle
 << "\n\033[1;33mПокупець: \033[0m" << buyerName
 << "\n\033[1;33mМісце: \033[0m" << seatNumber << "\n";
}
int Ticket::getTicketId() const {
 return ticketId;
}
string Ticket::getShowTitle() const {
 return showTitle;
}
