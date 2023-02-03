#include "Posts.h"
#include <string>
#include <iostream>
using namespace std;

Posts::Posts() 
{
	firstPost = NULL;
	size = 0;
}

Posts::~Posts()//addOn
{
	postNode* current = firstPost;

	while (!isEmpty)
	{
		
	}
}

// Adding to end of list
bool Posts::add(itemType post, itemType user) 
{
	postNode* newNode = new postNode;
	newNode->next = NULL;
	newNode->post = post;
	newNode->user = user;
	newNode->reply = NULL;

	if (size == 0)
	{
		firstPost = newNode;
	}

	else
	{
		postNode* temp = firstPost;
		while (temp->next = NULL)
		{
			temp = temp->next;

		}
		temp->next = newNode;
	}
	size++;
	return true;
}

// Adding to middle of list
bool Posts::edit(int index, itemType post, itemType user) 
{
	if (index < size)
	{
		postNode* newNode = new postNode;
		newNode->post = post;
		newNode->user = user;
		newNode->reply = NULL;
		newNode->next = NULL;

		if (index == 0)
		{
			newNode->next = firstPost;
			firstPost->next = newNode;
		}

		else
		{
			postNode* temp = firstPost;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;

			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		size++;
		return true;
	}
}


// Deleting at index
void Posts::remove(int index) 
{
	if (size >= index)
	{
		if (index == 0)
		{
			if (size == 1)
			{
				firstPost->reply = NULL;
				firstPost = firstPost->next;

			}
			else
			{
				postNode* temp = firstPost;
				firstPost = firstPost->next;
				temp->next = NULL;
				temp->reply = NULL;
				delete temp;
			}

		}
		else
		{
			postNode* current = firstPost;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			postNode* temp = current;
			current = current->next;
			temp->next = current->next;
			current->next = NULL;
			current->reply = NULL;
			delete current;
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
	postNode* current = firstPost;
	for (int i = 0; i < size; i++)
	{
		cout << current->post << endl;
		replyNode* 
	}


}