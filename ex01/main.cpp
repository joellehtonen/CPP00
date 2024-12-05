#include "PhoneBook.hpp"
#include <iostream>

void	instructions(void)
{
	std::cout << "ADD: to save a new contact" << std::endl;
	std::cout << "SEARCH: to display a specific contact" << std::endl;
	std::cout << "EXIT: to quit the program" << std::endl;
}

int main(void)
{
	PhoneBook 	phoneBook;
	std::string	userInput;
	int			index = 0;
	int 		max_index = 0;

	std::cout << std::endl << "Welcome. Please enter a command" << std::endl;
	while (true)
	{
		std::cout << std::endl;
		instructions();
		std::cout << std::endl;
		std::getline(std::cin, userInput);\
		std::cout << std::endl;
		if (userInput == "ADD")
		{
			if (index > 7)
				index = 0;
			phoneBook.addContact(index);
			phoneBook.checkValidIndex(index, "add");
			index++;
		}
		else if (userInput == "SEARCH")
		{
			if (phoneBook.contact[0].firstName.empty() == true)
				std::cout << "No contacts in the phonebook" << std::endl;
			else
			{
				if (index > max_index)
					max_index = index;
				phoneBook.displayAllContacts(max_index);
				std::cout << std::endl;
				phoneBook.searchContact();
			}
		}
		else if (userInput == "EXIT")
		{
			std::cout << "Goodbye" << std::endl;
			break ;
		}
		else
			std::cout << "Please enter a valid command" << std::endl;
	}
}
