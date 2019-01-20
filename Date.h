/***************************************************************
Title: Date.h
Author: Nablul Haseeb
Date Created: 04/01/2018
Class: Spring 2018, CSCI 235, Mon & Wed 7:00pm - 8:15pm
Professor: Aarsh Vora
Purpose: Project 2
Description: Header file for "Date"
***************************************************************/

#ifndef __CS235_DATE_H_
#define __CS235_DATE_H_

#include<string>

struct Date {
	int month;
	int day;
	int year;

	//Default constructor
	Date();

	//Default destructor
	~Date();

	//Constructor for turning MM/DD/YYYY string into date object. Assume no invalid dates
	Date(const std::string& dateStr);

	//Function that returns MM/DD/YYYY string from date object
	std::string returnDateStr(const Date& date);

	//Copy constructor
	Date(const Date& rhs);

	//Overloaded assignment operator. Similar to copy constructor
	Date& operator=(const Date& rhs);

	//Overloaded < operator
	bool operator<(const Date& rhs);

	//Overloaded == operator
	bool operator==(const Date& rhs);
};

#endif