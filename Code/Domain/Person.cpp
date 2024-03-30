#include "Person.h"

Person::Person() : ID(0) {} // initializing the ID field to 0 in the default constructor of the Person class

Person::Person(const std::string& name, const std::string& email, const std::string& address, int ID)
    : name(name), email(email), address(address), ID(ID) {}

std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string& newName) {
    name = newName;
}

std::string Person::getEmail() const {
    return email;
}

void Person::setEmail(const std::string& newEmail) {
    email = newEmail;
}

std::string Person::getAddress() const {
    return address;
}

void Person::setAddress(const std::string& newAddress) {
    address = newAddress;
}

int Person::getID() const {
    return ID;
}

void Person::setID(int newID) {
    ID = newID;
}
