#include "Merchant.h"

Merchant::Merchant(const std::string& name, const std::string& email, const std::string& address, int staffID, int PIN)
    : Person(name, email, address, staffID), PIN(PIN) {}

int Merchant::getPIN() const {
    return PIN;
}

void Merchant::setPIN(int newPIN) {
    PIN = newPIN;
}

void Merchant::issueProduct(Customer& customer, Product& product) {
}

void Merchant::returnProduct(Customer& customer, Product& product) {
}

void Merchant::calculateFine(Product& product) {
}
