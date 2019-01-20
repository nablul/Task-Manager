/***************************************************************
Title: Task.cpp
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Implementation file for "Task"
***************************************************************/

/**************************************************************
creates Task object that stores date, task description, task
type and additional information for non-generic tasks.
***************************************************************/

#include"Task.h"

//Default constructor
Task::Task() {};

//Default destructor
Task::~Task() {};

//Constructor. Creates Task object
Task::Task(const char& type_, const Date& date_, const std::string& desc_, const std::vector<std::string>& addlInfo_) {
	type = type_;
	desc = desc_;
	date = date_;
	addlInfo = addlInfo_;
};

//Copy constructor. Copies all parameters
Task::Task(const Task& rhs) {
	type = rhs.type;
	desc = rhs.desc;
	date = rhs.date;
	addlInfo = rhs.addlInfo;
};

//Overloaded assignment operator. Similar to copy constructor
Task& Task::operator=(const Task& rhs) {

	// Check for self assignment
	if (this == &rhs) {
		return *this;
	}

	type = rhs.type;
	desc = rhs.desc;
	date = rhs.date;
	addlInfo = rhs.addlInfo;
	return *this;
};