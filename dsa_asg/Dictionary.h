#include<string>
#include<iostream>
#include "Posts.h"
using namespace std;

const int max_size = 1000;
typedef string ItemType;
typedef string KeyType;

struct Node
{
	KeyType  key;
	ItemType user;
	postNode* post;
	Node* next;
};

class Dictionary
{
private:
	Node* items[max_size];
	int  size;

public:

	Dictionary();
	~Dictionary();

	int hash(KeyType key);
	bool add(KeyType newKey, ItemType user);
	void remove(KeyType key);
	postNode* getPost(KeyType key);
	bool isEmpty();
	int getLength();

	void printTopic();
};
