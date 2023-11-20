#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
private:   
   std::string m_firstName;
   std::string m_lastName;
   std::string m_nickName;
   std::string m_phoneNumber;
   std::string m_darkestSecret;

public:
    Contact();
    Contact(Contact& copy);
    ~Contact();
    bool setfName(const std::string str);
    bool setlName(const std::string str);
    bool setnName(const std::string str);
    bool setpNumber(const std::string str);
    bool setdSecret(const std::string str);
    
    const std::string& getfName() const;
    const std::string& getlName() const;
    const std::string& getnName() const;
    const std::string& getpNumber() const;
    const std::string& getdSecret() const;
};

#endif