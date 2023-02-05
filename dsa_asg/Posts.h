#pragma once
#include <string>
#include <iostream>
#include "Reply.h"
using namespace std;

typedef string ItemType;

class Posts
{
private:
	Reply* reply;
	struct postNode
	{
		ItemType post;
		ItemType user;
		Reply* reply;
		postNode* next;
	};
	postNode* firstNode;
	int size;

public:
	//constructor
	Posts();
	//destructor
	~Posts();
	//add post to the list.
	bool add(ItemType post, ItemType user);
	// add reply to a post.
	bool addReply(ItemType replyStr, ItemType user);
	//user selects the post they want to edit. the selected one will be the index.
	bool edit(int index, ItemType post);
	//edit a reply with index of the replies
	bool editReply(int index, ItemType replyStr);
	//remove post at the specific index
	void remove(int index);
	//remove a reply with the reply index.
	void removeReply(int index);
	//check if the topic is empty
	bool isEmpty();
	//print out all the post on the specific topic
	void printPost();
	//print out all the replies on the post(with its index).
	void printReply(int index);
};

