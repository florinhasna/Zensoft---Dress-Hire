#ifndef MERCHANT_H
#define MERCHANT_H

#include "Person.h" 
#include "Customer.h" 
#include "Product.h"

class Merchant : public Person {
private:
    int PIN;

public:
    Merchant(const std::string& name, const std::string& email, const std::string& address, int staffID, int PIN);

    int getPIN() const;
    void setPIN(int newPIN);

    void issueProduct(Customer& customer, Product& product);
    void returnProduct(Customer& customer, Product& product);
    void calculateFine(Product& product);
};

#endif 
