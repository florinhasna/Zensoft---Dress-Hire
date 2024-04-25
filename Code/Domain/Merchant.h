#ifndef MERCHANT_H
#define MERCHANT_H

#include "Customer.h" 

class Merchant : public Person {
private:
    std::string PIN;  
    std::string staffID;  

public:
 
    Merchant(const std::string& name, const std::string& email, const std::string& address, const std::string& staffID, const std::string& PIN);

    std::string getPIN() const;
    void setPIN(const std::string& newPIN);

    std::string getStaffID() const;  
    void setStaffID(const std::string& newStaffID);  

    void issueProduct(Customer* customer, Product* product);
    void returnProduct(Customer* customer, Product* product);
    void calculateFine(Product* product);
};

#endif
