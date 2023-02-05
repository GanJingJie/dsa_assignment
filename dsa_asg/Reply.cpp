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
	Node* newNode = new Node;
	newNode->reply = reply;
	newNode->next = NULL;
	newNode->user = user;

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
			Node* temp = firstNode;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;

			}
			temp->reply = reply;
		}
		return true;
	}
	return false;
}



void Reply::remove(int index)
{
	if (size > index)
	{
		Node* temp = firstNode;
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
				delete temp;
			}
		}

		else
		{
			Node* prev = firstNode;
			for (int i = 0; i < index; i++)
			{
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			temp->next = NULL;
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
	return false;
}

bool Reply::getReply(Itemtype& reply, int index)//index starts from 0
{
	if (size > index)
	{
		Node* current = firstNode;

		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		reply = current->reply;
		return true;
	}
	return false;
	
}

void Reply::printReply()
{
	Node* current = firstNode;
	for (int i = 0; i < size; i++)
	{
		cout << "\t"<< i+1 << "." << current->reply << "\t\t" << current->user << endl;
		current = current->next;
	}
}

Itemtype Reply::getReply(int index)
{
	if (size > index)
	{
		Node* current = firstNode;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->reply;
	}
	else
	{
		return "0";
	}
}

Itemtype Reply::getUser(int index)
{
	if (size > index)
	{
		Node* current = firstNode;
		for (int i = 0; i < index; i++)
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