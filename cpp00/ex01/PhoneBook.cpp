#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    nb = 0;

}

void PhoneBook::add(Contact contact) {
    int id = contact.getId();
    if (id >= 8) {
        id = id % 8;
    }

    livre[id] = contact;
    if (nb < 8)
        nb++;
}

bool isnumber(std::string s) {
    for (long unsigned int i = 0; i < s.length(); i++) {
        if (!std::isdigit(s[i]))
            return (false);
    }
    return (true);
}

int ft_atoi(const std::string& str) {
    std::istringstream ss(str);
    int result;
    ss >> result;
    return result;
}

void PhoneBook::search() {
    std::string sid;
    int nid;
    for (int i = 0; i < nb; i++) {
        livre[i].printSearch();
    }
    std::cout << "entrez l'id du contact à afficher : ";
    std::getline(std::cin, sid);
    if (!isnumber(sid)) {
        std::cout << "identifiant incorrect" << std::endl;
        return ;
    }
    nid = ft_atoi(sid);
    if (nid >= nb) {
        std::cout << "identifiant incorrect" << std::endl;
        return ;
    }
    livre[nid].printContact();

}

PhoneBook::~PhoneBook() {
    
}
    

