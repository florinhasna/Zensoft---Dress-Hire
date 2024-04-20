#include "DataReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

DataReader::DataReader(const std::string& filePath) : filePath(filePath) {}


std::vector<Product> DataReader::readProducts() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
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
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
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
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
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


// Update the main function to demonstate reading from products, merchants, and customers
int main() {
    DataReader productReader("C:\\Users\\Khalil\\Desktop\\2550 CW Reading from a data file\\CSV\\Products.csv");
    auto products = productReader.readProducts();
    DataReader merchantReader("C:\\Users\\Khalil\\Desktop\\2550 CW Reading from a data file\\CSV\\Merchants.csv");
    auto merchants = merchantReader.readMerchants();
    DataReader customerReader("C:\\Users\\Khalil\\Desktop\\2550 CW Reading from a data file\\CSV\\Customers.csv");
    auto customers = customerReader.readCustomers();

    for (const auto& product : products) {
    std::cout << "Product ID: " << product.getProductID()
              << ", Gender: " << product.getGender()
              << ", Collection: " << product.getCollection()
              << ", Product Type: " << product.getProductType()
              << ", Name: " << product.getProductName()  
              << ", Size: " << product.getProductSize()
              << ", Colour: " << product.getProductColour()
              << ", Daily Rental Price: $" << product.getDailyRentalPrice()
              << ", Full Price: $" << product.getFullPrice()
              << std::endl;
}


    for (const auto& merchant : merchants) {
    std::cout << "Merchant ID: " << merchant.getStaffID()  // Using getStaffID() to fetch merchant ID
              << ", Name: " << merchant.getName()
              << ", Address: " << merchant.getAddress()
              << ", Email: " << merchant.getEmail()
              << ", PIN: " << merchant.getPIN()
              << std::endl;
}




    for (const auto& customer : customers) {
        std::cout << "Customer ID: " << customer.getID()  
                  << ", Name: " << customer.getName()    
                  << ", Address: " << customer.getAddress() 
                  << ", Email: " << customer.getEmail()  
                  << std::endl;
    }

    return 0;
}
