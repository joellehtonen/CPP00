#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <charconv>
#include "Contact.hpp"

class PhoneBook
{
	private:
		std::string 		list_;

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
		bool		checkValidIndex(std::string index);
};