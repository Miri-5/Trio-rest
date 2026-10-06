#include <iostream>
#include <cstring>

using namespace std;

class User {
private:
    char username[20], password[20];
    char user[20] = "admin", pass[20] = "1234";

public:
    bool login() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
            cout << "System is active" << endl;
            system("color a"); 
            return true;
        } else {
            cout << "Username and Password incorrect!" << endl;
            system("color c"); 
            return false;
        }
    }
};