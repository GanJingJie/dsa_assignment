#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "List.h"
#include "Posts.h"
#include "Reply.h"
using namespace std;

void getPassword();
void Register();
void logIn();
int main();

int lineNo = 1;
string username, password, fileName, existingUser, Password;
ofstream write;
ifstream read;
List topicList;
//Posts postList;
//Reply replyList;

// Function to check if input is integer
bool isNumeric(string str) {

    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false) {
            return false;
        }
    }

    return true;
}

void deletePost() {

    string topicIndex;

    cout << "Which topic would you like to delete the post from: " << endl;
    getline(cin, topicIndex);

    if (isNumeric(topicIndex)) {
        int index = stoi(topicIndex);
        topicList.removePost(index-1);//minus 1 because index starts from 0 and displays it from 1
    }
   
}


void createPost(string username) 
{
    string post;
    cout << "=============Post=============" << endl;
    cout << "Enter your post:" << endl;
    getline(cin, post);

    //postList.add(post, username);
    //postList.printPost();

    bool inPost = true;
    string option;
    while (inPost)
    {
        cout << endl;
        cout << "1. Add another post" << endl;
        cout << "2. go back to View all topics";
        cin >> option;
        
        if (isNumeric(option)){
            if (option == "1")
            {
                createPost(username);
                inPost = false;
            }

            else if (option == "2")
            {
                inPost = false;
            }
        }

        else {
            cout << "Invalid option please try again" << endl;
        }
        
    }
}

void createTopic(string username) {

    string topicName;
    cout << "Enter topic name: ";
    getline(cin, topicName);
    topicList.add(topicName, username);

    bool inTopic = true;
    string option;
    while (inTopic)
    {
        cout << "------------TOPIC------------" << endl;
        cout << "" << endl;
        cout << topicName << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Add post" << endl;
        cout << "2. Back to previous menu" << endl;
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (isNumeric(option)){
            if (option == "1")
            {
                createPost(username);
                inTopic = false;
            }

            else if (option == "2")
            {
                inTopic = false;
            }
        }
        
        else
        {
            cout << "Invalid option please try again" << endl;
        }
    }

}

void viewTopics(string username) {
    string choice = 0;
    bool success = 1;

    cout << "----------- TOPICS -----------" << endl;
    topicList.printTopic();
    cout << "------------------------------" << endl;

    while (success) {
        cout << "------------ MENU ------------" << endl;
        cout << "1. Select Topic to view" << endl;
        cout << "0. Back" << endl;
        cout << "------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == "1") {
            viewPost(stoi(choice), username);
        }

        else if (choice == "0") {
            success = 0;//break the loop and return to the previous method.
        }
        else
        {
            success = 1;//continue the loop
        }
    }
}

void viewReply(int index)
{
    string choice;
    bool success = true;
    string reply;

    while (success)
    {
        //printing of post and the replies
        topicList.printReply(index);//this first print out the post then the replies.

        cout << "1.Add reply" << endl;
        cout << "2.Delete reply" << endl;
        cout << "3.Back" << endl;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == "1")
        {
            string replyStr;
            cout << "Enter your reply:" << endl;
            getline(cin, replyStr);



        }
        
    }
}

void viewPost(int index, string username)
{
    string choice;
    bool success = true;
    string post;

    while (success)
    {
        //printing of the all the posts
        cout << "-----------POSTS-----------" << endl;
        topicList.printPost();
        cout << "---------------------------" << endl;

        //listing all the options
        cout << "1.Add a post" << endl;
        cout << "2.View a post in detail" << endl;
        cout << "3.Delete your post" << endl;
        cout << "For all the option choose the index of the post." << endl;
        cout << "Your Option:" << endl;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //what happens to each options
        if (choice == "1")
        {
            string postStr;
            cout << "Enter your post:" << endl;
            getline(cin, postStr);
            topicList.addPost(postStr, username);
            cout << "" << endl;
            cout << "Your post has be added" << endl;
            success = true;
        }

        else if (choice == "2")//call a method to view the post and replies along with its options
        {
            //viewReply
        }

        else if (choice == "3")//call delete method
        {
            deletePost();
        }

    }

}

void showReplies(int index, string username)
{
    int choice;
    bool success = true;
    cout << "-----------POSTS-----------" << endl;
    topicList.printPost();
    cout << "---------------------------" << endl;

}

void ForumPage(string username) {
    bool success = true;
    string choice = 0;
    while (success){
        cout << "------------ MENU ------------" << endl;
        cout << "1. View All Topics" << endl;
        cout << "2. Create Topics" << endl;
        cout << "0. Log Out" << endl;
        cout << "------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == "1") {
            viewTopics(username);
        }

        else if (choice == "2") {
            createTopic(username);
        }

            else if (choice == "0") {
                username = "";
                password = "";
                success = false;
                cout << "Log out successful!" << endl;
                main();
            }
        }

        else
        {
            cout << "Invalid option please try again" << endl;
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
        getline(read, Password);
        lineNo--;
    }
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
                success = 0;
                same = true;
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
            success = 0;

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
    string username, password, fileName, opt;
    ofstream outFile;
    ifstream inFile;
    do {
        // Menu Print
        cout << "------------ MENU ------------" << endl;
        cout << "1. Register account" << endl;
        cout << "2. Log in" << endl;
        cout << "0. Exit" << endl;
        cout << "------------------------------" << endl;
        cout << "What would you like to do: ";
        cin >> opt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (isNumeric(opt)){
            if (opt == "1") {
                Register();
                opt = "0";
            }

            else if (opt == "2") {
                logIn();
                opt = "0";
            }

            else if (opt == "0") {
                exit;
            }
        }
        
        else {
            cout << "Please enter a valid option" << endl;
        }
    }

    while (opt != "0");
}
