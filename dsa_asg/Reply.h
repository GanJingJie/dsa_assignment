#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef string Itemtype;


class Reply
{
private:

	struct Node 
	{
		Itemtype reply;
		Itemtype user;
		Node* next;
	};
	
	Node* firstNode;
	int size;

public:
	Reply();
	~Reply();

	//add reply 
	bool add(Itemtype reply, Itemtype user);
	//edit a reply with the index of the reply, index starts with 0
	bool edit(int index, Itemtype reply);
	//remove a reply index starts with 0
	void remove(int index);
	//check if post has a reply
	bool isEmpty();
	//get the reply string 
	bool getReply(Itemtype& reply, int index);
	//print out all the replies for a post
	void printReply();
	//get the reply string.
	Itemtype getReply(int index);
	//get the user string.
	Itemtype getUser(int index);
};

