#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Product.h" 

class Customer : public Person {
private:
    std::vector<Product*> productsLoaned;

public:
    Customer();
    ~Customer(); // Destructor for managing dynamic memory, if necessary

    int getCustomerReference() const;
    std::vector<Product*> getProductsLoaned() const;
    void loanProduct(Product* aProduct);
    void returnProduct(Product* aProduct);
};

#endif 
