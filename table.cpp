#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include "reservation.cpp"
using namespace std;

class Table: public Reservation {
public:
    void getTableInfo() {
        getbaseInfo();
        cout << "Rezervasiya ugurla tamamlandi!" << endl;
        system("pause");
}

    double totalAmount = 0;

    void tableMenu() {
        int catChoice;
        bool isOrdering = true;

        while (isOrdering) {
    
            cout << "\n========== TRİO RESTAURANT MENU ==========" << endl;
            cout << "1. Kabablar" << endl;
            cout << "2. Isti Yemekler" << endl;
            cout << "3. Qazan Yemekleri (Şorbalar daxil)" << endl;
            cout << "4. Soyuq Içkiler" << endl;
            cout << "5. Sifarişi tamamla ve Qebz cap et" << endl;
            cout << "=============================================" << endl;
            cout << "Kateqoriya secin: ";
            cin >> catChoice;
            system("cls");

            switch (catChoice) {
                case 1: showKababMenu(); break;
                case 2: showIstiYemekMenu(); break;
                case 3: showQazanYemekMenu(); break;
                case 4: showIckiMenu(); break;
                case 5: isOrdering = false; break;
                default: cout << "Yanlis secim!" << endl;
            }
        }
        processPayment();
    }

private:
    void showKababMenu() {
        cout << "\n--- Kabablar ---" << endl;
        cout << "1. Antrikot (8.00 AZN)\n";
        cout << "2. Lülə (7.00 AZN)\n";
        cout << "3. Tikə (7.00 AZN)\n";
        cout << "4. Xan Kababı (7.00 AZN)\n";
        cout << "5. Adana Kababı - (15.00 AZN)\n";
        cout << "6. İskender Kababı - (18.00 AZN)\n";
        cout << "7. Dönər - (12.00 AZN)\n";
        cout << "0. Geri\n"; 
        
        while (true) {
            int choice;
            cout << "Sifariş vermek istediyiniz kababı seçin: ";
            cin >> choice;

            if (choice == 0) break;
            switch (choice) {
                case 1: totalAmount += 8.00; cout << ">> Antrikot elave edildi!" << endl; break;
                case 2: totalAmount += 7.00; cout << ">> Lülə elave edildi!" << endl; break;
                case 3: totalAmount += 7.00; cout << ">> Tikə elave edildi!" << endl; break;
                case 4: totalAmount += 7.00; cout << ">> Xan Kababı elave edildi!" << endl; break;
                case 5: totalAmount += 15.00; cout << ">> Adana Kababı elave edildi!" << endl; break;
                case 6: totalAmount += 18.00; cout << ">> İskender Kababı elave edildi!" << endl; break;
                case 7: totalAmount += 12.00; cout << ">> Dönər elave edildi!" << endl; break;
                default: cout << "Yanlis secim!" << endl;
            }
        }
    }

    void showIstiYemekMenu() {
        cout << "\n--- İsti Yemekler ---" << endl;
        cout << "1. Çolpa çığırtması (15.00 AZN)\n";
        cout << "2. Tabaka (18.00 AZN)\n";
        cout << "3. Kartof qızartması (4.00 AZN)\n";
        cout << "4. Tavuk Sote - (10.00 AZN)\n";
        cout << "5. Et Sote - (12.00 AZN)\n";
        cout << "6. Baliq Izgara - (20.00 AZN)\n";
        cout << "0. Geri\n";

        while (true){
            int choice;
            cout << "Sifariş vermek istediyiniz isti yemeyi seçin: ";
            cin >> choice;
            if (choice == 0) break;
            switch (choice) {
                case 1: totalAmount += 15.00; cout << ">> Çolpa çığırtması elave edildi!" << endl; break;
                case 2: totalAmount += 18.00; cout << ">> Tabaka elave edildi!" << endl; break;
                case 3: totalAmount += 4.00; cout << ">> Kartof qızartması elave edildi!" << endl; break;
                case 4: totalAmount += 10.00; cout << ">> Tavuk Sote elave edildi!" << endl; break;
                case 5: totalAmount += 12.00; cout << ">> Et Sote elave edildi!" << endl; break;
                case 6: totalAmount += 20.00; cout << ">> Baliq Izgara elave edildi!" << endl; break;
                default: cout << "Yanlis secim!" << endl;
            }
        }
    }

    void showQazanYemekMenu() {
        cout << "\n--- Qazan Yemekleri & Şorbalar ---" << endl;
        cout << "1. Dovga - (8.00 AZN)\n";
        cout << "2. Piti - (15.00 AZN)\n";
        cout << "3. Mərci şorbası (3.00 AZN)\n";
        cout << "4. Dusbərə (4.00 AZN)\n";
        cout << "5. Yarpaq Dolması (7.00 AZN)\n";
        cout << "0. Geri\n";
        int choice;
        

        while (true){
            int choice;
            cout << "Sifariş vermek istediyiniz qazan yemeyini seçin: ";
            cin >> choice;
            if (choice == 0) break;
            switch (choice) {
                case 1: totalAmount += 8.00; cout << ">> Dovğa elave edildi!" << endl; break;
                case 2: totalAmount += 15.00; cout << ">> Piti elave edildi!" << endl; break;
                case 3: totalAmount += 3.00; cout << ">> Mərci sorbasi elave edildi!" << endl; break;
                case 4: totalAmount += 4.00; cout << ">> Düsbərə elave edildi!" << endl; break;
                case 5: totalAmount += 7.00; cout << ">> Yarpaq Dolmasi elave edildi!" << endl; break;
                default: cout << "Yanlis secim!" << endl;
            }
        }
    }

    void showIckiMenu() {
        cout << "\n--- Soyuq İckiler ---" << endl;
        cout << "1. Kompot (3.00 AZN)\n";
        cout << "2. Limonad (2.00 AZN)\n";
        cout << "3. Ayran (1.00 AZN)\n";
        cout << "4. Red Bull (4.00 AZN)\n";
        cout << "5. Şərbət (3.00 AZN)\n";
        cout << "6. Qazli içki (2.50 AZN)\n";
        cout << "7. Su (1.00 AZN)\n";
        cout << "8. ÇAY(icetea) (1.50 AZN)\n";
        cout << "0. Geri\n";
        
        while (true){
            int choice;
            cout << "Sifaris vermek istediyiniz soyuq içkini secin: ";
            cin >> choice;
            if (choice == 0) break;
            switch (choice) {
                case 1: totalAmount += 3.00; cout << ">> Kompot elave edildi!" << endl; break;
                case 2: totalAmount += 2.00; cout << ">> Limonad elave edildi!" << endl; break;
                case 3: totalAmount += 1.00; cout << ">> Ayran elave edildi!" << endl; break;
                case 4: totalAmount += 4.00; cout << ">> Red Bull elave edildi!" << endl; break;
                case 5: totalAmount += 3.00; cout << ">> Şərbət elave edildi!" << endl; break;
                case 6: totalAmount += 2.50; cout << ">> Qazli içki elave edildi!" << endl; break;
                case 7: totalAmount += 1.00; cout << ">> Su elave edildi!" << endl; break;
                case 8: totalAmount += 1.50; cout << ">> ÇAY elave edildi!" << endl; break;
                default: cout << "Yanlis secim!" << endl;
            }
        }
    }

    void processPayment() {
    cout << "\n--- ÖDƏNİŞ MƏRHƏLƏSİ ---" << endl;
    calculateChange(totalAmount);
    printReceipt(globalMethod, givenMoney);
    }

    void printReceipt(int globalMethod, double givenMoney) {
        cout << "\n========================================" << endl;
        cout << "          TRİO RESTAURANT             " << endl;
        cout << "========================================" << endl;
        ReceiptHeader();
        cout << "Masa nomresi: " << rand() % 30 + 1 << endl; 
        cout << "Rezervasiya novu: Masa" << endl;
        cout << "----------------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << "Total order amount: " << totalAmount << " AZN" << endl;
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
        cout << "----------------------------------------" << endl;
        cout << "      Bizi secdiyiniz ucun tesekkurler! " << endl;
        cout << "========================================" << endl;
        system("pause");
    }
};