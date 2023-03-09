//prog3_menu.h
#include "prog3-table.h"

// James Truong		CS302		3-8-2023
// Program #3		Shedule Planner

/* This is the header file to implement a menu class interface. 
This interface will give the client the ability to manage and access
the events for the schedule. Events can be added, removed, changed, and
displayed until the client decides to quit/exit. */

class menu	// Menu class interface
{
	public:
		menu();			  // Default constructor
		~menu();		  // Destructor 
		int menu_interface();	  // The client main menu interface
		int add_interface();	  // Add event interface
		int edit_interface();	  // Edit event interface
		int delete_interface();	  // Delete event interface
		int display_interface();  // Display event interface
		void welcome_msg() const; // Display welcome message 
		void exit_msg() const; 	  // Display exit message
		// Functions
		int valid_opt2(); 	  // Function to check for valid int select (0-2)
		int valid_opt3();	  // Function to check for valid int select (0-3)
		int valid_opt4();	  // Function to check for valid int select (0-4)
		void main_menu() const;   // Display the schedule planner menu
		void add_menu() const; 	  // Display the add event menu 
		void delete_menu() const; // Display the delete event(s) menu 
		void edit_menu() const;   // Display the edit event menu
		void display_menu() const;// Display the display event menu
	private:
		// Variables
		table my_table;		// Table to organize and store events for schedule (BST)
		unique_ptr<event> ptr;	// Base class pointer/reference
		int choice;		// Main menu choice variable (int option)
		int next_choice;	// Next menu choice variable (int option)

		int capacity;		// Integer for capacity of a workshop event
		float price;		// Float for price of admission to convention

		string search;		// String variable to store search for title/name of event
		string a_title;		// Title or name for event
		string a_date;		// Date for event
		string a_location;	// Location for event
		string a_topic;		// Topic name for meeting
		string a_instructor;	// Instructor name for workshop
		string a_sponsor;	// Sponsor name for convention
};
