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
void viewPost(int index, string username);
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

    string topicIndex, postIndex;
    bool success = 1, yes = 1;

    while (success) {
        cout << "Which topic would you like to delete the post from: " << endl;
        getline(cin, topicIndex);

        if (isNumeric(topicIndex)) {
            int tIndex = stoi(topicIndex);
            success = 0;
            while (yes){
                cout << "----------- POSTS -----------" << endl;
                topicList.printTopicPost(tIndex);
                cout << "-----------------------------" << endl;
                cout << "Enter the post you would like to delete: " << endl;
                getline(cin, postIndex);

                if (isNumeric(postIndex)) {
                    int pIndex = stoi(postIndex);
                    yes = 0;
                    topicList.removePost(tIndex, pIndex);
                }

                else {
                    cout << "Please input a valid post" << endl;
                }
            }     
        }
    }
   
}


void createPost(string username) 
{
    string post, option, postStr;
    cout << "=============Post=============" << endl;
    cout << "Enter your post:" << endl;
    getline(cin, post);

    cout << "Enter your post:" << endl;
    getline(cin, postStr);
    topicList.add(postStr, username);
    cout << "" << endl;
    cout << "Your post has be added" << endl;

    bool inPost = true;
    while (inPost)
    {
        cout << endl;
        cout << "1. Add another post" << endl;
        cout << "2. Go back to view all topics" << endl;
        cout << "What would you like to do: ";
        getline(cin, option);
        
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

    bool inTopic = true;
    string topicName, option;
    cout << "Enter topic name: ";
    getline(cin, topicName);
    topicList.add(topicName, username);


    while (inTopic)
    {
        cout << "Topic Name: " << topicName << endl;
        cout << "----------- MENU -----------" << endl;
        cout << "1. Add post" << endl;
        cout << "2. Back to previous menu" << endl;
        cout << "----------------------------" << endl;
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

void whichTopic(string username) {
    string opt;
    bool success = 1;
    cout << "Which topic would you like to view: " << endl;
    getline(cin, opt);

    while (success) {
        if (isNumeric(opt)) {
            viewPost(stoi(opt), username);
            success = 0;
        }

        else {
            cout << "Please enter a valid topic" << endl;
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
        cout << "2. Create a Topic" << endl;
        cout << "0. Back" << endl;
        cout << "------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (isNumeric(choice)){
            if (choice == "1") {
                whichTopic(username);
            }

            else if (choice == "2") {
                createTopic(username);
            }

            else if (choice == "0") {
                success = 0;//break the loop and return to the previous method.
            }
        }

        else {
            cout << "Please input a valid option" << endl;
        }
    }
}

void viewReply(int topicIndex, int postIndex)
{
    string choice, reply;
    bool success = true;

    while (success)
    {
        //printing of post and the replies
        topicList.printPostReply(topicIndex, postIndex);//this first print out the post then the replies.

        cout << "------------ MENU ------------" << endl;
        cout << "1.Add reply" << endl;
        cout << "2.Delete reply" << endl;
        cout << "3.Back" << endl;
        cout << "------------------------------" << endl;
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
        for (int i = 0; i < topicList.getLength(); i++){
            topicList.printTopicPost(i);
        }
        cout << "---------------------------" << endl;

        //listing all the options
        cout << "1.Add a post" << endl;
        cout << "2.View a post in detail" << endl;
        cout << "3.Delete your post" << endl;
        cout << "For all the option choose the index of the post." << endl;
        cout << "Your Option:" << endl;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (isNumeric(choice)){
            //what happens to each options
            if (choice == "1")
            {
                createPost(username);
                success = true;
            }

            else if (choice == "2") //call a method to view the post and replies along with its options
            {
                viewReply(index, stoi(choice));
            }

            else if (choice == "3") //call delete method
            {
                deletePost();
            }
        }
        else {
            cout << "Please input a valid option" << endl;
        }
    }
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

        if (isNumeric(choice)){
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
    while (lineNo > 0) {
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

void saveTopics()
{
    fileName = "Topics.txt";
    write.open(fileName);

    int len = topicList.getTopicLength();

    for (int t = 0; t < len; t++)
    {
        write << topicList.getTopic(len) << '\t';
        write << topicList.getTopicUser(len) << endl;
    }
   
    write.close();
}

void savePosts()
{
    fileName = "Posts.txt";
    write.open(fileName);

    int topLen = topicList.getTopicLength();
    int postLen;
    for (int t = 0; t < topLen; t++)
    {
        write << t << endl;
        postLen = topicList.getPostLength(t);
        for (int p = 0; p < postLen; p++)
        {
            write << topicList.getPost(t, postLen) << '\t';
            write << topicList.getPostUser(t, postLen) << endl;
        }


    }
    write.close();
    
}

void saveReply()
{
    fileName = "Replies.txt";
    write.open(fileName);

    int topLen = topicList.getTopicLength();
    int postLen;
    int repLen;

    for (int t = 0; t < topLen; t++)
    {
        write << t << '\t';
        postLen = topicList.getPostLength(t);
        for (int p = 0; p < postLen; p++)
        {
            write << p << endl;
            repLen = topicList.getReplyLength(t, p);

            for (int r = 0; r < repLen; r++)
            {
                write << topicList.getReply(t, p, r) << '\t';
                write << topicList.getReplyUser(t, p, r) << endl;
            }
        }
    }
    write.close();
}

int main()
{
    string username, password, fileName, opt;
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
