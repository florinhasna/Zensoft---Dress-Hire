#include "Customer.h"
 
Customer::Customer(const std::string& name, const std::string& address, const std::string& ID, const std::string& email,
                   const std::string& gender, const std::string& age, const std::string& phoneNumber)
    :  Person(name, email, address, ID), gender(gender), age(age), phoneNumber(phoneNumber) {}


Customer::~Customer() {
    for (Product* product : productsLoaned) {
        delete product;
    }
    productsLoaned.clear();
}

std::vector<Product*> Customer::getProductsLoaned() const {
    return productsLoaned;
}

void Customer::loanProduct(Product* aProduct) {
    productsLoaned.push_back(aProduct);
}

void Customer::returnProduct(Product* aProduct) {
    auto it = std::find(productsLoaned.begin(), productsLoaned.end(), aProduct);
    if (it != productsLoaned.end()) {
        productsLoaned.erase(it);
    }
}

std::string Customer::toString() {
    std::string aString = "";
    aString += "\n\tCustomer reference number: " + this->getID();
    aString += "\n\tCustomer name: " + this->getName();
    aString += "\n\tCustomer address: " + this->getAddress();
    aString += "\n\tCustomer email: " + this->getEmail();
    aString += "\n\tCustomer phone no.: " + this->getPhoneNumber();
    return aString;
}
