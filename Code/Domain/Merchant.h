#ifndef MERCHANT_H
#define MERCHANT_H

#include "Person.h"
#include "Product.h"
#include "Customer.h" 

class Merchant : public Person {
private:
    std::string PIN;  // PIN is a string so it can handle alphanumeric PINs
    std::string staffID;  // Unique staff ID for the merchant which differs to the Customers ID

public:
    // Constructor updated with PIN as std::string
    Merchant(const std::string& name, const std::string& email, const std::string& address, const std::string& staffID, const std::string& PIN);

    std::string getPIN() const;
    void setPIN(const std::string& newPIN);

    std::string getStaffID() const;  // Getter for staffID
    void setStaffID(const std::string& newStaffID);  // Setter for staffID

    void issueProduct(Customer& customer, Product& product);
    void returnProduct(Customer& customer, Product& product);
    void calculateFine(Product& product);
};

#endif
