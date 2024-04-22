#ifndef DATA_READER_H
#define DATA_READER_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include "../Domain/Merchant.h"


class DataReader {
public:
    DataReader();
    explicit DataReader(const std::string& filePathProducts, const std::string& filePathMerchants, const std::string& filePathCustomers);
    std::vector<Product> readProducts();
    std::vector<Merchant> readMerchants();
    std::vector<Customer> readCustomers(); 
   static void AppendMerchantToCSV(const std::string& filename, const Merchant& merchant);
   static void AppendCustomerToCSV(const std::string& filename, const Customer& customer);


private:
    std::string filePathProducts;
    std::string filePathMerchants;
    std::string filePathCustomers;
};

#endif 
