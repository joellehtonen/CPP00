#include "PhoneBook.hpp"
#include <iostream>

void	instructions(void)
{
	std::cout << "Welcome. Please enter a command" << std::endl;
	std::cout << "ADD: to save a new contact" << std::endl;
	std::cout << "SEARCH: to display a specific contact" << std::endl;
	std::cout << "EXIT: to quit the program" << std::endl;
}

int main(void)
{
	PhoneBook 	phoneBook;
	std::string	userInput;
	int			index = 0;

	while (true)
	{
		instructions();
		std::getline(std::cin, userInput);
		if (userInput == "ADD")
		{
			phoneBook.addContact(index);
			phoneBook.checkValidIndex(index, "add");
			index++;
			if (index > 7)
				index = 0;
		}
		else if (userInput == "SEARCH")
		{
			if (phoneBook.contact[0].firstName.empty() == true)
				std::cout << "No contacts in the phonebook" << std::endl;
			else
			{
				phoneBook.displayContact(index);
				phoneBook.searchContact(userInput);
			}
		}
		else if (userInput == "EXIT")
			break ;
	}
}
