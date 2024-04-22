#include "DataReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

DataReader::DataReader(const std::string& filePathProducts, const std::string& filePathMerchants, const std::string& filePathCustomers) 
: filePathProducts(filePathProducts), filePathMerchants(filePathMerchants), filePathCustomers(filePathCustomers) {}
DataReader::DataReader(){}

std::vector<Product> DataReader::readProducts() {
    std::ifstream file(filePathProducts);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePathProducts << std::endl;
        return {};
    }

    std::vector<Product> products;
    std::string line;
    std::getline(file, line); // Skip the header line

    while (std::getline(file, line)) {
        std::istringstream s(line);
        int productID;
        std::string gender, collection, productType, productName, size, colour;
        double dailyRentalPrice, fullPrice;

        std::getline(s, line, ',');
        productID = std::stoi(line);

        std::getline(s, gender, ',');
        std::getline(s, collection, ',');
        std::getline(s, productType, ',');
        std::getline(s, productName, ',');
        std::getline(s, size, ',');
        std::getline(s, colour, ',');
        
        std::getline(s, line, ',');
        dailyRentalPrice = std::stod(line);
        
        std::getline(s, line, ',');
        fullPrice = std::stod(line);

        // Use the constructor to create a Product instance
        Product product(productID, gender, collection, productType, productName, size, colour, dailyRentalPrice, fullPrice);
        products.push_back(product);
    }

    file.close();
    return products;
}



std::vector<Merchant> DataReader::readMerchants() {
    std::ifstream file(filePathMerchants);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePathMerchants << std::endl;
        return {};
    }

    std::vector<Merchant> merchants;
    std::string line;
    std::getline(file, line); // Skip the header line

    while (std::getline(file, line)) {
        std::istringstream s(line);
        std::string merchantID, name, address, email, PIN;

        std::getline(s, merchantID, ','); // First column is merchantID
        std::getline(s, name, ',');
        std::getline(s, address, ',');
        std::getline(s, email, ',');
        std::getline(s, PIN, ','); // Last column is PIN

        merchants.push_back(Merchant(name, email, address, merchantID, PIN));
    }

    file.close();
    return merchants;
}

   std::vector<Customer> DataReader::readCustomers() {
    std::ifstream file(filePathCustomers);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePathCustomers << std::endl;
        return {};
    }

    std::vector<Customer> customers;
    std::string line;
    std::getline(file, line); 

    while (std::getline(file, line)) {
        std::istringstream s(line);
        std::string ID, name, email, address;

        std::getline(s, ID, ',');  
        std::getline(s, name, ',');
        std::getline(s, email, ',');
        std::getline(s, address, ',');

        // Create a Customer object with parsed data
        customers.push_back(Customer(name, email, address, ID));
    }

    file.close();
    return customers;
}