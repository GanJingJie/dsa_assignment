#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Register();
void logIn();
void passwordCheck();

int opt, lineNo = 0;
string username, password, fileName, existingUser, Password;
bool same = true;
ofstream write;
ifstream read;

void pWord() {
    cout << "Please enter your password: ";
    cin >> password;
    passwordCheck();
}

void passwordCheck() {
    read.open("Passwords.txt");
    for (int i = 0; i < lineNo; i++) {
        if (i == lineNo) {
            getline(read, Password);
            if (password == Password) {
                cout << "Log In Successful!" << endl;
                // ForumPage();
            }

            else
            {
                bool yes = true;
                while (yes) {
                    cout << "Incorrect Pin!" << endl;
                    cout << "--------- Options ---------" << endl;
                    cout << "1. Retype username \n2. Retype password \n3. Register User" << endl;
                    cout << "---------------------------";
                    cin >> opt;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (opt == 1) {
                        yes = false;
                        logIn();
                    }
                    else if (opt == 2) {
                        yes = false;
                        pWord();
                    }
                    else if (opt == 3) {
                        yes = false;
                        Register();
                    }
                    else {
                        cout << "Please enter a valid option!" << endl;
                    }
                }
            }
        }
    }
    read.close();
}

int logInCheck() {
    read.open(fileName);
    cout << fileName << "\n";
    while (!read.eof()) {
        getline(read, existingUser);
        cout << existingUser;
        if (username != existingUser) {
            lineNo++;
        }
        else if (username == existingUser) {
            pWord();
            read.close();
        }
        else
        {
            cout << "Username not found" << endl;
            logIn();
        }
    }

    return lineNo;
}

void logIn() {
    cout << "Please enter your username: ";
    cin >> username;
    logInCheck();
}

void RegisterCheck() {

    // Opening file to check if it exists
    read.open(fileName);
    while (!read.eof()) {
        getline(read, existingUser);
        if (username == existingUser) {
            cout << "Username already exists!" << endl;
            Register();
        }
    }
    read.close();
}

void Register() {
    while (same) {
        cout << "Please enter a username: ";
        cin >> username;
        cout << "Please enter a password: ";
        cin >> password;
        fileName = "Usernames.txt";

        if (username == password) {
            cout << "Your password cannot be the same as your username!" << endl;
        }

        else {
            same = false;
            RegisterCheck(); // checking if username exists

            // writing username to file "Usernames.txt"
            write.open(fileName);
            write << username << endl;
            write.close();

            // writing password to file "Passwords.txt"
            write.open("Passwords.txt");
            write << password << endl;
            write.close();
        }
    }
}

int main()
{
    int opt;
    string username, password, fileName;
    ofstream outFile;
    ifstream inFile;
    do {
        // Menu Print
        cout << "------------ MENU ------------" << endl;
        cout << "1. Register account" << endl;
        cout << "2. Log in" << endl;
        cout << "3. Exit" << endl;
        cout << "------------------------------" << endl;
        cout << "What would you like to do: ";
        cin >> opt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opt == 1) {
            Register();
        }

        else if (opt == 2) {
            logIn();
        }

        else if (opt == 3) {
            break;
        }

        else {
            cout << "Please enter a valid option" << endl;
        }
    }

    while (opt != 0);
}

