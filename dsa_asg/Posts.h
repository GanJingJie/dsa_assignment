#pragma once
#include <string>
#include <iostream>
#include "Reply.h"
using namespace std;

typedef string ItemType;

class Posts
{
private:
	struct Node
	{
		ItemType post;
		ItemType user;
		Reply* replyNode;
		Node* next;
	};
	Node* firstNode;
	int size;

public:
	//constructor
	Posts();
	//destructor
	~Posts();
	//add post to the list. to the back
	bool add(ItemType post, ItemType user);
	// add reply 
	bool addReply(int postIndex, ItemType replyStr, ItemType user);
	//user selects the post they want to edit. the selected one will be the index.
	bool edit(int postIndex, ItemType post);
	//edit a reply with index of the replies
	bool editReply(int postIndex, int replyIndex, ItemType replyStr);
	//remove post at the specific index
	void remove(int postIndex);
	//remove a reply with the reply index.
	void removeReply(int postIndex, int replyIndex);
	//check if the topic is empty
	bool isEmpty();
	//print out all the post on the specific topic
	void printPost();
	//print out the selected post and the replies
	void printPostReply(int postIndex);
	//get the post string
	ItemType getPost(int postIndex);
	//get the user string
	Itemtype getUser(int postIndex);
	
	
};

