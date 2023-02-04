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
	newNode->next = NULL;
	newNode->topic = topic;
	newNode->user = user;
	newNode->postNode = NULL;

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

bool List::addPost(ItemType postStr, ItemType user)
{
	return post.add(postStr, user);
}

bool List::addReply(ItemType replyStr, ItemType user)
{
	return post.addReply(replyStr, user);
}

bool List::edit(int index, ItemType topic)
{
	if (size > index)
	{
		if (index == 0)
		{
			firstNode->topic = topic;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 0; i < size; i++)
			{
				temp = temp->next;
			}
			temp->topic = topic;
		}
	}
	return true;
}

bool List::editPost(int index, ItemType postStr)
{
	return post.edit(index, postStr);
}

bool List::editReply(int index, ItemType replyStr)
{
	return post.editReply(index, replyStr);
}

void List::remove(int index)
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
				temp->postNode = NULL;
				delete temp;
			}
		}

		else
		{
			Node* prev;
			for (int i = 0; i < index; i++)
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

void List::removePost(int index)
{
	post.remove(index);
}

void List::removeReply(int index)
{
	post.removeReply(index);
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

void List::printPost()
{
	post.printPost();
}

void List::printReply()
{
	post.printReply();
}

bool List::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

int List::getLength()
{
	return size;
}


//int charvalue(char c)
//{
//	if (isalpha(c))
//	{
//		if (isupper(c))
//			return (int)c - (int)'A';
//		else
//			return (int)c - (int)'a' + 26;
//	}
//	else
//		return -1;
//}
//
//Dictionary::Dictionary()
//{
//	for (int i = 0; i < max_size; i++)
//	{
//		items[i] = NULL;
//	}
//	size = 0;
//}
//
//Dictionary::~Dictionary() {
//	// Deconstructor required
//}
//
//int Dictionary::hash(KeyType key)
//{
//	int strvalue = NULL;
//	for (int i = 1; i < key.length(); i++)
//	{
//		strvalue += charvalue(key[i]);
//	}
//
//	return strvalue;
//}
//
//bool Dictionary::add(KeyType nKey, ItemType nUser)
//{
//	int value = hash(nKey);
//	if (items[value] == NULL)
//	{
//		Node* newNode = new Node();
//		newNode->key = nKey;
//		newNode->user = nUser;
//		newNode->post = NULL;
//		newNode->next = NULL;
//
//		items[value] = newNode;
//	}
//
//	else
//	{
//		Node* temp = items[value];
//		if (temp->key == nKey)
//		{
//			return false;
//		}
//
//		while (temp->next != NULL)
//		{
//			if (temp->key == nKey)
//			{
//				return false;
//			}
//
//			temp = temp->next;
//		}
//
//		Node* newNode = new Node();
//		newNode->key = nKey;
//		newNode->user = nUser;
//		newNode->post = NULL;
//		newNode->key = nKey;
//		items[value] = newNode;
//		temp->next = newNode;
//	}
//
//	size++;
//	cout << "Topic created successfully!" << endl;
//	return true;
//}
//
//void Dictionary::remove(KeyType key)
//{
//	int value = hash(key);
//	if (items[value] != NULL)
//	{
//		Node* temp = items[value];
//		items[value] = NULL;
//		delete temp;
//		size--;
//	}
//}
//
//postNode *Dictionary::getPost(KeyType key)
//{
//	int value = hash(key);
//	if (items[value] != NULL)
//	{
//		return items[value]->post;
//	}
//
//}
//
//bool Dictionary::isEmpty()
//{
//	if (size == 0)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
//int Dictionary::getLength()
//{
//	return size;
//}
//
//void Dictionary::printTopic()
//{
//	int count = 1;
//	for (int i = 0; i < max_size; i++)
//	{
//		if (items[i] != NULL)
//		{
//			cout << count << ". " << items[i]->key << endl;
//			count++;
//		}
//	}
//}