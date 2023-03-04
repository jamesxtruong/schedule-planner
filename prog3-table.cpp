//prog3-table.cpp
#include "prog3-table.h"

// James Truong		CS302		3-3-2023
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
	/*if(ptr)
		delete ptr;
	ptr = nullptr; */
}
// Get left node
unique_ptr<node> node::get_left()
{
	return move(left);
}
// Get right node
unique_ptr<node> node::get_right()
{
	return move(right);
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

// Table (BST) class
// Default constructor
table::table() : root(nullptr) {}
// Destructor 
table::~table()
{
}

