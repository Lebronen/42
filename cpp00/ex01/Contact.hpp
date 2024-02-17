#ifndef DEF_CONTACT
#define DEF_CONTACT

#include <iostream>
#include <string>

class Contact {

    private:

    static int cid;
    int id;
    private : std::string first_name;
    private : std::string last_name;
    private : std::string nickname;
    private : std::string phone_number;
    private : std::string darkest_secret;

    public:
    Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret);
    Contact();

    std::string getFirstName();

    std::string getLastName();

    std::string getNickname();

    std::string getPhoneNumber();

    std::string getDarkestSecret();

    int getId();

    void printSearch();

    void printContact();

    ~Contact();


};


#endif