/***************************************************************
Title: ToDoListDriver.h
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Header file for "ToDoListDriver"
***************************************************************/

#ifndef __CS235_TODOLISTDRIVER_H_
#define __CS235_TODOLISTDRIVER_H_

#include"Task.h"
#include"taskNode.h"
#include"sortedTaskList.h"
#include <iomanip>
#include <fstream>

class ToDoListDriver {
public:
	//Initiate empty lists for complete and incomplete tasks
	sortedTaskList incompleteTasks;
	sortedTaskList completeTasks;

	//Adds task to incomplete task list
	bool addTask(Task* task);

	//Removes task by position from incomplete list
	bool removeTaskbyPos(const int pos);

	//Completes task by position from incomplete list and adds to complete list
	bool completeTaskbyPos(const int pos);

	//Saves list of incomplete tasks to file
	bool saveIncompleteTasks(const std::string fileName);

	//Loads list of incomplete tasks from file and merges with existing list
	bool loadIncompleteTasks(const std::string fileName);

	//Returns the first task of either complete/incomplete list depending on input
	taskNode* returnFirstNode(bool complete);
};

#endif