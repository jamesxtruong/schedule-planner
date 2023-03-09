//prog3-schedule.cpp
#include "prog3-schedule.h"

//using namespace std;

// James Truong		CS302		3-8-2023
// Program #3		Schedule Planner 

/* This is the file that implements the member functions for the schedule.h
file containing the abstract base class event and it's derived classes (meeting, 
workshop, convention)*/

// Functions:

// Abstract base class
// Default constructor
event::event() {}
// Parameterized constructor to set members
event::event(const string & t, const string & d, const string & l) : 
	title(t), date(d), location(l) {}
// Destructor
event::~event() {}
// Function to return the title/name of event
string event::get_title() const
{
	return title;
}
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
	event(t, d, l), /*title(t), date(d), location(l),*/ topic(a_topic) {}
// Destructor
meeting::~meeting() 
{
	/*title.clear();
	date.clear();
	location.clear();
	topic.clear();*/
}
// Add a meeting event
int meeting::add_event() 
{
	string t, d, l, a_topic;
	cout << "Enter name of meeting: ";
	getline(cin, t);
	//cin.ignore(100, '\n');
	cout << "Enter date of meeting: ";
	getline(cin, d);
	//cin.ignore(100, '\n');
	cout << "Enter location of meeting: ";
	getline(cin, l);
	//cin.ignore(100, '\n');
	cout << "Enter topic for meeting: ";
	getline(cin, a_topic);
	//cin.ignore(100, '\n');

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
/*int meeting::display_event(const string & t) 
{
	if(title == t)
	{
		cout << *this;
		return 1;
	}
	return 0;
} */
void meeting::display_event() const
{
	if(!title.empty())	// Check if meeting has title name
	{
		cout << *this;	// Overloaded output op
		//return 1;
		return;
	}
	else if(title.empty())	// Missing title/name
		throw invalid_argument("Meeting does not have title/name.");
	//return 0;
	return;
}
// Delete a meeting event 
int meeting::delete_event(const string & name) 
{
	if(title == name)	// Check for matching meeting title/name
	{
		title.clear();
		date.clear();
		location.clear();
		topic.clear();
		// Echo
		cout << "Meeting deleted." << endl;
		return 1;
	}
	else	// Missing title/name
		throw invalid_argument("No matching meeting found.");
	return 0;
}
// Overloaded output (display) for meeting event
ostream & operator << (ostream & cout, const meeting & op2)
{
	cout << static_cast<const event &>(op2);	// Call abc << first
	cout << left << setw(15) << op2.topic;		// Output meeting member (topic)
	return cout;
}

// Workshop subclass of event
// Default constructor
workshop::workshop() : capacity(0), instructor("")  {}
// Parameterized constructor
workshop::workshop(const string & t, const string & d, const string & l, const int & cap, const string & a_instructor) :
	event(t, d, l),/*title(t), date(d), location(l),*/ capacity(cap), 
		instructor(a_instructor) {} 
// Destructor
workshop::~workshop() 
{
	/*title.clear();
	date.clear();
	location.clear();
	instructor.clear();*/
	capacity = 0;
}
// Add a workshop event
int workshop::add_event()
{
	string t, d, l, inst;
	int cap = 0;
	cout << "Enter name of workshop: ";
	getline(cin, t);
	//cin.ignore(100, '\n');
	cout << "Enter date of workshop: ";
	getline(cin, d);
	//cin.ignore(100, '\n');
	cout << "Enter location of workshop: ";
	getline(cin, l);
	//cin.ignore(100, '\n');
	cout << "Enter workshop seating capacity: ";
	cin >> cap;
	cin.ignore(100, '\n');
	cout << "Enter name of workshop instructor: ";
	getline(cin , inst);
	//cin.ignore(100, '\n');

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
/*int workshop::display_event(const string & t)
{
	if(title == t)
	{
		cout << *this;
		return 1;
	}
	return 0;
} */
void workshop::display_event() const
{
	if(!title.empty())	// Check if workshop has title/name
	{
		cout << *this;	// Overloaded output op
		//return 1;
		return;
	}
	else if(title.empty())	// Missing title/name
		throw invalid_argument("Workshop does not have title/name");
	//return 0;
	return;
}
// Delete a meeting event
int workshop::delete_event(const string & name) 
{
	if(title == name)	// Check for matching workshop title/name
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
	else	// Missing title/name
		throw invalid_argument("No matching workshop found.");
	return 0;
}
// Change workshop capacity - non self-similar and non virtual method
int workshop::change_capacity(const int & num)
{
	capacity = num;		// Update the capacity for workshop
	return capacity;	// Return the capacity
}
// Change workshop instructor - non self-similar and non virtual method
int workshop::change_instructor(const string & replace)
{
	if(replace.empty())	// Check if instructor replacement has name
		throw invalid_argument("Missing replacement instructor name.");
	instructor = replace;		// Update the instructor for workshop
	return !instructor.empty();
}
// Overloaded output (display) for workshop event
ostream & operator << (ostream & cout, const workshop & op2)
{
	cout << static_cast<const event &>(op2);	// Call abc << op
	// Output workshop members (capacity, instructor)
	cout << left << setw(15) << op2.capacity << setw(15) << op2.instructor;
	return cout;
}
// Convention subclass of event
// Default constructor
convention::convention() : admission(0.00), sponsor("") {}
// Parameterized constructor 
convention::convention(const string & t, const string & d, const string & l, const float & price, const string & company) :
	event(t, d, l), /*title(t), date(d), location(l),*/admission(price), 
		sponsor(company) {}
// Destructor
convention::~convention() 
{
	/*title.clear();
	date.clear();
	location.clear();
	sponsor.clear();*/
	admission = 0.00;
}
// Add a convention event
int convention::add_event()
{
	string t, d, l, company;
	float price = 0.00;
	cout << "Enter name of convention: ";	// Prompt for convention title/name
	getline(cin, t);
	//cin.ignore(100, '\n');
	cout << "Enter date of convention: ";	// Prompt for convention date
	getline(cin, d);
	//cin.ignore(100, '\n');
	cout << "Enter location of convention: "; // Prompt for convention location
	getline(cin, l);
	//cin.ignore(100, '\n');
	cout << "Enter convention admission price: ";	// Prompt for convention admission price
	cin >> price;
	cout << "Enter name of convention sponsor: ";	// Prompt for convention sponsor
	getline(cin, company);
	//cin.ignore(100, '\n');
	
	// Update convention event (store)
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
/*int convention::display_event(const string & t)
{
	if(title == t)
	{
		cout << *this;
		return 1;
	}
	return 0;
}*/
void convention::display_event() const
{
	if(!title.empty())
	{
		cout << *this;
		//return 1;
		return;
	}
	//return 0;
	return;
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
	cout << static_cast<const event &>(op2);	// Call abc << op
	// Output convention members (admission, sponsor)
	cout << left << setw(15) << op2.admission << setw(15) << op2.sponsor;
	return cout;
}
