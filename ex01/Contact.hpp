#pragma once
#include <string>
#include <iostream>
#include <cctype>

class Contact
{
	public:
		Contact() {};
		~Contact() {};

		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

		void		setContactInformation(void);
		std::string indexCheck(int index);
		bool		validateInput(std::string userInput, int index);
		bool		containsOnlyAlphabet(std::string);
		bool		containsOnlyNumber(std::string);
		void		setInput(std::string requestedInformation, std::string userInput);
};