#include "Reply.h"
#include <string>
#include <iostream>
using namespace std;

Reply::Reply() {
	for (int i = 0; i < reply_max; i++) {
		replies[i] = NULL;
	}

	reply_size = 0;
}

bool Reply::add(Itemtype reply) {
	bool success = reply_size < reply_max;
	if (success)
	{
		replies[reply_size]->reply = reply;
		reply_size++;
	}

	return success;
}

void Reply::remove(int index) {
	bool success = (index >= 0) && (index <= reply_max);
	if (success)
	{
		for (int i = index; i < reply_size; i++)
		{
			replies[i] = replies[i + 1];
			reply_size--;
		}
	}
}