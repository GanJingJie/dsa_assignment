#include "Posts.h"
#include <string>
#include <iostream>
using namespace std;

Posts::Posts() {
	for (int i = 0; i < max_array; i++) {
		posts[i] = NULL;
	}

	size = 0;
}

Posts::~Posts(){}

// Adding to end of list
bool Posts::add(itemType post) {
	bool success = size < max_array;
	if (success)
	{
		posts[size]->post = post;
		size++;
	}

	return success;
}

// Adding to middle of list
bool Posts::add(int index, itemType post) {
	bool success = (index >= 0) && (index <= size) && (size < max_array);
	if (success)
	{  
		for (int pos = size; pos >= index; pos--) {
			posts[pos] = posts[pos - 1];
		}

		posts[index]->post = post;
		size++; 
	}
	return success;
}

// Deleting at index
void Posts::remove(int index) {
	bool success = (index >= 0) && (index <= max_array);
	if (success)
	{
		for (int i = index; i < size; i++)
		{
			posts[i] = posts[i + 1];
			size--;
		}
	}
}

// Checking isEmpty
bool Posts::isEmpty() {
	return size = 0;
}
