#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Dictionary.h"
using namespace std;

void getPassword();
void Register();
void logIn();
int main();

int opt, lineNo = 1, i = 0, choice;
string username, password, fileName, existingUser, Password;
bool same = true, success = true, yes = true;
ofstream write;
ifstream read;
Dictionary topicList;

void createTopic() {
    string topicName;
    string post;

    cout << "Enter topic name: ";
    getline(cin, topicName);
    

    cout << "What would you like to type: ";
    getline(cin, post);
    topicList.add(topicName, post);
}

void viewTopic() {
    
}

void ForumPage() {
    bool success = true;
    while (success){
        cout << "------------ MENU ------------" << endl;
        cout << "1. Create Topic" << endl;
        cout << "2. View Topics" << endl;
        cout << "3. Log Out" << endl;
        cout << "------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            createTopic();
        }

        else if (choice == 2) {
            viewTopic();
        }

        else if (choice == 3){
            username = "";
            password = "";
            success = false;
            cout << "Log out successful!" << endl;
            main();
        }
    }
}

void loginSuccessful() {
    cout << "Log In Successful!" << endl << endl;
    ForumPage();
}

void logInCheck() {
    fileName = "Usernames.txt";
    read.open(fileName);
    bool success = 0;

    while (!read.eof()) {
        getline(read, existingUser);
        if (username != existingUser) {
            lineNo++;
            cout << lineNo;
        }
        else {
            success = 1;
            break;
        }
    }

    read.close();

    if (success) {
        int passwordTries = 3;
        bool loggedIn = 0;
        while (passwordTries > 0) {
            cout << "Please enter your password: ";
            cin >> password;
            getPassword();

            if (password == Password) {
                loggedIn = 1;
                passwordTries = 0;
                loginSuccessful();
            }
            else {
                cout << "Incorrect Password!" << endl;
                passwordTries--;
            }
        }

        if (passwordTries <= 0) {
            cout << "You have enter the incorrect password 3 times. You will be logged out." << endl;
            exit;
        }
    }
    else {
        cout << "Username does not exist." << endl;
    }
}

void getPassword() {
    read.open("Passwords.txt");
    while (lineNo > 1) {
        read.eof();
        lineNo--;
    }
    getline(read, Password);
    read.close();
}

void logIn() {
    cout << "Please enter your username: ";
    cin >> username;
    logInCheck();
}

void Register() {
    while (same) {
        fileName = "Usernames.txt";
        cout << "Please enter a username: ";
        cin >> username;

        // Opening file to check if it exists
        read.open(fileName);
        while (!read.eof()) {
            getline(read, existingUser);
            if (username == existingUser) {
                cout << "Username already exists!" << endl;
                break;
            }
            else
            {
                same = false;
            }
        }
        read.close();
    }

    while (yes) {
        cout << "Please enter a password: ";
        cin >> password;
        if (password.length() < 8) {
            cout << "Your password must be more than 8 characters long!" << endl;
            continue;
        }

        else if (username == password) {
            cout << "Your password cannot be the same as your username!" << endl;
        }

        else {
            yes = false;

            // writing username to file "Usernames.txt"
            write.open(fileName);
            write << username << endl;
            write.close();

            // writing password to file "Passwords.txt"
            write.open("Passwords.txt");
            write << password << endl;
            write.close();

            cout << "User registered successfully!" << endl << endl;

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
            opt = 0;
        }

        else if (opt == 2) {
            logIn();
            opt = 0;
        }

        else if (opt == 3) {
            exit;
        }

        else {
            cout << "Please enter a valid option" << endl;
        }
    }

    while (opt != 0);
}
