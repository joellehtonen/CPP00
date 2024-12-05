#include "Contact.hpp"

std::string	Contact::indexCheck(int index)
{
	if (index == 0)
		return ("first name");
	if (index == 1)
		return ("last name");
	if (index == 2)
		return ("nickname");
	if (index == 3)
		return ("phone number");
	if (index == 4)
		return ("darkest secret");
	else
		return ("");
}

bool	Contact::containsOnlyAlphabet(std::string userInput)
{
	for (std::string::iterator it = userInput.begin(); it != userInput.end(); it++)
	{
		if (std::isalpha(*it) == false && *it != '-')
			return (false);
	}
	return (true);
}

bool	Contact::containsOnlyNumber(std::string userInput)
{
	for (std::string::iterator it = userInput.begin(); it != userInput.end(); it++)
	{
		if (std::isdigit(*it) == false)
			return (false);
	}
	return (true);
}

void	Contact::setInput(std::string requestedInformation, std::string userInput)
{
	if (requestedInformation == "first name")
		this->firstName = userInput;
	else if (requestedInformation == "last name")
		this->lastName = userInput;
	else if (requestedInformation == "nickname")
		this->nickname = userInput;
	else if (requestedInformation == "phone number")
		this->phoneNumber = userInput;
	else if (requestedInformation == "darkest secret")
		this->darkestSecret = userInput;
}

bool	Contact::validateInput(std::string userInput, int index)
{
	if (userInput.empty() == true)
	{
		std::cout << "The field cannot be empty" << std::endl << std::endl;
		return (false);
	}
	if (index != 3 && containsOnlyAlphabet(userInput) == false)
	{
		std::cout << "The field must contain only letters" << std::endl << std::endl;
		return (false);
	}
	if  (index == 3 && containsOnlyNumber(userInput) == false)
	{
		std::cout << "The field must contain only numbers" << std::endl << std::endl;
		return (false);
	}
	return (true);
}

void	Contact::setContactInformation(void)
{
	std::string	requestedInformation;
	std::string	userInput;

	for (int i = 0; i < 5; i++)
	{
		userInput.clear();
		requestedInformation = indexCheck(i);
		while (true)
		{
			std::cout << "Please enter the contact's " << requestedInformation << std::endl;
			std::getline(std::cin, userInput);
			if (validateInput(userInput, i) == true)
				break ;
		}
		setInput(requestedInformation, userInput);
		std::cout << std::endl;
	}
	std::cout << "Contact saved successfully" << std::endl;
	return ;
}
