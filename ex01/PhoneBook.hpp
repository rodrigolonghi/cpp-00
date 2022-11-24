#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <string>

class PhoneBook {
	public:
		Contact contacts[8];

		PhoneBook();
		~PhoneBook();
		void init();
	private:
		int		saved_contacts;

		bool		check_input(std::string);
		void		add_contact();
		void		search_contact();
		void		save_new_contact(Contact);
		std::string	get_data(std::string);
		std::string	truncate_string(std::string);
};

#endif
