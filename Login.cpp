#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool authenticate(const string& username, const string& password) {
    ifstream userFile("users.txt");
    string accounts, user, pass;

    while(userFile >> accounts) {
        int len = accounts.length();
        for(int i = 0 ; i < len; i++) {
            if(accounts[i] == '|') {
                user = accounts.substr(0, i);
                pass = accounts.substr(i + 1, len - i - 1);
                break;
            }
        }
        if(user == username && pass == password) {
            return true;
        }
    }
    userFile.close();
    return false;
}
void login(){
    int i=0;
    while(i<3){
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (authenticate(username, password)) {
        cout << "Login successful!" << endl;
        return;
    } else {
        cout << "Invalid username or password." << endl;
    }
    i++;
    if(i==3){
        cout<<"You have exceeded the number of attempts."<<endl;
    }
    }
}
int main() {
    login();
    return 0;
}