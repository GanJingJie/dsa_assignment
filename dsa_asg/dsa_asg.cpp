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

int lineNo = 1;
string username, password, fileName, existingUser, Password;
ofstream write;
ifstream read;
Dictionary topicList;

void createPost() {

}

void createTopic(string username) {
    string topicName;

    cout << "Enter topic name: ";
    getline(cin, topicName);
    
    topicList.add(topicName, username);
}

void viewTopics() {
    int choice = 0;
    cout << "----------- TOPICS -----------" << endl;
    topicList.print();
    cout << "------------------------------" << endl;
}

void ForumPage(string username) {
    bool success = true;
    int choice = 0;
    while (success){
        cout << "------------ MENU ------------" << endl;
        cout << "1. Create Topic" << endl;
        cout << "2. View Topics" << endl;
        cout << "3. Create Post" << endl;
        cout << "0. Log Out" << endl;
        cout << "------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            //createTopic(username);
        }

        else if (choice == 2) {
            viewTopics();
        }

        else if (choice == 3) {
            //createPost();
        }

        else if (choice == 0){
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
    ForumPage(username);
}

void logInCheck() {
    fileName = "Usernames.txt";
    read.open(fileName);
    bool success = 0;

    while (!read.eof()) {
        getline(read, existingUser);
        if (username != existingUser) {
            lineNo++;
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
    bool same = true;
    bool success = 0;
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
                success = 1;
            }
        }
        read.close();
    }

    while (success) {
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
            write.open(fileName, ios_base::app);
            write << username << endl;
            write.close();

            // writing password to file "Passwords.txt"
            write.open("Passwords.txt", ios_base::app);
            write << password << endl;
            write.close();

            cout << "User registered successfully!" << endl << endl;
            main();

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
