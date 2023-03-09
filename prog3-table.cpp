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
	for(const auto & event_ptr : my_events)	// Iterate
	{
		if(auto ptr = dynamic_cast<meeting*>(event_ptr.get()))	 // Meeting ptr
		{
			ptr->display_event();
			++count;
		}
		else if(auto ptr = dynamic_cast<workshop*>(event_ptr.get()))	// Workshop ptr
		{
			ptr->display_event();
			++count;
		}
		else if(auto ptr = dynamic_cast<convention*>(event_ptr.get())) // Convention ptr
		{
			ptr->display_event();
			++count;
		}
		//cout << *ptr << endl;	// Display the ptr
		//++count; 	// Increment count
	} 
	return count; 		// Return the count
}
// Function to take a base class pointer event and store it into the node (list)
int node::insert_data(unique_ptr<event> & a_ptr)
{
	my_events.push_back(move(a_ptr)); // Append the base class pointer event to list of events
	if(my_events.empty())
		throw invalid_argument("Failed to insert event.");
		//return 0;
	return 1;
}
// Function to return the name/title of the event stored in the node (list)
string node::get_data() const
{
	string temp;	// Temporary string to return
	for(const auto & ptr : my_events)
	{
		temp = ptr->get_title();	
	}
	return temp;
}
// Function to return the pointer to the event 
/*
//event& & node::return_event(const string & title); // Search for event 
unique_ptr<event> node::return_event(const string & title) // Search for event 
{
	for(auto & ptr: my_events) // Search the list in the node
	{
		if(ptr->get_title() == title)
			return ptr;
			//return *ptr; // Return reference to object
	}
	// No matching event title/name 
	return nullptr;
}*/
// Table (BST) class
// Default constructor
table::table() : root(nullptr) {}
// Destructor 
table::~table() {}
// Function to insert an event to the table (BST) wrapper
int table::insert(unique_ptr<event> & a_ptr)
{
	if(!root)	// Empty table case
	{
		root = make_unique<node>();
		return root->insert_data(a_ptr);
	}
	return insert(root, a_ptr);
}
// Function to insert an event to the table (BST) recursive
int table::insert(unique_ptr<node> & root, unique_ptr<event> & a_ptr)
{
	if(!root)	// Base case, insert at a leaf 
	{
		root = make_unique<node>();
		return root->insert_data(a_ptr);
	}
	
	//if(a_ptr->get_title() < root->get_data())		// Less than
	if(root->greater_equal(a_ptr->get_title()))
		return insert(root->get_left(), a_ptr);
	else							// Greater or equal
		return insert(root->get_right(), a_ptr); 
}
/*// Function to search for an event int he table (BST) and return the pointer/reference
unique_ptr<event> table::find_event(const string & title)
{
	if(!root)
		return nullptr;
	
}
// Function to search for an event recursively 
unique_ptr<event> table::find_event(const unique_ptr<node> & root, const string & title)
{
	if(!root)
		return nullptr;
} 
// Function to display an event in the table (BST)

int table::display(const string & title) const
{
	if(!root)
		return 0;
}
// Recursive display single event 
int table::display(const unique_ptr<node> & root, const string & title) const
{
	if(!root)
		return 0;
} */
// Function to display all events in the table (BST) in order of sort (alphabet)
int table::display_all() const
{
	if(!root)	// Empty table (BST), nothing to display, return
		return 0;
	return display_all(root);
}
// Recursive display all events stored
int table::display_all(const unique_ptr<node> & root) const
{
	if(!root)	// Base case, stop and return
		return 0;
	int count = display_all(root->get_left()); // Visit left
	count += root->display_list();
	count += display_all(root->get_right());
	return count;
} 
// Function to remove all events in table (BST)
bool table::remove_all() 
{
	if(!root)		// Check if table has any events
		return false; 	// Already emtpy 
	root.reset();		// Destroy the table
	return true;
}
/*
// Function to edit an event 
int table::edit(const string & title) 
{
	if(!root)		// Empty table return
		return 0;
	return edit(root, title);	// Recursive call
}
// Recursive function to traverse to find event to edit
int table::edit(unique_ptr<node> & root, const string & title) 
{
	if(!root)		// Base case, stop
		return 0;
	if(title < root->get_data())	// Title is less
		return edit(root->get_left(), title);
	else if(title > root->get_data()) // Title is greater
		return edit(root->get_right(), title); 
	else	// Found title
	{
		for(const auto & ptr : root->my_events)	// Iterate through the node list
		{
			if(ptr->get_data() == title)
			{
				ptr->edit_event();
			}
		}
		return 1;
	}
}
// Function to remove an event in the table (BST)
int table::remove(const string & title) 
{
	if(!root)
		return 0;
	return remove(root, title);
}
// Recursive function to remove event in the table (BST)
int table::remove(unique_ptr<node> & root, const string & title)
{
	if(!root)
		return 0;
	
}

*/
