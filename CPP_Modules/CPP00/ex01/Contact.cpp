
#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
    m_firstName = "";
    m_lastName = "";
    m_nickName = "";
    m_phoneNumber = "";
    m_darkestSecret = "";
}

Contact::Contact(Contact& copy)
{
    m_firstName = copy.getfName();
    m_lastName= copy.getlName(); 
    m_nickName= copy.getnName();
    m_phoneNumber = copy.getpNumber();
    m_darkestSecret = copy.getdSecret();
 }

Contact::~Contact()
{
}

bool    Contact::setfName(std::string str)
{
    if (str.length() <= 0)
        return (false);
    for (size_t i = 0; i < str.length() ; i++)
    {
        if (std::isalpha(str.at(i)) == false)
            return (false);
    }
    for (size_t i = 0; i < str.length() ; i++)
    {
        if (i == 0)
            str.at(i) = static_cast<char>(std::toupper(str[i]));
        else
            str.at(i) = static_cast<char>(std::tolower(str[i]));
    }
    m_firstName = str;
    return (true);
}

bool    Contact::setlName(std::string str)
{
    if (str.length() <= 0)
        return (false);
    for (size_t i = 0; i < str.length() ; i++)
    {
        if (std::isalpha(str.at(i)) == false)
            return (false);
    }
    for (size_t i = 0; i < str.length() ; i++)
    {
        if (i == 0)
            str.at(i) = static_cast<char>(std::toupper(str[i]));
        else
            str.at(i) = static_cast<char>(std::tolower(str[i]));
    }
    m_lastName = str;
    return (true);
}

bool    Contact::setnName(std::string str)
{
    if (str.length() <= 0)
        return (false);
    // I will allow nicknames to be of any characters since they are 
    m_nickName = str;
    return (true);
}

bool    Contact::setpNumber(const std::string str)
{
    bool international;
    
    international = false;
    if (str.length() <= 0)
        return (false);
    if (str.at(0) != '+' && std::isdigit(str.at(0)) == false)
        return (false);
    if (str.at(0) == '+')
        international = true;
    if (international == false && str.length() != 10)
        return (false);
    if (international == true && str.length() != 13)
        return (false);
    for (size_t i = 0; i < str.length() ; i++)
    {
        if  (i == 0 && international == true)
        {
            continue ;
        }
        else if (std::isdigit(str.at(i)) == false)
            return (false);
    }
    m_phoneNumber = str;
    return (true);
}

bool    Contact::setdSecret(const std::string str)
{

    if (str.length() <= 0)
        return (false);
    // I will allow secrets to contain all characters too.
    m_darkestSecret = str;
    return (true);
}


const std::string& Contact::getfName() const
{
    return m_firstName;
}
const std::string& Contact::getlName() const
{
    return m_lastName;
}
const std::string& Contact::getnName() const
{
    return m_nickName;
}
const std::string& Contact::getpNumber() const
{
    return m_phoneNumber;
}
const std::string& Contact::getdSecret() const
{
    return m_darkestSecret;
}