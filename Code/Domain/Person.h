#ifndef PERSON_H
#define PERSON_H

#include "../Utilities/Utilities.h"

class Person {
private:
    std::string name;
    std::string email;
    std::string address;  
    int ID;

public:
    Person();
    Person(const std::string& name, const std::string& email, const std::string& address, int ID);

    std::string getName() const;
    void setName(const std::string& newName);

    std::string getEmail() const;
    void setEmail(const std::string& newEmail);

    std::string getAddress() const;
    void setAddress(const std::string& newAddress);

    int getID() const;
    void setID(int newID);
};

#endif
