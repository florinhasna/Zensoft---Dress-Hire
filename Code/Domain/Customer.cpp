#include "Customer.h"

Customer::Customer() {
    // Constructor 
}

Customer::~Customer() {
    // Destructor implementation
    // If using raw pointers, need to deallocate memory to prevent memory leaks
    for (Product* product : productsLoaned) {
        delete product; // Delete the pointed-to Product
    }
    productsLoaned.clear();
}

int Customer::getCustomerReference() const {
    return 0; 
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
