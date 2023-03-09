//prog3-menu.cpp 
#include "prog3-menu.h"

// James Truong		CS302		3-8-2023
// Program #3		Schedule Planner 

/* This file contains the member function implementation for the
menu class interface. These functions will allow the the client to 
call methods to manage events in their schedule. Events are able to be
added, removed, changed, and displayed. */

// Menu class functions:
// Main menu interface, returns int choice
int menu::menu_interface()
{
	do
	{
		main_menu();	// Display main menu options
		choice = valid_opt4(); // Get valid main menu option (0-4)
		//cin.ignore(100, '\n');
		
		if(choice == 1)	// Add event menu
		{
			cout << "SELECTED: (1) Add Event ";
			do
			{
				add_menu();	// Display add event menu options
				next_choice = valid_opt3(); // Get valid event menu options (0-3)
				//cin.ignore(100, '\n');

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
		else if(choice == 2)	// Edit event menu
		{
			cout << "SELECTED: (2) Edit Event \n";
			do
			{
				edit_menu();
				next_choice = valid_opt3();
				//cin.ignore(100, '\n');

				/*if(next_choice == 1)
				else if(next_choice == 2)
				else if(next_choice == 3) */

			} while(next_choice != 0);
		}
		else if(choice == 3)	// Delete event menu
		{
			cout << "SELECTED: (3) Delete Event \n";
			do
			{
				delete_menu();
				next_choice = valid_opt2();
				//cin.ignore(100, '\n');

				/*if(next_choice == 1)
				else if(next_choice == 2) */

			} while(next_choice != 0);
		}
		else if(choice == 4)	// Display event menu
		{
			cout << "SELECTED: (4) Display Event \n";
			do
			{
				display_menu();
				next_choice = valid_opt4();
				//cout << "Enter event title to display: ";
				//getline(cin, search);

				/*if(next_choice == 1)
				else if(next_choice == 2)*/

			} while(next_choice != 0);
		}
		else if(choice == 0)	// Exit main menu - exit program
		{
			cout << "SELECTED: (0) Exit Program \n";
		}
	} while (choice != 0);

	return choice;	
}// Function to get a valid option integer between 0-2
int menu::valid_opt2()
{
	int temp = 0;	// Temporary integer variable to return to store valid int
	do
	{
		try
		{
			cout << "Select an option: "; // Prompt input
			if(!(cin >> temp))	// Check that the input was an integer
			{
				cin.clear(); 	// Clear any error flags
				cin.ignore(100, '\n');	// Input buffer 
				// Invalid input exception
				throw invalid_argument("Input was not an int. Please enter an integer.");
			}
			// Invalid range exception
			else if(temp != 0 && temp != 1 && temp != 2)	
				throw out_of_range("Input was not in valid range. Enter 1, 2, or 0.");
			cin.ignore(100, '\n');
		}
		catch(const exception & err)
		{
			cerr << err.what() << endl; 	// Display error message A
			continue;			// Go back to get valid input 
		}	
	} while(temp != 0 && temp != 1 && temp != 2); // Check for valid int options

	return temp;	// Return the valid int 
}
// Function to get a valid option integer between 0-3
int menu::valid_opt3()
{
	int temp = 0;	// Temporary integer variable to return to store valid int
	do
	{
		try
		{
			cout << "Select an option: "; // Prompt input
			if(!(cin >> temp))	// Check that the input was an integer
			{
				cin.clear(); 	// Clear any error flags
				cin.ignore(100, '\n');	// Input buffer 
				// Invalid input exception
				throw invalid_argument("Input was not an int. Please enter an integer.");
			}
			// Invalid range exception
			else if(temp != 0 && temp != 1 && temp != 2 && temp != 3) 
				throw out_of_range("Input was not in valid range. Enter 1, 2, 3, or 0.");
			cin.ignore(100, '\n');
		}
		catch(const exception & err)
		{
			cerr << err.what() << endl; 	// Display error message A
			continue;			// Go back to get valid input 
		}	
	} while(temp != 0 && temp != 1 && temp != 2 && temp != 3); // Check for valid int options

	return temp;	// Return the valid int 
}
// Function to get a valid option integer between 0-4
int menu::valid_opt4()
{
	int temp = 0;	// Temporary integer variable to return to store valid int
	do
	{
		try
		{
			cout << "Select an option: "; // Prompt input
			if(!(cin >> temp))	// Check that the input was an integer
			{
				cin.clear(); 	// Clear any error flags
				cin.ignore(100, '\n');	// Input buffer 
				// Invalid input exception
				throw invalid_argument("Input was not an int. Please enter an integer.");
			}
			// Invalid range exception
			else if(temp != 0 && temp != 1 && temp != 2 && temp != 3 && temp != 4)
				throw out_of_range("Input was not in valid range. Enter 1, 2, 3, 4, or 0.");
			cin.ignore(100, '\n');
		}
		catch(const exception & err)
		{
			cerr << err.what() << endl; 	// Display error message A
			continue;			// Go back to get valid input 
		}	
	} while(temp != 0 && temp != 1 && temp != 2 && temp != 3 && temp != 4); 
	// Check for valid int options

	return temp;	// Return the valid int 
}
// Function to display menu options
void menu::main_menu() const
{
	cout << "Schedule Planner Menu: \n";
	cout << "(1) Add Event \t\t (2) Edit Event \t (3) Delete Event \n";
	cout << "(4) Display Event \t (0) Exit Program\n";
}
// Function to display add event menu options
void menu::add_menu() const
{
	cout << "\nAdd Event Menu: \n";
	cout << "(1) Add Meeting \t (2) Add Workshop \t (3) Add Convention\n";
	cout << "(0) Back \n";
}
// Function to display edit event menu options 
void menu::edit_menu() const
{
	cout << "\nEdit Event Menu: \n";
	cout << "(1) Edit A Meeting \t (2) Edit A Workshop \t (3) Edit A Convention\n";
	cout << "(0) Back \t";
}
// Function to dispaly delete event menu options 
void menu::delete_menu() const
{
	cout << "\nDelete Event Menu: \n";
	cout << "(1) Delete An Event \t (2) Delete All \t (0) Back \n";
}
// Function to display event display menu options 
void menu::display_menu() const
{
	cout << "\nDisplay Event Menu: \n";
	cout << "(1) Display An Event \t (2) Display All \t (0) Back \n";
}
// Function to display welcome message
void menu::welcome_msg() const
{
	cout << "Welcome to the Schedule Planner Program \n";
}
// Function to display exit message
void menu::exit_msg() const
{
	cout << "Exiting the Schedule Planner Program... Goodbye! \n";
}
// Default menu constructor
menu::menu() : my_table(), choice(0), next_choice(0), capacity(0), price(0.00), search(""), 
	a_title(""), a_date(""), a_location(""), a_topic(""), a_instructor(""), a_sponsor("") {}
// Destructor 
menu::~menu() {} 
