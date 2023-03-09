//prog3-table.h
#include "prog3-schedule.h"
#include <memory>
#include <list>

// James Truong		CS302		3-8-2023
// Program #3		Schedule Planner

/* This is the header file to implement a table. This table is a BST
that will organize the events (meeting, workshop, convention). There
will be options to add, edit, display and remove events from the schedule. */

// Class interface(s):

class node				// Tree node of events
{
	public:
		node();				// Default constructor
		~node();			// Destructor
		unique_ptr<node> & get_left();	// Return pointer to left node
		unique_ptr<node> & get_right();	// Return pointer to right node
		bool has_left() const;		// Check for left node
		bool has_right() const;		// Check for right node
		bool greater_equal(const string & compare) const; // Compare node greater than
		bool less_than(const string & compare) const;	// Compare node less than
		int display_list() const;	// Display the events in a node
		int insert_data(unique_ptr<event> & a_ptr); // Function to store data to node (base ptr)
		string get_data() const; 	// Function to return title name of event
		unique_ptr<event> & return_event(const string & title); // Search for event
	private:
		//event * ptr;			// Raw pointer to base class
		//unique_ptr<event> ptr;	// Single base class event pointer
		list<unique_ptr<event>> my_events; // List of base class event pointers
		unique_ptr<node> left;		// Smart pointer to left node
		unique_ptr<node> right;		// Smart pointer to right node
}; 

class table				// Event tree 
{
	public:
		table();			// Default constructor
		~table();			// Destructor 
		int insert(unique_ptr<event> & a_ptr);	// Insert an event 
		//int display() const;		// Display an event
		int display_all() const;	// Display all events in BST (wrapper)
		//int edit(const event & find);	// Edit an event (search)
		//int remove(const event & remove);// Remove an event
		bool remove_all();		// Remove all events in schedule
		unique_ptr<event> & find_event(const string & title);  // Search for event
	private:
		//node * root;			// Raw node pointer to root of BST
		unique_ptr<node> root;
		// Recursive insert
		int insert(unique_ptr<node> & root, unique_ptr<event> & a_ptr);	
		//int display(unique_ptr<node> root) const;		// Recursive display
		int display_all(const unique_ptr<node> & root) const;	// Recursive display all
		//int edit(const event & find, unique_ptr<node> & root);	// Recursive search
		//int remove(const event & remove, unique_ptr<node> & root);	// Recursive remove
		//int remove_all(unique_ptr<node> & root);		// Recursive remove all
};

