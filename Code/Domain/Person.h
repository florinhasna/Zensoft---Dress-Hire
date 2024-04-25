#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    std::string email;
    std::string address;
    std::string ID;

public:
    Person();  
    Person(const std::string& name, const std::string& email, const std::string& address, const std::string& ID);  
    virtual ~Person() = default;
    std::string getName() const;
    void setName(const std::string& newName);
    std::string getEmail() const;
    void setEmail(const std::string& newEmail);
    std::string getAddress() const;
    void setAddress(const std::string& newAddress);
    std::string getID() const;
    void setID(const std::string& newID);
};

#endif 
