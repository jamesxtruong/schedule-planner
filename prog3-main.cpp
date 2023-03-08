//prog3-main.cpp
#include "prog3-table.h"

// James Truong		CS302		3-8-2023
// Program #3		Schedule Planner 

/* This is the client test program where the application can 
test the software through an interface of calls. */

int main()
{
	int choice = 0;		// Main menu choice variable (int option)
	int next_choice = 0;	// Next menu choice variable (int option)
	string search;		// String variable to store search
	table my_table;		// Table to organize events
	//event * ptr;		// ABC pointer (testing)

	cout << "Welcome to the Schedule Planner Program \n";
	do
	{
		cout << "Schedule Planner Menu: \n";
		cout << "(1) Add Event \t\t (2) Edit Event \t (3) Delete Event \n";
		cout << "(4) Display Event \t (0) Exit Program\n";
		cout << "Select a menu option: ";
		cin >>  choice;
		cin.ignore(100, '\n');
		
		if(choice == 1)
		{
			cout << "SELECTED: (1) Add Event ";
			do
			{
				cout << "\nAdd Event Menu: \n";
				cout << "(1) Add Meeting \t (2) Add Workshop \t (3) Add Convention\n";
				cout << "(0) Back \t";
				cout << "Select an option: ";
				cin >> next_choice;
				cin.ignore(100, '\n');

				if(next_choice == 1)
				{
					cout << "SELECTED: (1) Add Meeting \n";
					//meeting a_meeting;
					//event * ptr = &a_meeting;
					event * ptr = new meeting;
					if(ptr->add_event())
						ptr->display_event();
					if(ptr)
						delete ptr;
					ptr = nullptr;
				}
				else if(next_choice == 2)
				{
					cout << "SELECTED: (2) Add Workshop \n";
					//workshop a_workshop;
					//event * ptr = &a_workshop;
					event * ptr = new workshop;
					if(ptr->add_event())
						ptr->display_event();
					if(ptr)
						delete ptr;
					ptr = nullptr;
				}
				else if(next_choice == 3)
				{
					cout << "SELECTED: (3) Add Convention \n";
					//convention a_convention;
					//event * ptr = &a_convention;
					event * ptr =  new convention;
					if(ptr->add_event())
						ptr->display_event();
					if(ptr)
						delete ptr;
					ptr = nullptr;
					
				}
				else if(next_choice == 0)
				{
					cout << "SELECTED: (0) Back \n";
				}
			} while(next_choice != 0);
		}
		else if(choice == 2)
		{
			cout << "SELECTED: (2) Edit Event \n";
		}
		else if(choice == 3)
		{
			cout << "SELECTED: (3) Delete Event \n";
		}
		else if(choice == 4)
		{
			cout << "SELECTED: (4) Display Event \n";
			cout << "Enter event title to display: ";
			getline(cin, search);
		}
		else if(choice == 0)
		{
			cout << "SELECTED: (0) Exit Program \n";
		}
	} while (choice != 0);


	return 0;
}
