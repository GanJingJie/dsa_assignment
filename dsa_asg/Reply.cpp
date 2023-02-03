#include "Reply.h"
#include <string>
#include <iostream>
using namespace std;

Reply::Reply()
{
	firstNode = NULL;
	size = 0;

}

Reply::~Reply()
{
	while (!isEmpty)
	{
		remove(0);
	}
}

bool Reply::add(Itemtype reply, Itemtype user)
{
	replyNode* newNode = new replyNode;
	newNode->reply = reply;
	newNode->replyNext = NULL;
	newNode->user = user;

	if (size == 0)
	{
		firstNode = newNode;
	}

	else
	{
		replyNode* temp = firstNode;
		while (temp->replyNext != NULL)
		{
			temp = temp->replyNext;

		}
		temp->replyNext = newNode;

	}
	size++;
	return true;
}

void Reply::remove(int index)
{
	if (size > index)
	{
		if (index == 0)
		{
			if (size == 1)
			{
				firstNode = firstNode->replyNext;
			}

			else
			{
				replyNode* temp = firstNode;
				firstNode = firstNode->replyNext;
				temp->replyNext = NULL;
				delete temp;
			}
		}

		else
		{
			replyNode* current = firstNode;
			for (int i = 0; i < index; i++)
			{
				current = current->replyNext;
			}
			replyNode* temp = current;
			current = current->replyNext;
			temp->replyNext = current->replyNext;
			current->replyNext = NULL;
			delete current;
		}
	}
	size--;
}

bool Reply::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
}

void Reply::printReply()
{
	replyNode* current = firstNode;
	for (int i = 0; i < size; i++)
	{
		cout << "\t" << current->reply << endl;
		current = current->replyNext;
	}
}