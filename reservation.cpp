#include <iostream>
#include <string>
#include <ctime>

#ifndef RESERVATION_CPP
#define RESERVATION_CPP

using namespace std;

class Reservation {
protected: 
    string name, surname, phone_number, date;
    int globalMethod;
    double givenMoney;
    bool usedCash = false;
    bool usedCard = false;

public:
    void showCurrentTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "Sistemin cari vaxti: " << dt;
    }
    
    void getbaseInfo() {
        cout << "Musterinin adi: ";
        cin >> name;
        cout << "Musterinin soyadi: ";
        cin >> surname;

        while (true) {
        cout << "Musterinin telefon nomresi +994 (9 reqem): ";
        cout << "+994 ";
        cin >> phone_number;
        if (phone_number.length() == 9) break;
        cout << "Xeta: Telefon nomresi 9 reqemli olmalidir! Yeniden yazın." << endl;
        }

        while (true) {
            cout << "Musterinin geleceyi tarix (dd.mm.yyyy): ";
            cin >> date;
            if (date.length() == 10 && date[2] == '.' && date[5] == '.') {
                
                string gun = date.substr(0, 2);
                string ay = date.substr(3, 2);
                string il = date.substr(6, 4);

                if (il >= "2026" && (ay >= "01" && ay <= "12") && (gun >= "01" && gun <= "31")) {
                    break;
                }
            }
            cout << "Xeta: Tarix formati ve ya deyerler yanlisdir (Minimum il 2026 olmalidir)!" << endl;
        }
    }

    void ReceiptHeader() {
        cout << "\n****************** Restoran Qebzi ******************" << endl;
        showCurrentTime();
        cout << "User Full Name: " << name << " " << surname << endl;
        cout << "User Phone Number: +994 " << phone_number << endl;
        cout << "Reservation Date: " << date << endl;
        cout << "****************************************************" << endl;
    }

    void calculateChange(double totalAmount) {
        double AAA = totalAmount;
        givenMoney = 0;
        usedCash = false;
        usedCard = false;

        while (AAA > 0.01) {
            cout << "\nCemi borc: " << totalAmount << " AZN";
            cout << "\nOdenilmeli qalan mebleg: " << AAA << " AZN" << endl;
            cout << "Odenis usulunu secin (1. Nağd, 2. Kart): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                usedCash = true;
                double payment;
                cout << "Nağd mebleği daxil edin: "; 
                cin >> payment;
                givenMoney += payment; //45
                AAA -= payment; //5
            } 
            else if (choice == 2) {
                usedCard = true;
                double cardPayment;
                string cardNumber, expiryDate, cvv;
                while (true) {
                    cout << "16 reqemli kart nomresini daxil edin: "; cin >> cardNumber;
                    if (cardNumber.length() == 16) break;
                    cout << "Sehv! Kart 16 reqemli olmalidir." << endl;
                }
                cout << "Son istifade tarixi (MM/YY): "; cin >> expiryDate;
                cout << "CVV (3 reqem): "; cin >> cvv;
                cout << "Kartdan cekilecek mebleğ (Qalan borc " << AAA << " AZN): ";
                cin >> cardPayment; //6
                givenMoney += cardPayment;

                if (cardPayment > AAA) cardPayment = AAA; //6
                
                AAA -= cardPayment; 
                cout << "Kartdan " << cardPayment << " AZN ugurla cekildi." << endl;
            }
        }
        if (usedCash && usedCard) globalMethod = 3;
        else if (usedCash) globalMethod = 1;
        else globalMethod = 2;

        cout << "\nOdenis tamamlandi!" << endl;
        system("pause");
    }
}; 

#endif