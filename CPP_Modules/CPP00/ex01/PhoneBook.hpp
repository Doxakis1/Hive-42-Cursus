#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
private:
    enum e_Input
    {
        ADD,
        SEARCH,
        EXIT,
        ERROR,
        CONTINUE
    };
    static Contact  contactArray[9];
    static  int m_index;
    static  int m_currentlySaved;
    static e_Input m_input;
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