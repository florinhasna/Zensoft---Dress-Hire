#include "Merchant.h"

Merchant::Merchant(const std::string& name, const std::string& email, const std::string& address, const std::string& staffID, const std::string& PIN)
    : Person(name, email, address, staffID), // Now its passing staffID as ID to Person
      PIN(PIN), 
      staffID(staffID) {}


std::string Merchant::getPIN() const {
    return PIN;
}

void Merchant::setPIN(const std::string& newPIN) {
    PIN = newPIN;
}

std::string Merchant::getStaffID() const {
    return staffID;
}

void Merchant::setStaffID(const std::string& newStaffID) {
    staffID = newStaffID;
}

void Merchant::issueProduct(Customer& customer, Product& product) {
    // Implementation for issuing a product to a customer
}

void Merchant::returnProduct(Customer& customer, Product& product) {
    // Implementation for returning a product from a customer
}

void Merchant::calculateFine(Product& product) {
    // Implementation for calculating fines
}
