//prog3-schedule.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <iomanip>

using std::ostream;
using namespace std;

// James Truong		CS302		3-8-2023
// Program #3		Shedule Planner

/* This is the header file that will contain the clas interfaces. The base class is 
an event, it is an abstract base class. The derived classes are different events, 
the base class will contain virtual function to use specfic derived class methods. 
The derived classes may have unique methods and members. */

// Class Interface(s):

class event 	// Abstract base class event, virtual self-similar interface methods
{
	public:
		//event();						// Default constructor
		// Parameterized constructor
		//event(const string & t, const string & d, const string & l); 
		virtual ~event();
		virtual int add_event() = 0;				// Virtual method to call add an event
		virtual int edit_event(const string & t) = 0;		// Virtual method to call edit an event
		//virtual int display_event(const string & t) = 0;
		virtual void display_event() const = 0;			// Virtual method to display an event
		virtual int delete_event(const string & name) = 0;	// Virtual method to delete an event
		string get_title() const; 			// Method to return the string title of event
		friend ostream & operator << (ostream & cout, const event & op2); // Output
	//private:
	protected:
		string title;		// Name of event
		string date;		// Date of event
		string location;	// Location of event
};

class meeting : public event		// Derived class meeting is an event
{
	public:
		meeting();				// Default constructor
		// Parameterized constructor
		meeting(const string & t, const string & d, const string & l, const string & a_topic); 
		~meeting();				// Destructor
		int add_event();			// Add a meeting event
		int edit_event(const string & t);	// Edit a meeting event
		//int display_event(const string & t);
		void display_event() const;		// Display a meeting event
		int delete_event(const string & name);	// Delete a meeting event
		// Display meeting event overloaded output
		friend ostream & operator << (ostream & cout, const meeting & op2); 
	private:
		string topic;		// Topic or agenda for meeting
};

class workshop : public event		// Derived class workshop is an event
{
	public:
		workshop();				// Default constructor
		// Parameterized constructor
		workshop(const string & t, const string & d, const string & l, const int & capacity, 
			const string & a_instructor); 
		~workshop();				// Destructor
		int add_event();			// Add a workshop event
		int edit_event(const string & t);	// Edit a workshop event
		//int display_event(const string & t);
		void display_event() const;		// Display a workshop event
		int delete_event(const string & name);	// Delete a workshop event 
		int change_capacity(const int & num);	// Non virtual method to change capacity of workshop
		int change_instructor(const string & replace); // Non virtual method to change instructor of ws
		// Display workshop event overloaded ouput
		friend ostream & operator << (ostream & cout, const workshop & op2);	
	private:
		int capacity;		// Limited spots for workshop
		string instructor;	// Instructor or speaker name
};

class convention : public event		// Derived class convention is an event
{
	public:
		convention();				// Default constructor
		// Parameterized constructor
		convention(const string & t, const string & d, const string & l, const float & price,
			const string & company); 
		~convention();				// Destructor
		int add_event();			// Add a convention event
		int edit_event(const string & t);	// Edit a convention event
		//int display_event(const string & t);
		void display_event() const;		// Display a convention event
		int delete_event(const string & name);	// Delete a convention event
		// Display convention event overloaded output
		friend ostream & operator << (ostream & cout, const convention & op2); 
	private:
		float admission;	// Admission pricing for event
		string sponsor;		// Convention sponser
};

