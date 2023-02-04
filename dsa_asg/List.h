#include<string>
#include<iostream>
#include "Posts.h"
using namespace std;

typedef string ItemType;


class List
{
private:

	struct Node
	{
		ItemType topic;
		ItemType user;
		Posts* postNode;
		Node* next;
	};

	Posts post;
	Node* firstNode;
	int  size;

public:

	//Constructor
	List();
	//Destructor
	~List();
	// add topic to dictionary
	bool add(ItemType topic, ItemType user);
	//add post to topic
	bool addPost(ItemType postStr, ItemType user);
	//add reply to post
	bool addReply(ItemType replyStr, ItemType user);
	//edit topic at index
	bool edit(int index, ItemType topic);
	//edit post at index
	bool editPost(int index, ItemType postStr);
	//edit reply at index.
	bool editReply(int index, ItemType replyStr);
	// remove topic from dictionary
	void remove(int index);
	// remove post from topic
	void removePost(int index);
	// remove reply from post
	void removeReply(int index);
	// print all topics
	void printTopic();
	// print all posts
	void printPost();
	// print all replies
	void printReply();
	// check if dictionary is empty
	bool isEmpty();
	// return int of dictionary length
	int getLength();

};
