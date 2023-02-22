//prog3-schedule.h

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <iomanip>

using std::ostream;

// James Truong		CS302		2-22-2023
// Program #3		Shedule Planner

/* This is the header file that will contain the clas interfaces. The base class is 
an event, it is an abstract base class. The derived classes are different events, 
the base class will contain virtual function to use specfic derived class methods. 
The derived classes may have unique methods and members. */

// Class Interface(s):

class event 	// Abstract base class
{
	public:
		event(const string & t, const string & d, const string & l); // Parameterized constructor
		//~event();
		virtual int add_event() = 0;
		virtual int edit_event(const string & t) = 0;
		virtual int display_event(const string & t) = 0;
		virtual int delete_event(const string & name) = 0;
		friend ostream & operator << (ostream & cout, const event & src); // Output
	//private:
	protected:
		string title;		// Name of event
		string date;		// Date of event
		string location;	// Location of event
};

class meeting : public event		// Derived class meeting is an event
{
	public:
		meeting();
		meeting(const string & t, const string & d, const string & l); // Parameterized constructor
		~meeting();
		int add_event();
		int edit_event(const string & t);
		int display_event(const string & t);
		int delete_event(const string & name);
		friend ostream & operator << (ostream & cout, const meeting & src);
	private:
		string topic;		// Topic / agenda for meeting
};

class workshop : public event		// Derived class workshop is an event
{
	public:
		workshop();
		workshop(const string & t, const string & d, const string & l); // Parameterized constructor
		~workshop();
		int add_event();
		int edit_event(const string & t);
		int display_event(const string & t);
		int delete_event(const string & name);
		int change_capacity(const int & num);
		int change_instructor(const string & replace);
		friend ostream & operator << (ostream & cout, const workshop & src);	// Output
	private:
		int capacity;		// Limited spots for workshop
		string instructor;	// Instructor or speaker name
};

class convention : public event		// Derived class convention is an event
{
	public:
		convention();
		convention(const string & t, const string & d, const string & l); // Parameterized constructor
		~convention();
		int add_event();
		int edit_event(const string & t);
		int display_event(const string & t);
		int delete_event(const string & name);
		friend ostream & operator << (ostream & cout, const convention & src); // Output
	private:
		float admission;	// Admission pricing for event
		string sponser;		// Convention sponser
};
/*
class node
{
	public:
		node();
		~node();
	private:
		event * ptr;	
}; */
