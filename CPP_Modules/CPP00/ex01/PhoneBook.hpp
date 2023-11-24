#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
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
    PhoneBook(PhoneBook&);
public:
    PhoneBook();
    short   isActive();
    void    getInput();
    void    update();
    bool    addContact();
    bool    searchContacts();
    void    printBoxed(const std::string& str);
    ~PhoneBook();
};

#endif