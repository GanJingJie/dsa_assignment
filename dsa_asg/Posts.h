#pragma once
#include <string>
#include <iostream>
#include "Reply.h"
using namespace std;

typedef string itemType;

class Posts
{
private:

	struct postNode
	{
		itemType post;
		itemType user;
		Reply* reply;
		postNode* next;
	};

	
	postNode* firstPost;
	int size;

public:
	Posts();
	~Posts();
	//add post to the list.
	bool add(itemType post, itemType user);
	//user selects the post they want to edit. the selected one will be the index.
	bool edit(int index, itemType post, itemType user);
	//remove post at the specific index
	void remove(int index);
	//check if the topic is empty
	bool isEmpty();
	//print out all the post on the specific topic
	void printPost();
};

