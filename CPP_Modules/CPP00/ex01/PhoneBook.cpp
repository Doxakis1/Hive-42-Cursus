#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->m_input = PhoneBook::CONTINUE;
    this->m_index = 0;
}

PhoneBook::PhoneBook(PhoneBook& copy)
{
    (void)copy;
}

void PhoneBook::update()
{   
    bool    checker;

    checker = true;
    switch (this->m_input)
    {
        case PhoneBook::ADD:
            checker = this->addContact();
            if (!checker)
                std::cerr << "Failed to add new contact!" << std::endl;
            break ;
        case PhoneBook::SEARCH:
            checker = this->searchContacts();
            if (!checker)
                std::cerr << "Failed to search contacts!" << std::endl;
            break ;
        default:
            break;
    }
    if (!checker && std::cin.eof() == false)
        this->m_input = PhoneBook::ERROR;
    else
        this->m_input = PhoneBook::CONTINUE;
    return ;
}

short   PhoneBook::isActive()
{
    if (this->m_input == PhoneBook::ERROR || this->m_input == PhoneBook::EXIT)
    {
        return (0);
    }
    return (1);
}

void   PhoneBook::getInput()
{
    std::string input;
    if (this->m_input == PhoneBook::ERROR)
        return ;
    std::cout << "Enter your command: ( ADD | SEARCH | EXIT ):";
    std::cin >> input;
    std::cout << std::endl;
    if (std::cin.good() == false)
        this->m_input = PhoneBook::ERROR;
    else if (input == "ADD")
        this->m_input = PhoneBook::ADD;
    else if (input == "SEARCH")
        this->m_input = PhoneBook::SEARCH;
    else if (input == "EXIT")
        this->m_input = PhoneBook::EXIT;
    else 
        this->m_input  = PhoneBook::CONTINUE;
    return ;
}

PhoneBook::~PhoneBook()
{
}

bool   PhoneBook::addContact()
{
    std::string input;

    std::cout << "Enter first name:";
    std::cin >> input;
    std::cout << std::endl;
    if (std::cin.good() == false)
        return (false);
    if (this->contactArray[8].setfName(input) == false)
        return (false);
    std::cout << "Enter last name:";
    std::cin >> input;
    std::cout << std::endl;
    if (std::cin.good() == false)
        return (false);
    if (this->contactArray[8].setlName(input) == false)
        return (false);
    std::cout << "Enter nickname:";
    std::cin >> input;
    std::cout << std::endl;
    if (std::cin.good() == false)
        return (false);
     if (this->contactArray[8].setnName(input) == false)
        return (false);
    std::cout << "Enter phone number:";
    std::cin >> input;
    std::cout << std::endl;
    if (std::cin.good() == false)
        return (false);
    if (this->contactArray[8].setpNumber(input) == false)
        return (false);
    std::cout << "Enter deepest secret name:";
    std::cin >> input;
    std::cout << std::endl;
    if (std::cin.good() == false)
        return (false);
    if (this->contactArray[8].setdSecret(input) == false)
        return (false);
    this->contactArray[this->m_index] = this->contactArray[8];
    if (this->m_currentlySaved < 8)
        this->m_currentlySaved++;
    this->m_index = (this->m_index + 1) % 8;
    return (true);
}

void   PhoneBook::printBoxed(const std::string& str)
{
    int length;
    int padding;

    length = str.length();
    padding = 10 - length;
    if (padding <= 0)
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

    std::cout << "SEARCH INVOKED" << std::endl;
    length = 4 * 10 + 5;
    for (int i = 0 ; i < length ; i++)
        std::cout << "_";
    std::cout << "|";
    this->printBoxed("INDEX");
    std::cout << "|";
    this->printBoxed("FIRST NAME");
    std::cout << "|";
    this->printBoxed("LAST NAME");
    std::cout << "|";
    this->printBoxed("NICK NAME");
    std::cout << "|";
    std::cout << std::endl;
    for (int i = 0 ; i < this->m_currentlySaved; i++)
    {
        std::string num = std::to_string(i);
        std::cout << "|";
        this->printBoxed(num);
        std::cout << "|";
        this->printBoxed(this->contactArray[i].getfName());
        std::cout << "|";
        this->printBoxed(this->contactArray[i].getlName());
        std::cout << "|";
        this->printBoxed(this->contactArray[i].getnName());
        std::cout << "|" << std::endl;
    }
    std::cout << "Type the index of the contact you want to inspect:" << std::endl;
    std::cin >> length;
    if (std::cin.good() || length < 0 || length >= this->m_currentlySaved)
        return (false);
    else
    {
        std::cout << "First name: " << this->contactArray[length].getfName() << std::endl <<  "Last name: " << this->contactArray[length].getlName() << std::endl;
        std::cout << "Nick name: " << this->contactArray[length].getnName() << std::endl <<  "Phone number: " << this->contactArray[length].getpNumber() << std::endl;
        std::cout << "Darkest secret: " << this->contactArray[length].getdSecret() << std::endl;
    }
    return (true);
}