#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Product.h"
#include <vector>


class Customer : public Person {
private:
    std::vector<Product*> productsLoaned;

public:
    Customer(const std::string& name, const std::string& email, const std::string& address, const std::string& ID);
    ~Customer();

    std::vector<Product*> getProductsLoaned() const;
    void loanProduct(Product* aProduct);
    void returnProduct(Product* aProduct);
};

#endif
