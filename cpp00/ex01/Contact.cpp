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

void truncPrint(std::string arg) {
    int cut;

    cut = arg.length() - 10;
    if (cut > 0) {
        std::cout << arg.substr(0, 10);
        std::cout << ".|";
     }
    else {
        std::cout << std::setw(10);
        std::cout << arg << "|";
    }

}

void Contact::printSearch() {
    std::cout << std::setw(10);
    std::cout << id << "|";
    truncPrint(first_name);
    truncPrint(last_name);
    truncPrint(nickname);
    std::cout << std::endl;

}

void Contact::printContact() {
    std::cout << first_name << std::endl << last_name << std::endl << nickname << std::endl << phone_number << std::endl;
    std::cout << darkest_secret << std::endl;
}

Contact::~Contact() {

}