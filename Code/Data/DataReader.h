#ifndef DATA_READER_H
#define DATA_READER_H

#include <vector>
#include <string>
#include "../Domain/Merchant.h"


class DataReader {
public:
    DataReader();
    explicit DataReader(const std::string& filePath);
    std::vector<Product> readProducts();
    std::vector<Merchant> readMerchants();
    std::vector<Customer> readCustomers(); 

private:
    std::string filePath;
};

#endif 
