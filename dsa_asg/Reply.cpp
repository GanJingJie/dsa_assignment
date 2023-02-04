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
	while (!isEmpty())
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

bool Reply::edit(int index, Itemtype reply)
{
	if (size > index)
	{

		if (index == 0)
		{
			firstNode->reply = reply;
		}

		else
		{
			replyNode* temp = firstNode;
			for (int i = 0; i < index; i++)
			{
				temp = temp->replyNext;

			}
			temp->reply = reply;
		}
		return true;
	}
}



void Reply::remove(int index)
{
	if (size > index)
	{
		replyNode* temp = firstNode;
		if (index == 0)
		{
			if (size == 1)
			{
				firstNode = NULL;
			}

			else
			{
				firstNode = firstNode->replyNext;
				temp->replyNext = NULL;
				delete temp;
			}
		}

		else
		{
			replyNode* prev = firstNode;
			for (int i = 0; i < index; i++)
			{
				prev = temp;
				temp = temp->replyNext;
			}
			prev->replyNext = temp->replyNext;
			temp->replyNext = NULL;
			delete temp;
		}
		size--;
	}
	
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
		cout << "\t"<< i+1 << "." << current->reply << "\t\t" << current->user << endl;
		current = current->replyNext;
	}
}