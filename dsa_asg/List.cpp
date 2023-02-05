#include "List.h"
#include <string>
#include <iostream>

using namespace std;

List::List()
{
	firstNode = NULL;
	size = 0;
}

List::~List()
{
	while (!isEmpty())
	{
		remove(0);
	}
}


bool List::add(ItemType topic, ItemType user)
{
	Node* newNode = new Node;
	newNode->topic = topic;
	newNode->user = user;
	newNode->postNode = NULL;
	newNode->next = NULL;

	if (size == 0)
	{
		firstNode = newNode;
	}
	else
	{
		Node* temp = firstNode;
		while (temp->next = NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	size++;
	return true;
}

bool List::addPost(int topicIndex, ItemType postStr, ItemType user)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		current->postNode->add(postStr, user);
		return true;
	}
}

bool List::addReply(int topicIndex, int postIndex, ItemType replyStr, ItemType user)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		current->postNode->addReply(postIndex, replyStr, user);
		return true;
	}
}

bool List::edit(int topicIndex, ItemType topic)
{
	if (size > topicIndex)
	{
		if (topicIndex == 0)
		{
			firstNode->topic = topic;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 0; i < topicIndex; i++)
			{
				temp = temp->next;
			}
			temp->topic = topic;
		}
		return true;
	}
	return false;
}

bool List::editPost(int topicIndex, int postIndex, ItemType postStr)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		current->postNode->edit(postIndex, postStr);
		return true;
	}
	return false;
}

bool List::editReply(int topicIndex, int postIndex, int replyIndex, ItemType replyStr)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		current->postNode->editReply(postIndex, replyIndex, replyStr);
		return true;
	}
	return false;
}

void List::remove(int topicIndex)
{
	if (size > topicIndex)
	{
		Node* temp = firstNode;
		if (topicIndex == 0)
		{
			if (size == 1)
			{
				firstNode = NULL;
			}

			else
			{
				firstNode = firstNode->next;
				temp->next = NULL;
				temp->postNode = NULL;
				delete temp;
			}
		}

		else
		{
			Node* prev = firstNode;
			for (int i = 0; i < topicIndex; i++)
			{
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			temp->next = NULL;
			temp->postNode = NULL;
			delete temp;
		}
		size--;
	}
}

void List::removePost(int topicIndex, int postIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		current->postNode->remove(postIndex);
		
		cout << "Post successfully removed" << endl << endl;
	}
}

void List::removeReply(int topicIndex, int postIndex, int replyIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		current->postNode->removeReply(postIndex, replyIndex);
	}
}

void List::printTopic()
{
	Node* current = firstNode;
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << "." << current->topic << "\t\t" << current->user<< endl;
		current = current->next;
	}
}

void List::printTopicPost(int topicIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		cout << current->topic << '\t\t' << current->user << endl;
		current->postNode->printPost();
	}
}

void List::printPostReply(int topicIndex, int postIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		current->postNode->printPostReply(postIndex);
	}
}

bool List::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

int List::getTopicLength()
{
	return size;
}

ItemType List::getTopic(int topicIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		return current->topic;
	}
	else
	{
		return "0";
	}
}

ItemType List::getTopicUser(int topicIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int  i = 0; i < topicIndex; i++)
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

ItemType List::getPost(int topicIndex, int postIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		return current->postNode->getPost(postIndex);
	}
	else
	{
		return "0";
	}
}

ItemType List::getPostUser(int topicIndex, int postIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		return current->postNode->getPostUser(postIndex);
	}
	else
	{
		return "0";
	}
}

ItemType List::getReply(int topicIndex, int postIndex, int replyIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		return current->postNode->getReply(postIndex, replyIndex);
	}
	else
	{
		return "0";
	}
}

ItemType List::getReplyUser(int topicIndex, int postIndex, int replyIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		return current->postNode->getReplyUser(postIndex, replyIndex);
	}
	else
	{
		return "0";
	}
}

int List::getPostLength(int topicIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		return current->postNode->getPostLength();

	}
	else
	{
		return 0;
	}
}

int List::getReplyLength(int topicIndex, int postIndex)
{
	if (size > topicIndex)
	{
		Node* current = firstNode;
		for (int i = 0; i < topicIndex; i++)
		{
			current = current->next;
		}
		return current->postNode->getReplyLength(postIndex);

	}
	else
	{
		return 0;
	}
}