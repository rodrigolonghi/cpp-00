#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::truncate_string(std::string str) {
	std::string	aux;
	std::string	result;

	if (str.length() <= 10)
		return str;
	aux = str.substr(0, 9);
	result = aux + ".";
	return result;
}

void PhoneBook::search_contact() {
	int			index;
	std::string	field;

	if (saved_contacts == 0) {
		std::cout << "\nNo contacts saved yet!\n\n";
		return ;
	}
	std::cout << std::endl;
	std::cout.width(10); std::cout << std::right << "Index" << "|";
	std::cout.width(10); std::cout << std::right << "First Name" << "|";
	std::cout.width(10); std::cout << std::right << "Last Name" << "|";
	std::cout.width(10); std::cout << std::right << "Nickname" << "|";
	std::cout << std::endl;
	for (int i = 0; i < saved_contacts; i++) {
		std::cout.width(10); std::cout << std::right << saved_contacts;
		std::cout << "|";
		field = truncate_string(this->contacts[i].first_name);
		std::cout.width(10); std::cout << std::right << field;
		std::cout << "|";
		field = truncate_string(this->contacts[i].last_name);
		std::cout.width(10); std::cout << std::right << field;
		std::cout << "|";
		field = truncate_string(this->contacts[i].nickname);
		std::cout.width(10); std::cout << std::right << field;
		std::cout << "|\n";
	}
	std::cout << "\n\nSelect the index to see complete contact data: ";
	getline(std::cin, field);
	std::stringstream sstr(field);
	sstr >> index;
	while (index > saved_contacts || index < 1) {
		std::cout << "\nInvalid index selected.\nPlease, try again.";
		std::cout << "\n\nSelect the index to see complete contact data: ";
		getline(std::cin, field);
		std::stringstream sstr(field);
		sstr >> index;
	}
	std::cout << "\nFirst name: " << this->contacts[index - 1].first_name << std::endl;
	std::cout << "Last name: " << this->contacts[index - 1].last_name << std::endl;
	std::cout << "Nickname: " << this->contacts[index - 1].nickname << std::endl;
	std::cout << "Phone number: " << this->contacts[index - 1].phone_number << std::endl;
	std::cout << "Darkest secret: " << this->contacts[index - 1].darkest_secret << "\n\n";
}

void PhoneBook::save_new_contact(Contact contact) {
	if (this->saved_contacts == 7)
		this->saved_contacts = 0;
	this->contacts[this->saved_contacts].first_name = contact.first_name;
	this->contacts[this->saved_contacts].last_name = contact.last_name;
	this->contacts[this->saved_contacts].nickname = contact.nickname;
	this->contacts[this->saved_contacts].phone_number = contact.phone_number;
	this->contacts[this->saved_contacts].darkest_secret = contact.darkest_secret;
	this->saved_contacts++;
}

std::string PhoneBook::get_data(std::string field) {
	std::string data;

	std::cout << std::endl << field << ": ";
	getline(std::cin, data);
	while (data.empty()) {
		std::cout << std::endl << field << " can't be null.\nPlease, try again.\n";
		std::cout << std::endl << field << ": ";
		getline(std::cin, data);
	}
	return data;
}

void PhoneBook::add_contact() {
	Contact contact;

	std::cout << "\nInsert the contact informations:\n";
	contact.first_name = get_data("First name");
	contact.last_name = get_data("Last name");
	contact.nickname = get_data("Nickname");
	contact.phone_number = get_data("Phone number");
	contact.darkest_secret= get_data("Darkest secret");
	save_new_contact(contact);
}

bool PhoneBook::check_input(std::string input) {
	if (input.compare("ADD") == 0) {
		add_contact();
		return true;
	}
	else if (input.compare("SEARCH") == 0) {
		search_contact();
		return true;
	}
	else if (input.compare("EXIT") == 0) {
		std::cout << "\nSee you never, user.\nBye bye!\n";
		return false;
	}
	else {
		std::cout << "\nInvalid option!\nPlease, try again.\n\n";
		return true;
	}
}

void PhoneBook::init() {
	std::string	input;

	this->saved_contacts = 0;
	std::cout << "Choose one option: ADD, SEARCH, EXIT\n";
	getline(std::cin, input);
	while (check_input(input)) {
		std::cout << "Choose one option: ADD, SEARCH, EXIT\n";
		getline(std::cin, input);
	}
	exit(0);
}
