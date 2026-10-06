#include<iostream>
#include<string>
#include "reservation.cpp"

using namespace std;
class Cabinet : public Reservation {
public:
    void cabinetReserv(){
        getbaseInfo();
        int cabinetNo, hour;
        double amountForOneHour = 50;
        cout << "\n--- KABİNET MƏLUMATLARI ---" << endl;
        cout << "Kabinet nomresi secin: ";
        cin >> cabinetNo;
        cout << "Nece saatliq rezerv olacaq? ";
        cin >> hour;

        double totalAmount = hour * amountForOneHour;

        //system("cls");
        cout << "========== ƏLAVƏ XİDMƏTLƏR (Hər biri 20 AZN) ==========" << endl;
        cout << "1. Şarla bəzəmə\n2. Led İşıqlar\n3. Tort\n4. Çiçək ləçəkləri\n5. Sadə boş otaq (0 AZN)\n6. SEÇİMİ BİTİR" << endl;
        cout << "========================================================" << endl;

        int choose;
        string answer;
        while (true) {
            cout << "Secim daxil edin: "; 
            cin >> choose;

            if (choose == 6) break;

            if (choose >= 1 && choose <= 4) {
                totalAmount += 20;
                cout << ">> Xidmet elave edildi!" << endl;
            } 
            else if (choose == 5) {
                cout << ">> Sade otaq secildi (Elave odenis yoxdur)." << endl;
            } 
            else {
                cout << ">> Yanlis secim!" << endl;
            }
            cout << "Elave secim olacaq? (Bəli/Xeyr): ";
            cin >> answer;
            if (answer != "Bəli" && answer == "Xeyr") {
                break; 
            }
        }
        //system("cls");
        ReceiptHeader();
        cout << "Rezerv növü:     Kabinet" << endl;
        cout << "Kabinet nömrəsi: " << cabinetNo << endl;
        cout << "Müddət:          " << hour << " saat" << endl;
        cout << "Saatlıq qiymət:  " << amountForOneHour << " AZN" << endl;
        cout << "----------------------------------------------------" << endl;
        calculateChange(totalAmount);
        if (globalMethod == 3) {
            cout << "ÖDƏNİŞ NÖVÜ:        Hibrid (Nağd + Kart)" << endl;
            cout << "ÜMUMİ ÖDƏNİLƏN:    " << givenMoney << " AZN" << endl;
        } 
        else if (globalMethod == 1) {
            cout << "ÖDƏNİŞ NÖVÜ:        Nağd (Cash)" << endl;
        } 
        else {
            cout << "ÖDƏNİŞ NÖVÜ:        Bank Kartı" << endl;
        }
        if (givenMoney > totalAmount) {
        cout << "QALIQ (Cashback):   " << givenMoney - totalAmount << " AZN" << endl;
        }
        cout << "\n****************************************************" << endl;
        cout << "   Bizi seçdiyiniz üçün təşəkkür edirik!   " << endl;
        cout << "****************************************************" << endl;
        system("pause");
    }
};