#include "Theater.h" 
#include <iostream> 
#include <fstream> 
#include <sstream> 
using namespace std;

static void splitString(const string& str, char delimiter, string*& arr, int& count) {

    count = 1;
    for (char c : str) {
        if (c == delimiter)
            count++;
    }
    arr = new string[count];
    int index = 0;
    size_t start = 0;
    while (true) {
        size_t pos = str.find(delimiter, start);
        if (pos == string::npos) {
            arr[index++] = str.substr(start);
            break;
        }
        else {
            arr[index++] = str.substr(start, pos - start);
            start = pos + 1;
        }
    }
}

Theater::Theater()
    : shows(nullptr), tickets(nullptr),
    showCount(0), ticketCount(0),
    showCapacity(0), ticketCapacity(0)
{
    loadShowsFromFile("show.txt");
}

Theater::~Theater() {
    delete[] shows;
    delete[] tickets;
}

void Theater::resizeShows() {
    int newCapacity = (showCapacity == 0) ? 1 : showCapacity * 2;
    Show* temp = new Show[newCapacity];
    for (int i = 0; i < showCount; i++) {
        temp[i] = shows[i];
    }
    delete[] shows;
    shows = temp;
    showCapacity = newCapacity;
}

void Theater::resizeTickets() {
    int newCapacity = (ticketCapacity == 0) ? 1 : ticketCapacity * 2;
    Ticket* temp = new Ticket[newCapacity];
    for (int i = 0; i < ticketCount; i++) {
        temp[i] = tickets[i];
    }
    delete[] tickets;
    tickets = temp;
    ticketCapacity = newCapacity;
}

void Theater::loadShowsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "\033[1;31mПопередження: Неможливо відкрити файл " << filename << ". Починаємо з порожнього списку.\n\033[0m";
        return;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string title, date, time, actorsStr, desc;
        int duration, intermissionInt, seats;

        getline(ss, title, ';');
        getline(ss, date, ';');
        getline(ss, time, ';');
        string durationStr;
        getline(ss, durationStr, ';');
        duration = stoi(durationStr);

        string intermissionStr;
        getline(ss, intermissionStr, ';');
        intermissionInt = stoi(intermissionStr);

        getline(ss, actorsStr, ';');

        string seatsStr;
        getline(ss, seatsStr, ';');
        seats = stoi(seatsStr);

        getline(ss, desc);

        // Розбиваємо список акторів за комою 
        string* actorArr = nullptr;
        int actorCount = 0;
        splitString(actorsStr, ',', actorArr, actorCount);

        bool hasIntermission = (intermissionInt != 0);
        Show newShow(title, date, time, duration, hasIntermission, actorArr, actorCount, seats, desc);
        addShow(newShow);
        delete[] actorArr;
    }
    file.close();
}

void Theater::addShow(const Show& show) {
    if (showCount == showCapacity) {
        resizeShows();
    }
    shows[showCount] = show;
    showCount++;
}

void Theater::listShows() const {
    if (showCount == 0) {
        cout << "\033[1;31mНемає вистав для показу.\n\033[0m";
        return;
    }
    for (int i = 0; i < showCount; i++) {
        shows[i].displayShowInfo();
        cout << "-------------------------\n";
    }
}

void Theater::sellTicket(const string& showTitle, const string& buyerName) {
    for (int i = 0; i < showCount; i++) {
        if (shows[i].getTitle() == showTitle) {
            if (shows[i].getAvailableSeats() > 0) {
                int seatNumber = shows[i].getAvailableSeats();
                shows[i].bookSeat();
                if (ticketCount == ticketCapacity) {
                    resizeTickets();
                }
                tickets[ticketCount] = Ticket(showTitle, buyerName, seatNumber);
                ticketCount++;
                cout << "\033[1;32mКвиток успішно продано!\n\033[0m";
                return;
            }
            else {
                cout << "\033[1;31mПомилка: Немає доступних місць!\n\033[0m";
                return;
            }
        }
    }
    cout << "\033[1;31mПомилка: Виставу не знайдено!\n\033[0m";
}

void Theater::listTicketsForShow(const string& showTitle) const {
    bool found = false;
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].getShowTitle() == showTitle) {
            tickets[i].displayTicketInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "\033[1;31mНемає квитків для вистави: " << showTitle << "\n\033[0m";
    }
}
