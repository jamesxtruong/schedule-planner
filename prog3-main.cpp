//prog3-main.cpp
//#include "prog3-table.h"
#include "prog3-menu.h"

// James Truong		CS302		3-8-2023
// Program #3		Schedule Planner 

/* This is the client test program where the application can 
test the software through a menu interface of available options. 
This program allows the user to create a schedule/planner to track 
their events. Events include: meetings, workshops, and conventions.
The interface will allow for insertion, removal, and display.*/

int main()
{
	int select = 0;		// Int menu interface select
	menu my_menu;		// Menu interface object called my menu

	my_menu.welcome_msg();	 // Program welcome message call
	
	// Menu interface loop
	do
	{
		// Menu interface call
		select = my_menu.menu_interface(); 

	} while(select != 0); 	// 0 option interface select to exit
	
	return 0;
}
