#include<string>
#include<iostream>
using namespace std;

const int max_size = 1000;
typedef string ItemType;
typedef string KeyType;

struct Node
{
	KeyType  key;   
	ItemType item;
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
	bool add(KeyType newKey, ItemType newItem);
	void remove(KeyType key);
	ItemType get(KeyType key);
	bool isEmpty();
	int getLength();

	void print();
};
