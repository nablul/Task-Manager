/***************************************************************
Title: ToDoListApp.cpp
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Implementation file for "ToDoListApp"
***************************************************************/

/**************************************************************
I/O interface
***************************************************************/

#include"ToDoListApp.h"

//Main application run
void ToDoListApp::run() {
	out << "Welcome to your To-Do List! You may begin to enter commands.";
	out << std::endl;

	//Checks user input against predefined commands
	std::string command;
	do {
		out << "> ";
		getline(in, command);

		//Converts entire command to uppercase for easy compares
		std::transform(command.begin(), command.end(), command.begin(), ::toupper);

		//Checks user input with available commands. Return error message if command is not valid
		if (command == "PRINT") {
			executeCommandPrint();
		}
		else if (command == "DETAILED") {
			executeCommandPrint(false, true);
		}
		else if (command == "COMPLETED") {
			executeCommandPrint(true);
		}
		else if (command == "ADD") {
			executeCommandAddTask();
		}
		else if (command == "REMOVE") {
			executeCommandRemoveTask();
		}
		else if (command == "COMPLETE") {
			executeCommandCompleteTask();
		}
		else if (command == "SAVE") {
		executeCommandSave();
		}
		else if (command == "LOAD") {
		executeCommandLoad();
		}
		else if (command == "EXIT") {
			out << "Thank you for using To-Do List!\n";
			break;
		}
		else {
			out << "Unknown Command (" << command << "). Try Again.\n";
		}
		out << "\n";
	} while (true);
};

//Executes PrintTask command
void ToDoListApp::executeCommandPrint(bool completed, bool detailed) {
	taskNode* tmp;
	TaskType taskChoice;
	
	//Determine which sortedTaskList to work with
	if (completed == true) {
		tmp = driver.returnFirstNode(true);
	}
	else {
		tmp = driver.returnFirstNode(false);
	};

	//Iterate through list and display information
	if (tmp != nullptr) {
		taskNumber = 1;

		while (tmp != nullptr) {
			if (tmp->task.type == 'G') { taskChoice = GENERIC; }
			else if (tmp->task.type == 'H') { taskChoice = HOMEWORK; }
			else if (tmp->task.type == 'E') { taskChoice = EVENT; }
			else if (tmp->task.type == 'S') { taskChoice = SHOPPING; };

			out << taskNumber << ". " << tmp->task.date.returnDateStr(tmp->task.date) << " - ";

			//Switch case for enum
			switch (taskChoice) {
				case GENERIC:{break; };
				case HOMEWORK:{out << "[Homework] "; break; };
				case EVENT:{out << "[Event] "; break; };
				case SHOPPING:{out << "[Shopping] "; break; };
			};

			out << tmp->task.desc << std::endl;

			//Output for detailed display
			if (detailed == true) {
				switch (taskChoice) {
				case GENERIC:
				{
					break;
				};
				case HOMEWORK:
				{
					out << "\t" << "Subject: " << std::endl;
					out << "\t" << tmp->task.addlInfo[0] << std::endl;
					break;
				};
				case EVENT:
				{
					out << "\t" << "Location: " << std::endl;
					out << "\t" << tmp->task.addlInfo[0] << std::endl;
					out << "\t" << "Time: " << std::endl;
					out << "\t" << tmp->task.addlInfo[1] << std::endl;
					break;
				};
				case SHOPPING:
				{
					out << "\t" << "Items: " << std::endl;
					for (size_t i = 0; i < tmp->task.addlInfo.size(); ++i) {
						out << "\t" << tmp->task.addlInfo[i] << std::endl;
					};
					break;
				};
				};
			};

			tmp = tmp->next;
			++taskNumber;
		};
	}
	//Error message for no completed tasks available
	else if (completed == true) {
		out << "There are no completed tasks." << std::endl;
	}
	//Error message for no incomplete tasks available
	else {
		out << "There are no outstanding tasks." << std::endl;
	};
};

//Executes AddTask command
void ToDoListApp::executeCommandAddTask() {
	//Create new Task and define enum for Task type
	Task* task = new Task;
	TaskType taskChoice;

	//Input for task type. Assignment corresponding enum
	out << "What type of task is this? [G: Generic, S: Shopping, E: Event, H: Homework]" << std::endl << "> ";
	type_ = getchar();
	if (type_ == 'G') { taskChoice = GENERIC; }
	else if (type_ == 'H') { taskChoice = HOMEWORK; }
	else if (type_ == 'E') { taskChoice = EVENT; }
	else if (type_ == 'S') { taskChoice = SHOPPING; }
	else {
		out << "Please enter a valid task type." << std::endl;
		return;
	};

	//Input for date and description
	out << "What is the deadline for this task (MM/DD/YYYY format)?" << std::endl << "> ";
	in.ignore();
	getline(in, dateStr_);
	out << "How would you describe this task?" << std::endl << "> ";
	getline(in, desc_);
	Date date_(dateStr_);
	task->type = type_;
	task->desc = desc_;
	task->date = date_;

	//Additional input for special cases
	switch (taskChoice) {
	case GENERIC:
	{
		break;
	};
	case HOMEWORK:
	{
		out << "What subject is this homework task for?" << std::endl << "> ";
		getline(in, tmpInput);
		addlInfo_.push_back(tmpInput);
		tmpInput = "";
		break;
	};
	case SHOPPING:
	{
		out << "What items do you need to buy? [Type your item and press ENTER to add another item. Type DONE to complete the list.]" << std::endl << "> ";
		while (true) {
			getline(in, tmpInput);
			if (tmpInput == "DONE" || tmpInput == "done" || tmpInput == "Done") {
				break;
			}
			else {
				addlInfo_.push_back(tmpInput);
				out << "> ";
			};
		}
		tmpInput = "";
		break;
	};
	case EVENT:
	{
		out << "Where is this event taking place?" << std::endl << "> ";
		getline(in, tmpInput);
		addlInfo_.push_back(tmpInput);
		out << "When is this event taking place?" << std::endl << "> ";
		getline(in, tmpInput);
		addlInfo_.push_back(tmpInput);
		tmpInput = "";
		break;
	};
	};

	//Add additional input to Task and clear additional input vector for next input
	task->addlInfo = addlInfo_;
	addlInfo_.clear();

	//Add Task to list
	driver.addTask(task);
	out << "Task added successfully." << std::endl;
};

//Executes RemoveTask command
void ToDoListApp::executeCommandRemoveTask() {

	//Error message for no incomplete tasks
	if (driver.incompleteTasks.size == 0) {
		out << "There are currently no outstanding tasks." << std::endl;
	}

	//Typical case
	else {
		out << "Which task would you like to remove?" << std::endl << "> ";
		in >> taskNumber;
		in.ignore();
		if (driver.removeTaskbyPos(taskNumber) == true) {
			out << "Task removed successfully." << std::endl;
		}
		else {
			out << "You have entered an invalid task number!" << std::endl;
		};
	};
};

//Executes CompleteTask command
void ToDoListApp::executeCommandCompleteTask() {

	//Error message for no incomplete tasks
	if (driver.incompleteTasks.size == 0) {
		out << "There are currently no outstanding tasks." << std::endl;
	}

	//Typical case
	else {
		out << "Which task would you like to complete?" << std::endl << "> ";
		in >> taskNumber;
		in.ignore();
		if (driver.completeTaskbyPos(taskNumber) == true) {
			out << "Task marked complete successfully." << std::endl;
		}
		else {
			out << "You have entered an invalid task number!" << std::endl;
		};
	};
};
 
//Executes Save command
void ToDoListApp::executeCommandSave() {

	//Error message for no incomplete tasks
	if (driver.incompleteTasks.size == 0) {
		out << "You have no outstanding tasks!" << std::endl;
	}

	//Typical case
	else {
		out << "Where would you like to save your outstanding tasks?" << std::endl << "> ";
		std::string fileName;
		getline(in, fileName);
		if (driver.saveIncompleteTasks(fileName) == true) {
			out << "Tasks saved successfully!" << std::endl;
		}
		else {
			out << "Error saving tasks. Please try again." << std::endl;
		};
	};
};

//Executes Load command
void ToDoListApp::executeCommandLoad() {

	//Typical case
	out << "Where would you like to load outstanding tasks from?" << std::endl << "> ";
	std::string fileName;
	getline(in, fileName);
	if (driver.loadIncompleteTasks(fileName) == true) {
		out << "Tasks loaded successfully!" << std::endl;
	}

	//Error message for unsuccessful loading
	else {
		out << "Error loading tasks. Please try again." << std::endl;
	};
};
