#pragma once
#include <string>
#include <iostream>
using namespace std;

const int max_array = 10;
typedef string itemType;

struct Node {
	itemType type;
	itemType post;
	Node* next;
};

class Posts
{
private:
	Node* posts[max_array];
	int size;

public:
	Posts();
	~Posts();

	bool add(itemType type, itemType post);
	bool add(int index, itemType type, itemType post);
	void remove(int index);
	bool isEmpty();
};

