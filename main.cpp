#include <iostream>
#include "Show.h"
#include "Theater.h"
#include "Ticket.h"
#include <locale>
using namespace std;
int main() {
 setlocale(LC_ALL, "ukr"); // Встановлення української локалі
 Theater theater; // Конструктор завантажує вистави з файлу show.txt
 int choice;
 string showTitle, buyerName;
 do {
 cout << "\033[1;36m\nСистема управління театром\n\033[0m";
 cout << "1. Додати виставу\n";
 cout << "2. Показати вистави\n";
 cout << "3. Купити квиток\n";
 cout << "4. Показати квитки на виставу\n";
 cout << "0. Вийти\n";
 cout << "\033[1;32mВведіть ваш вибір: \033[0m";
 cin >> choice;
 cin.ignore();
 switch (choice) {
 case 1: {
 string t, d, ti, desc;
 int du, seats, ac;
 bool hi;
 cout << "\033[1;34mВведіть назву вистави: \033[0m";
 getline(cin, t);
 cout << "Введіть дату вистави (РРРР-ММ-ДД): ";
 getline(cin, d);
 cout << "Введіть час початку (ГГ:ХХ): ";
 getline(cin, ti);
 cout << "Введіть тривалість (хвилини): ";
 cin >> du;
 cin.ignore();
 cout << "Є антракт? (1 - так, 0 - ні): ";
 cin >> hi;
 cin.ignore();
 cout << "Введіть кількість акторів: ";
 cin >> ac;
 cin.ignore();
 string* actors = new string[ac];
 for (int i = 0; i < ac; i++) {
 cout << "Введіть ім'я актора №" << (i + 1) << ": ";
 getline(cin, actors[i]);
 }
 cout << "Введіть кількість доступних місць: ";
 cin >> seats;
 cin.ignore();
 cout << "Введіть опис вистави: ";
 getline(cin, desc);
 Show newShow(t, d, ti, du, hi, actors, ac, seats, desc);
 theater.addShow(newShow);
 delete[] actors;
 break;
 }
 case 2:
 theater.listShows();
 break;
 case 3: {
 cout << "\033[1;33mВведіть назву вистави для продажу квитка: \033[0m";
 getline(cin, showTitle);
 cout << "Введіть ім'я покупця: ";
 getline(cin, buyerName);
 theater.sellTicket(showTitle, buyerName);
 break;
 }
 case 4: {
 cout << "\033[1;35mВведіть назву вистави для перегляду квитків: \033[0m";
 getline(cin, showTitle);
 theater.listTicketsForShow(showTitle);
 break;
 }
 case 0:
 cout << "\033[1;31mВихід з програми.\n\033[0m";
 break;
 default:
 cout << "\033[1;31mНевірний вибір. Спробуйте ще раз.\n\033[0m";
 }
 } while (choice != 0);
 return 0;
}

