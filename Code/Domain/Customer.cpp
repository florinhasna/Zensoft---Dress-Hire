#include "Customer.h"
 

// Customer::Customer(const std::string& name, const std::string& email, const std::string& address, const std::string& ID)
//     : Person(name, email, address, ID) {}

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
    // Removes the product from the customer's list of loaned products
    auto it = std::find(productsLoaned.begin(), productsLoaned.end(), aProduct);
    if (it != productsLoaned.end()) {
        productsLoaned.erase(it);
    }
}
