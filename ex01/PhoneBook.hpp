#pragma once
#include <string>
#include <iostream>
#include <vector> //for vector
#include <algorithm> //for .find
#include <iomanip> //for setw
#include "Contact.hpp"

class PhoneBook
{
	private:
		std::vector<int>	_list;

	public:
		PhoneBook() {};
		~PhoneBook() {};

		Contact				contact[8];
		
		void 		addContact(int index);
		void 		displayAllContacts(int max_index);
		void		displayContact(int index);
		void		truncateContactInformation(std::string text);
		void 		searchContact(void);
		void		showFullContact(int index);
		bool		checkValidIndex(int index, std::string command);
};