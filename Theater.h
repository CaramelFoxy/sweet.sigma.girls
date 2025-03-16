#pragma once 
#include "Show.h" 
#include "Ticket.h" 
#include <string> 
using namespace std;

class Theater {
private: 
    Show* shows;
    Ticket* tickets;
    int showCount;
    int ticketCount;
    int showCapacity;
    int ticketCapacity;

    void resizeShows();
    void resizeTickets();

    void loadShowsFromFile(const string& filename);
public:
    Theater();
    ~Theater();

    void addShow(const Show& show);

    void listShows() const;

    void sellTicket(const string& showTitle, const string& buyerName);

    void listTicketsForShow(const string& showTitle) const;
};
