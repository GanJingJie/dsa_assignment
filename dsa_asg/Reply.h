#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef string Itemtype;


class Reply
{
private:

	struct replyNode 
	{
		Itemtype reply;
		Itemtype user;
		replyNode* replyNext;
	};
	
	replyNode* firstNode;
	int size;

public:
	Reply();
	~Reply();

	//add reply
	bool add(Itemtype reply, Itemtype user);
	//edit a reply with the index of the reply
	bool edit(int index, Itemtype reply, Itemtype user);
	//remove a reply
	void remove(int index);
	//check if post has a reply
	bool isEmpty();
	//print out all the replies for a post
	void printReply();
};

