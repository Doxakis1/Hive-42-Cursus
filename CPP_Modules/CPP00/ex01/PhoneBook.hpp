#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
private:
    Contact  contactArray[9];
    int m_index;
    int m_currentlySaved;
    enum e_Input
    {
        ADD,
        SEARCH,
        EXIT,
        ERROR,
        CONTINUE
    };
    e_Input m_input;
public:
    PhoneBook();
    PhoneBook(PhoneBook& copy);
    short   isActive();
    void    getInput();
    void    update();
    bool    addContact();
    bool    searchContacts();
    void    printBoxed(const std::string& str);
    ~PhoneBook();
};

#endif