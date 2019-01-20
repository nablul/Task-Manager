/***************************************************************
Title: sortedTaskList.h
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Header file for "sortedTaskList"
***************************************************************/

#ifndef __CS235_SORTEDTASKLIST_H_
#define __CS235_SORTEDTASKLIST_H_

#include"taskNode.h"

class sortedTaskList {
public:
	//Default constructor
	sortedTaskList();

	//Default destructor
	~sortedTaskList();

	//Function that inserts into list
	bool insert(taskNode* node);

	//Removes the node at a given position
	bool remove(const int pos);

	//Function for merging two sorted lists
	void mergeLists(sortedTaskList& List1, sortedTaskList& List2);

private:
	taskNode* head;
	int size;

	//Private Functions: Returns the node based on a given position. 
	taskNode* at(const int pos);

	//Private Functions: Adds node to front of list
	bool pushFront(taskNode* node);

	friend class ToDoListDriver;
	friend class ToDoListApp;
};

#endif