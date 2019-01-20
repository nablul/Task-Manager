/***************************************************************
Title: Date.cpp
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Implementation file for "Date"
***************************************************************/

/**************************************************************
creates Date object from MM/DD/YYYY string, and handles Date
objects.
***************************************************************/

#include "Date.h"

//Default constructor
Date::Date() {};

//Default destructor
Date::~Date() {};

//Constructor for turning MM/DD/YYYY string into date object. Assume no invalid dates
Date::Date(const std::string& dateStr) {
	//Parse string into month, day and year values
	month = stoi(dateStr.substr(0, 2));
	day = stoi(dateStr.substr(3, 2));
	year = stoi(dateStr.substr(6, 4));
};

//Function that returns MM/DD/YYYY string from date object
std::string Date::returnDateStr(const Date& date) {
	std::string monthStr = std::to_string(date.month);
	std::string dayStr = std::to_string(date.day);
	std::string yearStr = std::to_string(date.year);

	//Add leading 0 to single integer month and day values. Assume year is always 4 digits.
	if (date.month < 10) {
		monthStr = "0" + std::to_string(date.month);
	}
	if (date.day < 10) {
		dayStr = "0" + std::to_string(date.day);
	}

	return monthStr + "/" + dayStr + "/" + yearStr;
};

//Copy constructor
Date::Date(const Date& rhs) {
	month = rhs.month;
	day = rhs.month;
	year = rhs.month;
};

//Overloaded assignment operator. Similar to copy constructor
Date& Date::operator=(const Date& rhs) {

	// Check for self assignment
	if (this == &rhs) {
		return *this;
	}
	month = rhs.month;
	day = rhs.day;
	year = rhs.year;
	return *this;
};

//Overloaded < operator
bool Date::operator<(const Date& rhs) {
	if (this != &rhs) {
		if (year < rhs.year) { return true; }
		else if (year == rhs.year) {
			if (month < rhs.month) { return true; }
			else if (month == rhs.month) {
				if (day < rhs.day) { return true; }
				else if (day == rhs.day) {
					return false;
				};
			};
		};
		return false;
	};
	return false;
};

//Overloaded == operator
bool Date::operator==(const Date& rhs) {
	if (this != &rhs) {
		return(year == rhs.year && month == rhs.month && day == rhs.day);
	};
	return true;
};
