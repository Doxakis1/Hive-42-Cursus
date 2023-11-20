
#include "Contact.hpp"

Contact::Contact()
{
    this->m_firstName = "";
    this->m_lastName = "";
    this->m_nickName = "";
    this->m_phoneNumber = "";
    this->m_darkestSecret = "";
}

Contact::Contact(Contact& copy)
{
    this->m_firstName = copy.getfName();
    this->m_lastName= copy.getlName(); 
    this->m_nickName= copy.getnName();
    this->m_phoneNumber = copy.getpNumber();
    this->m_darkestSecret = copy.getdSecret();
 }

Contact::~Contact()
{
}

bool    Contact::setfName(std::string str)
{
    if (str.length() <= 0)
        return (false);
    for (size_t i = 0; str.at(i) != '\0'; i++)
    {
        if (std::isalpha(str.at(i)) == false)
            return (false);
    }
    for (size_t i = 0; str.at(i) != '\0'; i++)
    {
        if (i == 0)
            str.at(i) = static_cast<char>(std::toupper(str[i]));
        else
            str.at(i) = static_cast<char>(std::tolower(str[i]));
    }
    this->m_firstName = str;
    return (true);
}

bool    Contact::setlName(std::string str)
{
    if (str.length() <= 0)
        return (false);
    for (size_t i = 0; str.at(i) != '\0'; i++)
    {
        if (std::isalpha(str.at(i)) == false)
            return (false);
    }
    for (size_t i = 0; str.at(i) != '\0'; i++)
    {
        if (i == 0)
            str.at(i) = static_cast<char>(std::toupper(str[i]));
        else
            str.at(i) = static_cast<char>(std::tolower(str[i]));
    }
    this->m_lastName = str;
    return (true);
}

bool    Contact::setnName(std::string str)
{
    if (str.length() <= 0)
        return (false);
    // I will allow nicknames to be of any characters since they are 
    this->m_nickName = str;
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
    return (true);
}

bool    Contact::setdSecret(const std::string str)
{

    if (str.length() <= 0)
        return (false);
    // I will allow secrets to contain all characters too.
    this->m_darkestSecret = str;
    return (true);
}


const std::string& Contact::getfName() const
{
    return this->m_firstName;
}
const std::string& Contact::getlName() const
{
    return this->m_lastName;
}
const std::string& Contact::getnName() const
{
    return this->m_nickName;
}
const std::string& Contact::getpNumber() const
{
    return this->m_phoneNumber;
}
const std::string& Contact::getdSecret() const
{
    return this->m_darkestSecret;
}