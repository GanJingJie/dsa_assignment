#include "Posts.h"
#include <string>
#include <iostream>
using namespace std;

Posts::Posts() 
{
	firstNode = NULL;
	size = 0;
}

Posts::~Posts()
{
	postNode* current = firstNode;

	while (!isEmpty)
	{
		remove(0);
	}
}

// Adding to end of list
bool Posts::add(ItemType post, ItemType user) 
{
	postNode* newNode = new postNode;
	newNode->next = NULL;
	newNode->post = post;
	newNode->user = user;
	newNode->reply = NULL;

	if (size == 0)
	{
		firstNode = newNode;
	}

	else
	{
		postNode* temp = firstNode;
		while (temp->next != NULL)
		{
			temp = temp->next;

		}
		temp->next = newNode;
	}
	size++;
	return true;
}

bool Posts::addReply(ItemType reply, ItemType user)
{
	replyNode->add(reply, user);
	return true;
}

// Adding to middle of list
bool Posts::edit(int index, ItemType post) 
{
	if (size > index)
	{
		if (index == 0)
		{
			firstNode->post = post;
		}
		else
		{
			postNode* temp = firstNode;
			for (int i = 0; i < size; i++)
			{
				temp = temp->next;
			}
			temp->post = post;
		}
	}
	return true;
}

bool Posts::editReply(int index, ItemType reply)
{
	replyNode->edit(index, reply);
}

void Posts::removeReply(int index)
{
	replyNode->remove(index);
}

// Deleting at index
void Posts::remove(int index) 
{
	if (size > index)
	{
		postNode* temp = firstNode;
		if (index == 0)
		{
			if (size == 1)
			{
				firstNode = NULL;
			}

			else
			{
				firstNode = firstNode->next;
				temp->next = NULL;
				temp->reply = NULL;
				delete temp;
			}
		}

		else
		{
			postNode* prev;
			for (int i = 0; i < index; i++)
			{
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			temp->next = NULL;
			temp->reply = NULL;
			delete temp;
		}
		size--;
	}
	
}

// Checking isEmpty
bool Posts::isEmpty() 
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Posts::printPost()
{
	postNode* current = firstNode;
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << "." << current->post << "\t\t" << current->user << endl;
		current = current->next;
	}

}

void Posts::printReply()
{
	replyNode->printReply();
}