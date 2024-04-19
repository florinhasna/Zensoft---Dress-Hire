#include "DataReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

DataReader::DataReader(){}
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
        Product product;
        std::string field;

        std::getline(s, field, ',');
        product.productID = std::stoi(field);

        std::getline(s, field, ',');
        product.gender = field[0];

        std::getline(s, field, ',');
        product.collection = field;

        std::getline(s, field, ',');
        product.productType = field;

        std::getline(s, field, ',');
        product.size = field;

        std::getline(s, field, ',');
        product.colour = field;

        std::getline(s, field, ',');
        product.dailyRentalPrice = std::stod(field);

        std::getline(s, field, ',');
        product.totalPrice = std::stod(field);

        products.push_back(product);
    }

    file.close();
    return products;
}   
