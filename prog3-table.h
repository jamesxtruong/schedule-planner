//prog3-table.h
#include "prog3-schedule.h"
#include <memory>
#include <list>

// James Truong		CS302		3-3-2023
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
		unique_ptr<node> get_left();	// Return pointer to left node
		unique_ptr<node> get_right();	// Return pointer to right node
		bool has_left() const;		// Check for left node
		bool has_right() const;		// Check for right node

	private:
		//event * ptr;			// Pointer to base class
		//unique_ptr<event> ptr;
		list<unique_ptr<event>> my_events;
		unique_ptr<node> left;		// Smart pointer to left node
		unique_ptr<node> right;		// Smart pointer to right node
}; 

class table				// Event tree 
{
	public:
		table();			// Default constructor
		~table();			// Destructor 
		int insert(const event & add);	// Insert an event 
		int display() const;		// Display an event
		int edit(const event & find);	// Edit an event (search)
		int remove(const event & remove);// Remove an event
		int remove_all();		// Remove all events in schedule
	private:
		//node * root;
		unique_ptr<node> root;
		int insert(const event & add, unique_ptr<node> & root);	// Recursive insert
		int display(unique_ptr<node> root) const;		// Recursive display
		int edit(const event & find, unique_ptr<node> & root);	// Recursive search
		int remove(const event & remove, unique_ptr<node> & root);	// Recursive remove
		int remove_all(unique_ptr<node> & root);		// Recursive remove all
};

