#include <iostream>
#include "user.cpp"
#include "reservation.cpp"
#include "cabinet.cpp" 
#include "table.cpp" 

using namespace std;

int main() {
    system("chcp 65001 > nul"); 
    User u;
    if (!u.login()) {
        return 0; 
    }

    int choose;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\n1. Kabinet\n2. Masa\n3. Exit\nSeciminiz: ";
        cin >> choose;

        if (choose == 1) {
            Cabinet c;
            c.cabinetReserv();
            cout << "Kabinet bölməsi seçildi." << endl;
        } 
        else if (choose == 2) {
            cout << "Masa bölməsi seçildi." << endl;
            Table t;
            t.getTableInfo();
            t.tableMenu();
        } 
        else if (choose == 3) {
            exitProgram = true;
            cout << "Sistemden çixilir..." << endl;
        }
    }

    return 0;
}