//prog3-schedule.h

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <iomanip>

// James Truong		CS302		2-22-2023
// Program #3		Shedule Planner

/* This is the header file that will contain the clas interfaces. The base class is 
an event, it is an abstract base class. The derived classes are different events, 
the base class will contain virtual function to use specfic derived class methods. 
The derived classes also have unique methods and members. */

// Class Interface(s):

class event 	// Abstract base class
{
	public:
		virtual int add_event() = 0;
		virtual int edit_event() = 0;
		virtual int display_event() = 0;
		virtual int delete_event() = 0;
	//private:
	protected:
		string title;		// Name of event
		string date;		// Date of event
		string location;	// Location of event
};

class meeting : public event
{
	public:
		int add_event();
		int edit_event();
		int display_event();
		int delete_event();
	private:
};

class workshop : public event
{
	public:
		int add_event();
		int edit_event();
		int display_event();
		int delete_event();
	private:
};

class convention : public event
{
	public:
		int add_event();
		int edit_event();
		int display_event();
		int delete_event();
	private:
};
