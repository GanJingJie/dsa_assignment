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
	Node* current = firstNode;

	while (!isEmpty())
	{
		remove(0);
	}
}

// Adding to end of list
bool Posts::add(ItemType post, ItemType user) 
{
	Node* newNode = new Node;
	newNode->next = NULL;
	newNode->post = post;
	newNode->user = user;
	newNode->replyNode = NULL;

	if (size == 0)
	{
		firstNode = newNode;
	}

	else
	{
		Node* temp = firstNode;
		while (temp->next != NULL)
		{
			temp = temp->next;

		}
		temp->next = newNode;
	}
	size++;
	return true;
}

bool Posts::addReply(int postIndex, ItemType replyStr, ItemType user)
{
	if (size > 0)
	{
		Node* current = firstNode;
		for (int i = 0; i < postIndex; i++)
		{
			current = current->next;
		}
		current->replyNode->add(replyStr, user);
		
	}
	return true;
}

// Adding to middle of list
bool Posts::edit(int postIndex, ItemType post) 
{
	if (size > postIndex)
	{
		if (postIndex == 0)
		{
			firstNode->post = post;
		}
		else
		{
			Node* current = firstNode;
			for (int i = 0; i < postIndex; i++)
			{
				current = current->next;
			}
			current->post = post;
		}
	}
	return true;
}

bool Posts::editReply(int postIndex, int replyIndex, ItemType replyStr)
{
	if (size > postIndex)
	{
		Node* current = firstNode;

		for (int i = 0; i < postIndex; i++)
		{
			current = current->next;
		}
		current->replyNode->edit(replyIndex, replyStr);
		return true;
	}
	return false;
}



// Deleting at index
void Posts::remove(int postIndex) 
{
	if (size > postIndex)
	{
		Node* current = firstNode;
		if (postIndex == 0)
		{
			if (size == 1)
			{
				firstNode = NULL;
			}

			else
			{
				firstNode = firstNode->next;
				current->next = NULL;
				current->replyNode = NULL;
				delete current;
			}
		}

		else
		{
			Node* prev = current;
			for (int i = 0; i < postIndex; i++)
			{
				prev = current;
				current = current->next;
			}
			prev->next = current->next;
			current->next = NULL;
			current->replyNode = NULL;
			delete current;
		}
		size--;
	}
	
}

void Posts::removeReply(int postIndex, int replyIndex)
{
	if (size > postIndex)
	{
		Node* current = firstNode;

		for (int i = 0; i < postIndex; i++)
		{
			current = current->next;
		}
		current->replyNode->remove(replyIndex);
		
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
	Node* current = firstNode;
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << "." << current->post << "\t\t" << current->user << endl;
		current = current->next;
	}

}

void Posts::printPostReply(int postIndex)
{
	if (size > postIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < postIndex; i++)
		{
			current = current->next;
		}
		cout << current->post << "\t\t" << current->user << endl;
		current->replyNode->printReply();
	}

}

ItemType Posts::getPost(int postIndex)
{
	if (size > postIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < postIndex; i++)
		{
			current = current->next;
		}
		return current->post;
	}
	else
	{
		return "0";
	}
}

ItemType Posts::getUser(int postIndex)
{
	if (size > postIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < postIndex; i++)
		{
			current = current->next;
		}
		return current->user;
	}
	else
	{
		return "0";
	}
}