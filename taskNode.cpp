/***************************************************************
Title: Task.cpp
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Implementation file for "taskNode"
***************************************************************/

/**************************************************************
Manages task items as nodes
***************************************************************/

#include"taskNode.h"
#include<algorithm>

//Default constructor
taskNode::taskNode() {};

//Default destructor
taskNode::~taskNode() {
	next = nullptr;
	//delete task;
};

//Overloaded < operator
bool taskNode::comparator(taskNode* lhs, taskNode* rhs){
		if (lhs->task.date < rhs->task.date) { return true; }

		//If dates are the same, compare based on description
		if (lhs->task.date == rhs->task.date) {
			return (lhs->task.desc < rhs->task.desc);
		};
		return false;
};

//Converts string from pre-specified format by user to a task item
Task* taskNode::stringToTask(std::string fileString, Task* task) {
	std::string delimiter = "|";
	std::string token;
	size_t pos_start = 0, pos_end;
	size_t delim_len = delimiter.length();
	int pos = 0;

	while ((pos_end = fileString.find(delimiter, pos_start)) != std::string::npos) {
		token = fileString.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;

		if (pos == 0) {
			task->type = token[0];
		}
		else if (pos == 1) {
			Date date(token);
			task->date = date;
		}
		else if (pos == 2) {
			task->desc = token;
		}
		else {
			task->addlInfo.push_back(token);
		};
		++pos;
	};
	if (task->type == 'G') {
		task->desc = fileString.substr(pos_start);
	}
	else {
		task->addlInfo.push_back(fileString.substr(pos_start));
	}
	return task;
};

//Converts task item to string in pre-specified format by user
std::string taskNode::tasktoString(Task task) {
	std::string stringTask;
	std::string delimiter = "|";
	stringTask = task.type + delimiter + task.date.returnDateStr(task.date) + delimiter + task.desc;

	for (size_t i = 0; i < task.addlInfo.size(); ++i) {
		stringTask = stringTask + delimiter + task.addlInfo[i];
	};

	return stringTask;
};