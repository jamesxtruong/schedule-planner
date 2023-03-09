//prog3-menu.cpp 
#include "prog3-menu.h"

// James Truong		CS302		3-8-2023
// Program #3		Schedule Planner 

/* This file contains the member function implementation for the
menu class interface. These functions will allow the the client to 
call methods to manage events in their schedule. Events are able to be
added, removed, changed, and displayed. */

// Menu class functions:
// Function interface for adding an event
int menu::add_interface()
{
	int select = 0;	// Local select variable
	do
	{
		add_menu();		// Display add event menu options
		select = valid_opt3(); 	// Get valid event menu options (0-3)

		if(select == 1)		// Add a meeting option
		{
			cout << "SELECTED: (1) Add Meeting \n";
			/*meeting a_meeting;	// Raw pointer test implementation
			event * ptr = &a_meeting;
			event * ptr = new meeting;A
			if(ptr)
				delete ptr;
			ptr = nullptr;*/

			ptr = make_unique<meeting>();	// Upcast base class ptr to meeting
			if(ptr->add_event())		// Call meeting method to add
			{
				cout << "\tADDED MEETING: \n";
				ptr->display_event();	// Call meeting display method (echo)
			}

			my_table.insert(ptr);	// Insert meeting event to table (BST)
			/*{

				try
				{
					// Insert meeting event to table (BST)
					int insert = 
					if(insert == 0)
						throw invalid_argument("Failed to add event.");
					else
					{
						cout << "Meeting that was added: \n";
						ptr->display_event();
					}
				}
				catch(const invalid_argument & err)
				{
					cerr << err.what() << endl; // Display error
					continue;
				}
			} */
		}
		else if(select == 2)	// Add a workshop option
		{
			cout << "SELECTED: (2) Add Workshop \n";
			ptr = make_unique<workshop>();	// Upcast base class ptr to workshop
			if(ptr->add_event())		// Call workshop method to add
			{
				cout << "\tADDED WORKSHOP: \n";
				ptr->display_event();	// Call workshop display method (echo)
			}

			my_table.insert(ptr);		// Insert workshop event to table (BST)
		}
		else if(select == 3)	// Add a convention option
		{
			cout << "SELECTED: (3) Add Convention \n";
			ptr = make_unique<convention>();// Upcast base class ptr to convention
			if(ptr->add_event())		// Call convention method to add
			{
				cout << "\tADDED CONVENTION: \n";
				ptr->display_event();	// Call convention display method (echo)
			}

			my_table.insert(ptr);		// Insert convention event to table (BST)	
		}
		else if(select == 0)	// Exit add event interface
		{
			cout << "SELECTED: (0) Back \n";
		}
	} while(select != 0);	// Loop until (0) is selected

	return select;	// Return the exit option
}
// Function interface for editing an event
int menu::edit_interface()
{
	int select = 0;
	do
	{
		edit_menu();		// Display the edit event menu options
		select = valid_opt3();	// Get valid event menu options (0-4)
	/*	
		if(select == 2) 	// Edit a workshop event to experience downcasting 
		{
			ptr = make_unique<workshop>();	// Upcast base class ptr to workshop
			if(ptr->add_event())		// Call workshop method to add
			{
				cout << "\tADDED WORKSHOP: \n";
				ptr->display_event();	// Call workshop display method (echo)
			}
			//unique_ptr<workshop> workshop_ptr = dynamic_cast<workshop*>(ptr.get()); 
			my_table.insert(ptr);		// Insert workshop event to table (BST)
		}
		if(select == 1)	// Search needs to be implemented to downcast for workshop methods non-virtual
		else if(select == 2)
		else if(select == 3) */

	} while(select != 0);	// Loop until (0) is selected
	return select; // Return the exit option
}
// Function interface for deleting an event
int menu::delete_interface()
{
	int select = 0;
	do
	{
		delete_menu();		// Display the delete event menu options
		select = valid_opt2();	// Get valid event menu options (0-2)
		
		//if(select == 1)
		if(select == 2)
		{
			cout << "\nSELECTED: (2) Remove all events \n";
			try
			{
				bool removed = my_table.remove_all();	// Call to remove all
				if(!removed)	// Throw exception, table was empty (schedule)
					throw invalid_argument("Nothing to remove.");
				else
					cout << "All events removed! \n";
			}
			catch(const invalid_argument & err) // Catch exception
			{
				cerr << err.what() << endl;
				continue;
			}
		}	
		/*else if(select == 2)	// Remove a single event
		{
			cout << "\nSELECTED: (1) Remove an event \n";
			cout << "Enter an event to search: ";
			getline(cin, search);

		}
		*/

	} while(select != 0);	// Loop until (0) is selected
	return select;	// Return the exit option
}
// Function interface for displaying an event
int menu::display_interface()
{
	int select = 0;
	do
	{
		display_menu();		// Display the display event menu options
		select = valid_opt4();	// Get valid event menu options (0-2)

		//cout << "Enter event title to display: ";

		//if(select == 1)
		if(select == 2) // Display all events
		{
			cout << "\nSELECTED: (2) Displaying all events: \n";
			try
			{
				int num = my_table.display_all(); // Call display all table
				if(num == 0) // No events found, empty
					throw invalid_argument("No events to display. Add first.");
			}
			catch(const invalid_argument & err) // Catch exception
			{
				cerr << err.what() << endl;
				continue;
			}
		}
		/*else if(select== 2)
			cout << "\nSELECTED: (1) Display an event: \n";
			cout << "Enter an event to search for: ";
			getline(cin, search);
		*/

	} while(next_choice != 0);
	return select;
}
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
			next_choice = add_interface();	// Call add event interface
		}
		else if(choice == 2)	// Edit event menu
		{
			cout << "SELECTED: (2) Edit Event \n";
			next_choice = edit_interface();	// Call edit event interface
		}
		else if(choice == 3)	// Delete event menu
		{
			cout << "SELECTED: (3) Delete Event \n";
			next_choice = delete_interface(); // Call delete event interface
		}
		else if(choice == 4)	// Display event menu
		{
			cout << "SELECTED: (4) Display Event \n";
			next_choice = display_interface(); // Call display event interface
		}
		else if(choice == 0)	// Exit main menu - exit program
		{
			cout << "SELECTED: (0) Exit Program \n";
			exit_msg(); 	// Call for exit message
		}
	} while (choice != 0);

	return choice;	// Exiting, return 0
}
// Function to get a valid option integer between 0-2
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
		catch(const out_of_range & outr) // Invalid int
		{
			cerr << outr.what() << endl; 	// Display error message
			continue;			// Go back to get valid input
		}
		catch(const exception & err)	// Catch non int
		{
			cerr << err.what() << endl; 	// Display error message 
			temp = 5;
			continue;			// Go back to get valid input 
		}	
		catch(...)			// Any other exception
		{
			cerr << "Invalid input. " << endl;
			continue;
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
		catch(const out_of_range & outr) // Invalid int
		{
			cerr << outr.what() << endl; 	// Display error message
			continue;			// Go back to get valid input
		}
		catch(const exception & err)	// Catch non int
		{
			cerr << err.what() << endl; 	// Display error message 
			temp = 5;
			continue;			// Go back to get valid input 
		}	
		catch(...)			// Any other exception
		{
			cerr << "Invalid input. " << endl;
			continue;
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
		catch(const out_of_range & outr) // Invalid int
		{
			cerr << outr.what() << endl; 	// Display error message
			continue;			// Go back to get valid input
		}
		catch(const exception & err)	// Catch non int
		{
			cerr << err.what() << endl; 	// Display error message 
			temp = 5;
			continue;			// Go back to get valid input 
		}	
		catch(...)			// Any other exception
		{
			cerr << "Invalid input. " << endl;
			continue;
		}
	} while(temp != 0 && temp != 1 && temp != 2 && temp != 3 && temp != 4); 
	// Check for valid int options

	return temp;	// Return the valid int 
}
// Function to display menu options
void menu::main_menu() const
{
	cout << "\nSchedule Planner Menu: \n";
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
	cout << "(_) Edit A Meeting \t (_ Edit A Workshop \t (_) Edit A Convention\n";
	cout << "(0) Back \t";
}
// Function to dispaly delete event menu options 
void menu::delete_menu() const
{
	cout << "\nDelete Event Menu: \n";
	cout << "(_) Delete An Event \t (2) Delete All \t (0) Back \n";
}
// Function to display event display menu options 
void menu::display_menu() const
{
	cout << "\nDisplay Event Menu: \n";
	cout << "(_) Display An Event \t (2) Display All \t (0) Back \n";
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
