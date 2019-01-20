/***************************************************************
Title: Task.h
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Header file for "Task"
***************************************************************/

#ifndef __CS235_TASK_H_
#define __CS235_TASK_H_

#include"Date.h"
#include<string>
#include<vector>

struct Task {
	char type;
	std::string desc;
	Date date;
	std::vector<std::string> addlInfo;

	//Default constructor
	Task();

	//Default destructor
	~Task();

	//Constructor. Creates Task object
	Task(const char& type_, const Date& date_, const std::string& desc_, const std::vector<std::string>& addlInfo_);

	//Copy constructor. Copies all parameters except "next" pointer
	Task(const Task& rhs);

	//Overloaded assignment operator. Similar to copy constructor
	Task& operator=(const Task& rhs);
};

#endif