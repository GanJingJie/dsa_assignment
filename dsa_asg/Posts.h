#pragma once
#include <string>
#include <iostream>
#include "Reply.h"
using namespace std;

const int max_array = 10;
typedef string itemType;

struct postNode {
	itemType post;
	itemType user;
	replyNode* replynext;
	postNode* next;
};

class Posts
{
private:
	postNode* posts[max_array];
	int size;

public:
	Posts();
	~Posts();

	bool add(itemType post, itemType user);
	bool add(int index, itemType post, itemType user);//what is this for? is it so that we can edit the post and then put it back at the same index?
	void remove(int index);
	bool isEmpty();
	void printPost();
};

