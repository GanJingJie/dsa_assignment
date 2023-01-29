#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Register();
void logIn();
int main();

int opt, lineNo = 0, i = 0, choice;
string username, password, fileName, existingUser, Password, topicName;
bool same = true, success = true, yes = true;
ofstream write;
ifstream read;

void createTopic() {
    cout << "Enter topic name: " << endl;
    getline(cin, topicName);


}

void ForumPage() {
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
        // viewTopic();
    }

    else if (choice == 3){
        username = "";
        password = "";
        cout << "Log out successful!" << endl;
        main();
    }

}

void logInCheck() {
    fileName = "Usernames.txt";
    read.open(fileName);
    while (!read.eof()) {
        getline(read, existingUser);
        read.close();

        // check if username exists
        if (username != existingUser) {
            lineNo++;
        }

        // if username exists
        else if (username == existingUser) {
            cout << "Please enter your password: ";
            cin >> password;

            read.open("Passwords.txt");
            while (!read.eof()) {
                if (i == lineNo) {
                    getline(read, Password);
                    if (password == Password) {
                        cout << "Log In Successful!" << endl << endl;
                        ForumPage();
                    }

                    else
                    {
                        bool ye = true;
                        while (ye) {
                            cout << "Incorrect Pin!" << endl;
                            cout << "------------ Options ------------" << endl;
                            cout << "1. Retype username \n2. Retype password \n3. Register User" << endl;
                            cout << "---------------------------------" << endl;
                            cout << "Your choice: ";
                            cin >> opt;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            if (opt == 1) {
                                ye = false;
                                logIn();
                            }
                            else if (opt == 2) {
                                ye = false;
                                logInCheck();
                            }
                            else if (opt == 3) {
                                ye = false;
                                Register();
                            }
                            else {
                                cout << "Please enter a valid option!" << endl;
                            }
                        }
                    }
                }

                else {
                    i++;
                }
            }
            read.close();
        }
        else
        {
            cout << "Username not found" << endl;
            logIn();
        }
    }

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

