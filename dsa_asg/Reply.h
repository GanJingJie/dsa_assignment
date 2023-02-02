#pragma once
#include <string>
#include <iostream>
using namespace std;

const int reply_max = 100;
typedef string Itemtype;

struct replyNode {
	Itemtype reply;
	replyNode* replynext;
};

class Reply
{
private:
	replyNode* replies[reply_max];
	int reply_size;

public:
	Reply();
	~Reply();

	bool add(Itemtype reply);
	void remove(int index);
	bool isEmpty();
	void printReply();
};

