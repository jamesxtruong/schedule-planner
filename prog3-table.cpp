//prog3-table.cpp
#include "prog3-table.h"

// James Truong		CS302		3-8-2023
// Program #3		Schedule Planner 

/* This is the file that implements the member functions for the table.h
These member functions will allow events to be stored and organized in a schedule.
These methods will also allow access to add, edit, display and remove events stored. */

// Functions:

// Table (BST) node class
// Default constructor
node::node() : /*ptr(nullptr),*/ left(nullptr), right(nullptr) {}
// Destructor 
node::~node()
{
	/*if(ptr)		// Raw pointer
		delete ptr;
	ptr = nullptr; */
}
// Get left node
unique_ptr<node> & node::get_left()
{
	//return move(left);
	return left;
}
// Get right node
unique_ptr<node> & node::get_right()
{
	//return move(right);
	return right;
}
// Check for left node
bool node::has_left() const
{
	return left != nullptr;
}
// Check for right node
bool node::has_right() const
{
	return right != nullptr;
}
// Greater than or equal to check
bool node::greater_equal(const string & compare) const
{
	if(compare.empty())	// Check for title to compare
		throw invalid_argument("Event title missing.");
	return my_events.front()->get_title() >= compare;
}
// Less than check 
bool node::less_than(const string & compare) const
{
	if(compare.empty())
		throw invalid_argument("Event title missing.");
	return my_events.front()->get_title() < compare;
}
// Display the events stored in a node 
int node::display_list() const
{
	int count = 0;		// Int count variable to track number of events (list may have more than one)
	
	// Display the list
	for(const auto & ptr : my_events)
	{
		cout << *ptr << endl;
		++count; 	// Increment count
	}
	return count; 		// Return the count
}

// Table (BST) class
// Default constructor
table::table() : root(nullptr) {}
// Destructor 
table::~table() {}
// Function to insert an event to the table (BST)
//int table::insert(unique_ptr<event> & ptr)
//{
//}
// Function to display an event in the table (BST)
/*
int table::display() const
{
}
// Recursive display single event 
int table::display() const
{
}
// Function to display all events in the table (BST) in order of sort (alphabet)
int table::display_all() const
{
}
// Recursive display all events stored
//int table::display_all() const
{
} */
// Function to edit an event 
//int table::edit() {}
// Recursive function to traverse to find event to edit
//int table::edit() {}

// Function to remove an event in the table (BST)
//int table::remove() {}
// Recursive function to remove event in the table (BST)
//int table::remove() {}

// Function to remove all events in table (BST)
//int table::remove_all() {}
// Recursive function to remove all events int he table (BST)
//int table::remove_all() {}

