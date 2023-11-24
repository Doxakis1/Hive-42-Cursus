#include "PhoneBook.hpp"
#include <exception>
#include <iostream>

PhoneBook::PhoneBook()
{
    m_input = PhoneBook::CONTINUE;
    m_index = 0;
}

PhoneBook::PhoneBook(PhoneBook&)
{
}

void PhoneBook::update()
{   
    bool    checker;

    checker = true;
    if (m_input == PhoneBook::ERROR)
        return ;
    switch (m_input)
    {
        case PhoneBook::ADD:
            checker = addContact();
            if (!checker)
                std::cout << "Failed to add new contact!" << std::endl << std::endl;
            break ;
        case PhoneBook::SEARCH:
            checker = searchContacts();
            if (!checker)
                std::cout << "Failed to search contacts!" << std::endl << std::endl;
            break ;
        case PhoneBook::EXIT:
            checker = true;
            m_input = PhoneBook::EXIT;
            return ;
        default:
            break;
    }
    if (checker == false && std::cin.eof() == true)
        m_input = PhoneBook::ERROR;
    else
    {
        m_input = PhoneBook::CONTINUE;
        std::cin.clear();
    }
       
    return ;
}

short   PhoneBook::isActive()
{
    if (m_input == PhoneBook::ERROR || m_input == PhoneBook::EXIT)
    {
        return (0);
    }
    return (1);
}

void   PhoneBook::getInput()
{
    std::string input;
    if (m_input == PhoneBook::ERROR)
        return ;
    std::cout << "Enter your command: ( ADD | SEARCH | EXIT ):";
    std::getline(std::cin, input);
    if (std::cin.good() == false)
        m_input = PhoneBook::ERROR;
    else if (input == "ADD")
        m_input = PhoneBook::ADD;
    else if (input == "SEARCH")
        m_input = PhoneBook::SEARCH;
    else if (input == "EXIT")
        m_input = PhoneBook::EXIT;
    else 
        m_input  = PhoneBook::CONTINUE;
    return ;
}

PhoneBook::~PhoneBook()
{
}

bool   PhoneBook::addContact()
{
    std::string input;

    std::cout << std::endl;
    std::cout << "Enter first name:";
    std::getline(std::cin, input);
    if (std::cin.good() == false)
        return (false);
    if (contactArray[8].setfName(input) == false)
        return (false);
    std::cout << "Enter last name:";
    std::getline(std::cin, input);
    if (std::cin.good() == false)
        return (false);
    if (contactArray[8].setlName(input) == false)
        return (false);
    std::cout << "Enter nickname:";
    std::getline(std::cin, input);
    if (std::cin.good() == false)
        return (false);
     if (contactArray[8].setnName(input) == false)
        return (false);
    std::cout << "Enter phone number:";
    std::getline(std::cin, input);
    if (std::cin.good() == false)
        return (false);
    if (contactArray[8].setpNumber(input) == false)
        return (false);
    std::cout << "Enter deepest secret:";
    std::getline(std::cin, input);
    if (std::cin.good() == false)
        return (false);
    if (contactArray[8].setdSecret(input) == false)
        return (false);
    contactArray[m_index] = contactArray[8];
    if (m_currentlySaved < 8)
        m_currentlySaved++;
    m_index = (m_index + 1) % 8;
    std::cout << std::endl;
    return (true);
}

void   PhoneBook::printBoxed(const std::string& str)
{
    int length;
    int padding;

    length = str.length();
    padding = 10 - length;
    if (padding < 0)
    {
        for (int i = 0; i < 9; i++)
            std::cout << str.at(i);
        std::cout << '.';
    }
    else
    {
        for (int i = 0; i < padding; i++)
            std::cout << ' ';
       for (int i = 0; i < length; i++)
            std::cout << str.at(i);
    }
}

bool   PhoneBook::searchContacts()
{
    std::string str;
    int         length;

    std::cout << std::endl;
    std::cout << "SEARCH INVOKED" << std::endl;
    length = 4 * 10 + 5;
    for (int i = 0 ; i < length ; i++)
        std::cout << "_";
    std::cout << std::endl;
    std::cout << "|";
    printBoxed("INDEX");
    std::cout << "|";
    printBoxed("FIRST NAME");
    std::cout << "|";
    printBoxed("LAST NAME");
    std::cout << "|";
    printBoxed("NICK NAME");
    std::cout << "|";
    std::cout << std::endl;
    for (int i = 0 ; i < m_currentlySaved; i++)
    {
        std::string num = std::to_string(i);
        std::cout << "|";
        printBoxed(num);
        std::cout << "|";
        printBoxed(contactArray[i].getfName());
        std::cout << "|";
        printBoxed(contactArray[i].getlName());
        std::cout << "|";
        printBoxed(contactArray[i].getnName());
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Type the index of the contact you want to further inspect:";
    std::getline(std::cin, str);
    try {
        length = std::stoi(str);
    }catch (std::exception& e)
    {
        return (false);
    }
    if (std::cin.good() == false || length < 0 || length >= m_currentlySaved)
        return (false);
    else
    {
        std::cout << std::endl;
        std::cout << "First name: " << contactArray[length].getfName() << std::endl <<  "Last name: " << contactArray[length].getlName() << std::endl;
        std::cout << "Nick name: " << contactArray[length].getnName() << std::endl <<  "Phone number: " << contactArray[length].getpNumber() << std::endl;
        std::cout << "Darkest secret: " << contactArray[length].getdSecret() << std::endl << std::endl;
    }
    return (true);
}