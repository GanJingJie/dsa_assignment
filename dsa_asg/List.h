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

	Node* firstNode;
	int  size;

public:

	//Constructor
	List();
	//Destructor
	~List();
	// add a new topic to the list.
	bool add(ItemType topic, ItemType user);
	//add post to the selected topic.
	bool addPost(int topicIndex, ItemType postStr, ItemType user);
	//add reply to selected post of the selected topic
	bool addReply(int topicIndex, int postIndex, ItemType replyStr, ItemType user);
	//edit topic with index
	bool edit(int topicIndex, ItemType topic);
	//edit post of selected topic
	bool editPost(int topicIndex, int postIndex, ItemType postStr);
	//edit reply of selected post 
	bool editReply(int topicIndex, int postIndex, int replyIndex, ItemType replyStr);
	// remove topic from topicList at index. index starts with 0
	void remove(int topicIndex);
	// remove selected post from topic
	void removePost(int topicIndex, int postIndex);
	// remove selected reply from selected post
	void removeReply(int topicIndex, int postIndex, int replyIndex);
	// print all topics
	void printTopic();
	// print all post of selected topic
	void printTopicPost(int topicIndex);
	// print all replies of selected post
	void printPostReply(int topicIndex, int postIndex);
	// check if dictionary is empty
	bool isEmpty();
	// return int of dictionary length
	int getTopicLength();
	//get the topic string
	ItemType getTopic(int topicIndex);
	//get the user string for topics
	ItemType getTopicUser(int topicIndex);
	//get the post string
	ItemType getPost(int topicIndex, int postIndex);
	//get the user string from post
	ItemType getPostUser(int topicIndex, int postIndex);
	//get the reply string 
	ItemType getReply(int topicIndex, int postIndex, int replyIndex);
	//get the user string from reply
	ItemType getReplyUser(int topicIndex, int postIndex, int replyIndex);
	//get length of post selected
	int getPostLength(int topicIndex);
	//get length of reply from post selected
	int getReplyLength(int topicIndex, int postIndex);


};
