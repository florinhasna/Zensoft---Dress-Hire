#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Product.h"
#include <vector>


class Customer : public Person {
private:
    std::string email;
    std::string gender;
    std::string age; 
    std::string phoneNumber;
    std::vector<Product*> productsLoaned;

public:
    // Customer(const std::string& name, const std::string& email, const std::string& address, const std::string& ID);
    // ~Customer();
  Customer(const std::string& name, const std::string& address, const std::string& ID, const std::string& email,
             const std::string& gender, const std::string& age, const std::string& phoneNumber);
    ~Customer();

    std::string getGender() const { return gender; }
    std::string getAge() const { return age; }
    std::string getPhoneNumber() const { return phoneNumber; }

    std::vector<Product*> getProductsLoaned() const;
    void loanProduct(Product* aProduct);
    void returnProduct(Product* aProduct);
};

#endif
