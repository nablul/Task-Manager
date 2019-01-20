/***************************************************************
Title: ToDoListApp.h
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Header file for "ToDoListApp"
***************************************************************/

#ifndef __CS235_TODOLISTAPP_H_
#define __CS235_TODOLISTAPP_H_

#include<iostream>
#include<algorithm>
#include"TodoListDriver.h"

class ToDoListApp {

public:
	//Main application run
	void run();

	//Define in/out in terms of cin/cout
	ToDoListApp(std::istream& in = std::cin, std::ostream& out = std::cout) : in(in), out(out) {}

protected:

	//Predefined task types
	enum TaskType : char{ GENERIC = 'G', HOMEWORK = 'H', EVENT = 'E', SHOPPING = 'S'};

	//Executes Print command
	void executeCommandPrint(bool completed = false, bool detailed = false);

	//Executes AddTask command
	void executeCommandAddTask();

	//Executes RemoveTask command
	void executeCommandRemoveTask();

	//Executes CompleteTask command
	void executeCommandCompleteTask();

	//Executes Save command
	void executeCommandSave();

	//Executes Load command
	void executeCommandLoad();

private:
	//in/out in terms of cin/cout
	std::istream& in = std::cin;
	std::ostream& out = std::cout;

	//Private variable definitions
	char type_;
	std::string dateStr_;
	std::string desc_;
	std::string tmpInput;
	std::vector<std::string> addlInfo_;

	//Initialize driver item and task numbering variable
	ToDoListDriver driver;
	int taskNumber;
};

#endif