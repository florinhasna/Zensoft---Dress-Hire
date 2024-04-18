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

// // Main function for testing purposes
// int main() {
//     DataReader reader("C:\\Users\\Khalil\\Desktop\\2550 CW Reading from a data file\\Products.csv");
//     auto products = reader.readProducts();

//     for (const auto& product : products) {
//         std::cout << "Product ID: " << product.productID
//                   << ", Gender: " << product.gender
//                   << ", Collection: " << product.collection
//                   << ", Product Type: " << product.productType
//                   << ", Size: " << product.size
//                   << ", Colour: " << product.colour
//                   << ", Daily Rental Price: " << product.dailyRentalPrice
//                   << ", Total Price: " << product.totalPrice << std::endl;
//     }

//     return 0;
// }
