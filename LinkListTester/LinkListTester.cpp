/**
	A quick, simple application to test a Linked List implementation... 
	Author: R. LaChance
*/


#include <iostream>
#include "ListInterface.h"
#include "LinkedList.h"
#include "Node.h"


// Function prototypes
int mainMenu();
void displayMenu();
int itemToDelete(int numberItems);
int add();


int main() {

	// Declarations
	int exit = 6;
	int userChoice = 0;
	ListInterface<int>* intList = new LinkedList<int>();
	
	while (userChoice != exit) {
		userChoice = mainMenu();

		switch (userChoice){
			case 1:
				intList->insert(1, add());
				break;
			case 2:
				if (!intList->remove(itemToDelete(intList->getLength())))
					std::cout << "Item not removed!\n";
				else
					std::cout << "Item removed!\n";
				break;
			case 3:
				intList->reverse();
				break;
			case 4:
				intList->outputList();
				break;
			case 5:
				std::cout << "Total items: " << intList->getLength() << std::endl;
				break;
			default:
				break;
		} // End switch
	} // End while loop
	
	std::cout << "Thanks for using my Linked List tester!\n";
	system("pause");
	return 0;
}


/**
	Integer function that determines the position of the item to be deleted.  
	@param numberItems - An int value that represents the total number of items in the list.
	@return - An integer value that represents a validated position of an element to delete.
*/
int itemToDelete(int numberItems){
	int elementToDelete = 0;
	bool validInput = false;

	std::cout << "Enter the position of item (not 0-based) to delete: ";

	do {
		if ((std::cin >> elementToDelete) && (elementToDelete <= numberItems)){
			validInput = true;
		}else{
			std::cout << "Not valid integer, try again!\n";
			std::cin.clear();
			std::cin.ignore(200,'\n');
		} // End if/else
	} while (!validInput);

	return elementToDelete;
} // End itemToDelete


/**
	Integer function that determines an integer value to add to the linked list
	@return - A validated integer value to add to the linked list
*/
int add(){
	int valueToAdd = 0;
	bool validInput = false;

	std::cout << "Enter an integer value to add to the list: ";

	do {
		if (std::cin >> valueToAdd){
			validInput = true;
		}else{
			std::cout << "Not valid integer, try again!\n";
			std::cin.clear();
			std::cin.ignore(200,'\n');
		} // End if/else
	} while (!validInput);

	return valueToAdd;
} // End add


/**
	A function that returns an integer value that represents the choice that the user made.
	The input is validated, and if not valid menu is repeated until it is.
	@param - No parameters are passed in
	@return - The integer value, action, is returned
*/
int mainMenu(){
	int action = 0;
	bool validChoice = false;

	displayMenu(); // Call to function to display the menu

	do {
		if ((std::cin >> action) && (action <= 6) && (action >= 1)){
			validChoice = true;
		}else{
			std::cout << "Not a valid selection!\n";
			std::cin.clear();
			std::cin.ignore(200, '\n');
		} // End if/else
	} while (!validChoice);

	return action;
} // End mainMenu

/**
	Void function that displays the menu 
	@post - The menu is displayed to the user
*/
void displayMenu() {
	std::cout << "Enter desired action:\n";
	std::cout << "---------------------\n";
	std::cout << " 1) Add value to list\n";
	std::cout << " 2) Delete value from list\n";
	std::cout << " 3) Reverse list\n";
	std::cout << " 4) Display list\n";
	std::cout << " 5) Display total items in list\n";
	std::cout << " 6) Exit\n";
} // End displayMenu