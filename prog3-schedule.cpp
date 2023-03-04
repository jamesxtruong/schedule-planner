//prog3-schedule.cpp

#include "prog3-schedule.h"

//using namespace std;

// James Truong		CS302		3-3-2023
// Program #3		Schedule Planner 

/* This is the file that implements the member functions for the schedule.h
file containing the abstract base class event and it's derived classes (meeting, 
workshop, convention)*/

// Functions:

// Abstract base class
// Default constructor
event::event() : title(""), date(""), location("") {}
// Parameterized constructor 
event::event(const string & t, const string & d, const string & l) : 
	title(t), date(d), location(l) {}
// Destructor
event::~event() {}
// Overloaded output (display) for event title, date, location
ostream & operator << (ostream & cout, const event & op2)
{
	cout << left << setw(50) << op2.title << setw(15) << op2.date << setw(15) 
		<< op2.location;
	return cout;
}

// Meeting subclass of event
// Default constructor
meeting::meeting() : topic("") {}
// Parameterized constructor
meeting::meeting(const string & t, const string & d, const string & l, const string & a_topic) : 
	event(t, d, l), topic(a_topic) {}
// Destructor
meeting::~meeting() {}
// Add a meeting event
int meeting::add_event() 
{
	string t, d, l, a_topic;
	cout << "Enter name of meeting: ";
	getline(cin, t);
	cout << "Enter date of meeting: ";
	getline(cin, d);
	cout << "Enter location of meeting: ";
	getline(cin, l);
	cout << "Enter topic for meeting: ";
	getline(cin, a_topic);

	title = t;
	date = d;
	location = l;
	topic = a_topic;

	return 1;
}
// Edit a meeting event
int meeting::edit_event(const string & t)
{
	if(title == t)
		return add_event();	
	return 0;
}
// Display a meeting event
int meeting::display_event(const string & t) 
{
	if(title == t)
	{
		cout << *this;
		return 1;
	}
	return 0;
}
// Delete a meeting event
int meeting::delete_event(const string & name) 
{
	if(title == name)
	{
		title.clear();
		date.clear();
		location.clear();
		topic.clear();
		// Echo
		cout << "Meeting deleted." << endl;
		return 1;
	}
	return 0;
}
// Overloaded output (display) for meeting event
ostream & operator << (ostream & cout, const meeting & op2)
{
	cout << static_cast<const event &>(op2);
	cout << left << setw(15) << op2.topic;
	return cout;
}

// Workshop subclass of event
// Default constructor
workshop::workshop() : capacity(0), instructor("") {}
// Parameterized constructor
workshop::workshop(const string & t, const string & d, const string & l, const int & cap, const string & a_instructor) :
	event(t, d, l), capacity(cap), instructor(a_instructor) {}
// Destructor
workshop::~workshop() {}
// Add a workshop event
int workshop::add_event()
{
	string t, d, l, inst;
	int cap = 0;
	cout << "Enter name of workshop: ";
	getline(cin, t);
	cout << "Enter date of workshop: ";
	getline(cin, d);
	cout << "Enter location of workshop: ";
	getline(cin, l);
	cout << "Enter workshop seating capacity: ";
	cin >> cap;
	cout << "Enter name of workshop instructor: ";
	getline(cin , inst);

	title = t;
	date = d;
	location = l;
	capacity = cap;
	instructor = inst;

	return 1;
}
// Edit a workshop event
int workshop::edit_event(const string & t)
{
	if(title == t)
		return add_event();
	return 0;
}
// Display a workshop event
int workshop::display_event(const string & t)
{
	if(title == t)
	{
		cout << *this;
		return 1;
	}
	return 0;
}
// Delete a meeting event
int workshop::delete_event(const string & name) 
{
	if(title == name)
	{
		title.clear();
		date.clear();
		location.clear();
		capacity = 0;
		instructor.clear();
		// Echo
		cout << "Workshop deleted." << endl;
		return 1;
	}
	return 0;
}
// Change workshop capacity
int workshop::change_capacity(const int & num)
{
	capacity = num;
	return capacity;
}
// Change workshop instructor
int workshop::change_instructor(const string & replace)
{
	instructor = replace;
	return !instructor.empty();
}
// Overloaded output (display) for workshop event
ostream & operator << (ostream & cout, const workshop & op2)
{
	cout << static_cast<const event &>(op2);
	cout << left << setw(15) << op2.capacity << setw(15) << op2.instructor;
	return cout;
}
// Convention subclass of event
// Default constructor
convention::convention() : admission(0.00), sponsor("") {}
// Parameterized constructor 
convention::convention(const string & t, const string & d, const string & l, const float & price, const string & company) :
	event(t, d, l), admission(price), sponsor(company) {}
// Destructor
convention::~convention() {}
// Add a convention event
int convention::add_event()
{
	string t, d, l, company;
	float price = 0.00;
	cout << "Enter name of convention: ";
	getline(cin, t);
	cout << "Enter date of convention: ";
	getline(cin, d);
	cout << "Enter location of convention: ";
	getline(cin, l);
	cout << "Enter convention admission price: ";
	cin >> price;
	cout << "Enter name of convention sponsor: ";
	getline(cin, company);

	title = t;
	date = d;
	location = l;
	admission =  price;
	sponsor = company;

	return 1;
}
// Edit a convention event
int convention::edit_event(const string & t)
{
	if(title == t)
		return add_event();
	return 0;
}
// Display a convention event
int convention::display_event(const string & t)
{
	if(title == t)
	{
		cout << *this;
		return 1;
	}
	return 0;
}
// Delete a convention event
int convention::delete_event(const string & name)
{
	if(title == name)
	{
		title.clear();
		date.clear();
		location.clear();
		admission = 0.00;
		sponsor.clear();
		// Echo
		cout << "Convention was deleted." << endl;
		return 1;
	}
	return 0;
}
// Overloaded output (display) for convention event
ostream & operator << (ostream & cout, const convention & op2)
{
	cout << static_cast<const event &>(op2);
	cout << left << setw(15) << op2.admission << setw(15) << op2.sponsor;
	return cout;
}
