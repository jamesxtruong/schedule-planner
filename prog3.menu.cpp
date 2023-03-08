//prog3-menu.cpp 
#include "prog3-menu.h"

// James Truong		CS302		3-8-2023
// Program #3		Schedule Planner 

/* This file contains the member function implementation for the
menu class interface. These functions will allow the the client to 
call methods to manage events in their schedule. Events are able to be
added, removed, changed, and displayed. */

		// Functions
		int valid_opt(); 	// Function to check for valid int select
		void welcome_msg() const; // Display welcome message 
		void exit_msg() const; 	  // Display exit message
		void main_menu() const;   // Display the schedule planner menu
		void add_menu() const; 	  // Display the add event menu 
		void edit_menu() const;   // Display the edit event menu
		void display_menu() const;// Display the display event menu

// Menu class functions:
// Default menu constructor
menu::menu() : my_table(), choice(0), next_choice(0), capacity(0), price(0.00), search(""), 
	a_title(""), a_date(""), a_location(""), a_topic(""), a_instructor(""), a_sponsor("") {}
// Destructor 
menu::~menu() {} 
// Function to display welcome message
void menu::welcome_msg() const
{
}
// Function to display exit message
void menu::exit_msg() const
{
}
// Main menu interface, returns int choice
int menu::menu_interface()
{
	
}
// Function to display menu options
void menu::main_menu() const
{
}
// Function to display add event menu options
void menu::add_menu() const
{
}
// Function to display edit event menu options 
void menu::edit_menu() const
{
}
// Function to display event display menu options 
void menu::display_menu() const
{
}
