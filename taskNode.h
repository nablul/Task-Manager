/***************************************************************
Title: Task.h
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Header file for "taskNode"
***************************************************************/

#ifndef __CS235_TASKNODE_H_
#define __CS235_TASKNODE_H_

#include"Task.h"

struct taskNode {
	Task task;
	taskNode *next;

	//Default constructor
	taskNode();

	//Default destructor
	~taskNode();

	//Overloaded < operator
	bool comparator(taskNode* lhs, taskNode* rhs);

	//Converts string from pre-specified format by user to a task item
	Task* stringToTask(std::string fileString, Task* task);

	//Converts task item to string in pre-specified format by user
	std::string tasktoString(Task task);
};

#endif