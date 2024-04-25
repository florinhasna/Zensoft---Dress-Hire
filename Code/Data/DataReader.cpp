#include "DataReader.h"


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
    std::getline(file, line); 

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
    std::getline(file, line); 

    while (std::getline(file, line)) {
        std::istringstream s(line);
        std::string merchantID, name, address, email, PIN;

        std::getline(s, merchantID, ','); 
        std::getline(s, name, ',');
        std::getline(s, address, ',');
        std::getline(s, email, ',');
        std::getline(s, PIN, ',');

        merchants.push_back(Merchant(name, email, address, merchantID, PIN));
    }

    file.close();
    return merchants;
}

void DataReader::AppendMerchantToCSV(const std::string& filename, const Merchant& merchant) {
    std::ofstream file;
    file.open(filename, std::ios_base::app);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing.");
    }

    if (file.is_open()) {
        file << merchant.getStaffID() << ","
             << merchant.getName() << ","
             << merchant.getAddress() << ","
             << merchant.getEmail() << ","
             << merchant.getPIN() << "\n";
    }
    
    file.close();
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
        std::string ID, name, address, email, gender, age, phoneNumber;

        std::getline(s, ID, ',');
        std::getline(s, name, ',');
        std::getline(s, address, ',');
        std::getline(s, email, ',');
        std::getline(s, gender, ',');
        std::getline(s, age, ',');
        std::getline(s, phoneNumber, ',');

        
        customers.push_back(Customer(name, address, ID, email, gender, age, phoneNumber));
    }

    file.close();
    return customers;
}



void DataReader::AppendCustomerToCSV(const std::string& filename, const Customer& customer) {
    std::ofstream file;
    file.open(filename, std::ios_base::app);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing.");
    }

    file << customer.getID() << ","        
         << customer.getName() << ","
         << customer.getAddress() << ","
         << customer.getEmail() << ","
         << customer.getGender() << ","
         << customer.getAge() << ","
         << customer.getPhoneNumber() << "\n";
    
    file.close();
}
