#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"


int Contact::cid = -1;

Contact::Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret) :
    first_name(first),
    last_name(last),
    nickname(nick),
    phone_number(number),
    darkest_secret(secret)
    {
        Contact::cid++;
        id = cid;
    }

Contact::Contact() {
    
}

std::string Contact::getFirstName() {
    return first_name;
}

std::string Contact::getLastName() {
    return last_name;
}

std::string Contact::getNickname() {
    return nickname;
}

std::string Contact::getPhoneNumber() {
    return phone_number;
}

std::string Contact::getDarkestSecret() {
    return darkest_secret;
}

int Contact::getId() {
    return id;
}

void Contact::printSearch() {
    int cut;
    std::cout << std::setw(10);
    std::cout << id << "|";
    std::cout << std::setw(10);
    cut = first_name.length() - 10;
    if (cut > 0) {
        std::cout << first_name.substr(0, 10);
        for (int i = 0; i < cut; i++) {
            std::cout << ".";
        }
        std::cout << "|";
    }
    else
        std::cout << first_name << "|";
    std::cout << std::setw(10);
    cut = last_name.length() - 10;
    std::cout << last_name << "|";
    std::cout << std::setw(10);
    cut = nickname.length() - 10;
    std::cout << nickname << std::endl;

}

void Contact::printContact() {
    std::cout << first_name << std::endl << last_name << std::endl << nickname << std::endl << phone_number << std::endl;
    std::cout << darkest_secret << std::endl;
}

Contact::~Contact() {

}