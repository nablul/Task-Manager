/***************************************************************
Title: ToDoListDriver.cpp
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Implementation file for "ToDoListDriver"
***************************************************************/

/**************************************************************
Driver class that manages sorted task lists and handles user
inputs
***************************************************************/

#include"TodoListDriver.h"
#include<iostream>

//Adds task to incomplete task list
bool ToDoListDriver::addTask(Task* task) {
	taskNode* node = new taskNode;
	node->task = *task;
	incompleteTasks.insert(node);
	return true;
};

//Removes task by position from incomplete list
bool ToDoListDriver::removeTaskbyPos(const int pos) {
	std::cout << incompleteTasks.size << std::endl;
	return incompleteTasks.remove(pos);
};

//Completes task by position from incomplete list and adds to complete list
bool ToDoListDriver::completeTaskbyPos(const int pos) {

	//Case of invalid position or empty list
	if (incompleteTasks.head == nullptr || pos > incompleteTasks.size || pos <= 0) {
		return false;
	}

	else {
		Task* tmptask = new Task;
		*tmptask = incompleteTasks.at(pos)->task;
		incompleteTasks.remove(pos);
		taskNode* node = new taskNode;
		node->task = *tmptask;
		completeTasks.insert(node);
		return true;
	};
};

//Saves list of incomplete tasks to file
bool ToDoListDriver::saveIncompleteTasks(const std::string fileName) {

	//Create ofstream item and set temp pointer to first element in incomplete tasks list
	std::ofstream outfile(fileName);
	taskNode* tmp = incompleteTasks.head;

	//For each task in incomplete tasks list, convert to string and save to file
	while (tmp != nullptr) {
		outfile << tmp->tasktoString(tmp->task) << std::endl;
		tmp = tmp->next;
	};

	//Close file
	outfile.close();
	return true;
};

//Loads list of incomplete tasks from file and merges with existing list
bool ToDoListDriver::loadIncompleteTasks(const std::string fileName){

	//Create ifstream item
	std::ifstream inFile;
	inFile.open(fileName);

	//Check if file exists and is readable
	if (!inFile) {
		return false;
	}

	//For each line in file, convert string to task item and save in new loaded linked task list
	else {
		sortedTaskList loadedTasks;
		std::string fileLine;
		while (getline(inFile, fileLine)) {
			Task* tmptask = new Task;
			taskNode* node = new taskNode;
			tmptask = node->stringToTask(fileLine, tmptask);
			node->task = *tmptask;
			loadedTasks.insert(node);
		};

		//Close file
		inFile.close();

		//Combine loaded task list with exisitng linked task list of incomplete tasks
		sortedTaskList mergedTasks;
		mergedTasks.mergeLists(incompleteTasks, loadedTasks);

		//Shallow copy merged list to incomplete list. Set first task pointers of loaded and merged tasks = NULL.
		incompleteTasks.head = mergedTasks.head;
		incompleteTasks.size = mergedTasks.size;
		loadedTasks.head = nullptr;
		mergedTasks.head = nullptr;
		return true;
	};
};

//Returns the first task of either complete/incomplete list depending on input
taskNode* ToDoListDriver::returnFirstNode(bool complete) {
	if (complete == true) {
		return completeTasks.head;
	}
	else {
		return incompleteTasks.head;
	};
};