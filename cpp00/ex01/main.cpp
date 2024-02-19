#include <iostream>
#include <string>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main () {

   std::string line;
   PhoneBook book;
   std::string prenom;
   std::string nom;
   std::string surnom;
   std::string numero;
   std::string secret;

   while (1) {
    std::getline(std::cin, line);
    if (!std::cin)
        break;
    if (!line.compare("ADD")) {
        prenom = "";
        nom = "";
        surnom = "";
        numero = "";
        secret = "";
        while (prenom == "")
        {
            if (!std::cin)
                exit(0);
            std::cout << "prenom : ";
            std::getline(std::cin, prenom);
            if (prenom == "")
                std::cout << "ce champ ne peut rester vide" << std::endl;
        }
        while (nom == "") {
            if (!std::cin)
                exit(0);
            std::cout << "nom : ";
            std::getline(std::cin, nom);
            if (nom == "")
                std::cout << "ce champ ne peut rester vide" << std::endl;
        }
        while (surnom == "") {
            if (!std::cin)
                exit(0);
            std::cout << "surnom : ";
            std::getline(std::cin, surnom);
            if (surnom == "")
                std::cout << "ce champ ne peut rester vide" << std::endl;
        }
        while (numero == "") {
            if (!std::cin)
                exit(0);
            std::cout << "numero de telephone : ";
            std::getline(std::cin, numero);
            if (numero == "")
                std::cout << "ce champ ne peut rester vide" << std::endl;
        }
        while (secret == "") {
            if (!std::cin)
                exit(0);
            std::cout << "plus grand secret : ";
            std::getline(std::cin, secret);
            if (secret == "")
                std::cout << "ce champ ne peut rester vide" << std::endl;
        }
        Contact contact(prenom, nom, surnom, numero, secret);
        book.add(contact);
        
    }
    else if (!line.compare("SEARCH")) {
        book.search();
    }
    else if (!line.compare("EXIT")) {
        break;
    }
   }
   return 0;
}