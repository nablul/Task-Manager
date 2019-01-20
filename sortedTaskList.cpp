/***************************************************************
Title: sortedTaskList.cpp
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Implementation file for "sortedTaskList"
***************************************************************/

/**************************************************************
Sorted linked list for Tasks.
***************************************************************/

#include"sortedTaskList.h"

//Default constructor
sortedTaskList::sortedTaskList() {
	head = nullptr;
	size = 0;
};

//Default destructor
sortedTaskList::~sortedTaskList() {
	taskNode* current = this->head;
	taskNode* tmp;
	while (current != nullptr) {
		tmp = current->next;
		delete current;
		current = tmp;
	};
	head = nullptr;
};

//Function that inserts into list
bool sortedTaskList::insert(taskNode* node) {

	//Insert node as first node
	if (head == nullptr || node->comparator(node, head) == true) {
		pushFront(node);
		return true;
	}

	//List only has first node, and node to be inserted after first node
	else if (head->next == nullptr) {
		node->next = nullptr;
		head->next = node;
		++size;
		return true;
	}

	//Typical algorithm for non-edge conditions
	else {
		taskNode* tmp = head;

		//Determine node before insertion location
		while (tmp->next != nullptr && node->comparator(tmp->next, node)) {
			tmp = tmp->next;
		};

		//Insert node into location determined above
		node->next = tmp->next;
		tmp->next = node;
		++size;
		return true;
	};
	return false;
};

//Removes the node at a given position
bool sortedTaskList::remove(const int pos) {

	//Case of invalid position or empty list
	if (head == nullptr || pos > size || pos <= 0) {
		return false;
	}

	else if (pos == 1) {
		taskNode* tmp = head->next;
		delete head;
		head = tmp;
		--size;
		return true;
	}

	else {
		taskNode* tmp = head;
		for (int i = 0; i < pos - 2; ++i) {
			tmp = tmp->next;
		};
		taskNode* tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
		--size;
		return true;
	};
};

//Function for merging two sorted lists
void sortedTaskList::mergeLists(sortedTaskList& List1, sortedTaskList& List2) {
	size = List1.size + List2.size;
	taskNode* tmp_ptr1 = List1.head;
	taskNode* tmp_ptr2 = List2.head;
	taskNode* sorting = nullptr;

	//If first list is empty, return second list
	if (tmp_ptr1 == nullptr) {
		head = tmp_ptr2;
		return;
	}

	//If second list is empty, return first list
	else if (tmp_ptr2 == nullptr) {
		head = tmp_ptr1;
		return;
	}

	//Condition where both lists contain tasks
	else {
		if (tmp_ptr1 && tmp_ptr2) {
			//Point sorting ptr to first element of merged list
			if (tmp_ptr1->comparator(tmp_ptr1, tmp_ptr2) == true) {
				sorting = tmp_ptr1;
				tmp_ptr1 = sorting->next;
			}
			else {
				sorting = tmp_ptr2;
				tmp_ptr2 = sorting->next;
			};
		};

		//Define head of merged list
		head = sorting;

		//While both lists contain elements
		while (tmp_ptr1 && tmp_ptr2) {

			//move sorting ptr to point element that is next in list
			if (tmp_ptr1->comparator(tmp_ptr1, tmp_ptr2) == true) {
				sorting->next = tmp_ptr1;
				sorting = tmp_ptr1;
				tmp_ptr1 = sorting->next;
			}
			else {
				sorting->next = tmp_ptr2;
				sorting = tmp_ptr2;
				tmp_ptr2 = sorting->next;
			};
		};

		//If first list runs out, point to remainder of second list
		if (tmp_ptr1 == nullptr) {
			sorting->next = tmp_ptr2;
		};

		//If second list runs out, point to remainder of first list
		if (tmp_ptr2 == nullptr) {
			sorting->next = tmp_ptr1;
		};
		return;
	};
};

//Private Functions: Returns the node based on a given position. 
taskNode* sortedTaskList::at(const int pos) {
	taskNode* tmp = head;
	for (int i = 0; i < pos - 1; ++i) {
		tmp = tmp->next;
	};
	return tmp;
};

//Private Functions: Adds node to front of list
bool sortedTaskList::pushFront(taskNode* node) {

	//Edge condition if list is empty
	if (head == nullptr) {
		node->next = nullptr;
		head = node;
		++size;
		return true;
	}

	//Algorithm for non-edge conditions
	else
	{
		node->next = head;
		head = node;
		++size;
		return true;
	};

};
