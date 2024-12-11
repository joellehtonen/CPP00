#include "PhoneBook.hpp"

void	PhoneBook::addContact(int index)
{
	this->contact[index].setContactInformation();
}

void	PhoneBook::displayAllContacts(int max_index)
{
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int index = 0; index < max_index; index++)
		this->displayContact(index);
	std::cout << "|----------|----------|----------|----------|" << std::endl;

}
void	PhoneBook::displayContact(int index)
{
	std::cout << "|" << std::setw(10) << index << "|";
	truncateContactInformation(this->contact[index].firstName);
	truncateContactInformation(this->contact[index].lastName);
	truncateContactInformation(this->contact[index].nickname);
	std::cout << std::endl;
}

void	PhoneBook::truncateContactInformation(std::string text)
{
	if (text.length() > 10)
	{
		text.resize(9);
		text.push_back('.');
	}
	std::cout << std::setw(10) << text;
	std::cout << "|";
}
void	PhoneBook::showFullContact(int index)
{
	std::cout << "First name: ";
	std::cout << this->contact[index].firstName << std::endl;
	std::cout << "Last name: ";
	std::cout << this->contact[index].lastName << std::endl;
	std::cout << "Nickname: ";
	std::cout << this->contact[index].nickname << std::endl;
	std::cout << "Phone number: ";
	std::cout << this->contact[index].phoneNumber << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << this->contact[index].darkestSecret << std::endl;
}

void	PhoneBook::searchContact(void)
{
	std::string userInput;
	int			index = -1;

	std::cout << "Please enter the index of an entry to display more information" << std::endl;
	while (true)
	{
		std::cout << std::endl;
		std::getline(std::cin, userInput);
		std::cout << std::endl;
		if (std::cin.eof() == true)
			std::exit(0);
		if (userInput.empty() == false && userInput.length() == 1 && this->contact->containsOnlyNumber(userInput) == true)
			index = std::stoi(userInput);
		if (this->checkValidIndex(index, "search") == true)
		{
			PhoneBook::showFullContact(index);
			break ;
		}
		std::cout << "Please enter a valid index" << std::endl;
	}
}

bool	PhoneBook::checkValidIndex(int index, std::string command)
{
	if (command == "add")
	{
		list_.push_back(index);
		return (true);
	}
	if (command == "search")
	{
		if (std::find(list_.begin(), list_.end(), index) == list_.end())
		{
			return (false);
		}
		else
			return (true);
	}
	return (false);
}
