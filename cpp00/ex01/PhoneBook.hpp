#ifndef DEF_PHONEBOOK
# define DEF_PHONEBOOK

#include "Contact.hpp"

class PhoneBook {

    private:
    
    Contact livre[8];
    int nb;

    public:

    PhoneBook();
    void add(Contact contact);
    void search();
    ~PhoneBook();

};


#endif