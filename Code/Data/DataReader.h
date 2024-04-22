#ifndef DATA_READER_H
#define DATA_READER_H

#include <vector>
#include <string>
#include "../Domain/Merchant.h"


class DataReader {
public:
    DataReader();
    explicit DataReader(const std::string& filePathProducts, const std::string& filePathMerchants, const std::string& filePathCustomers);
    std::vector<Product> readProducts();
    std::vector<Merchant> readMerchants();
    std::vector<Customer> readCustomers(); 

private:
    std::string filePathProducts;
    std::string filePathMerchants;
    std::string filePathCustomers;
};

#endif 
