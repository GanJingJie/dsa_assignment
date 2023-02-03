#include "Dictionary.h"
#include <string>
#include <iostream>

using namespace std;




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