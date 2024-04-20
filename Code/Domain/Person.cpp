#include "Person.h"

Person::Person() : ID("") {}

Person::Person(const std::string& name, const std::string& email, const std::string& address, const std::string& ID)
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

std::string Person::getID() const {
    return ID;
}

void Person::setID(const std::string& newID) {
    ID = newID;
}
