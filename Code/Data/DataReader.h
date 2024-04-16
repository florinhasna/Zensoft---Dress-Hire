#ifndef DATA_READER_H
#define DATA_READER_H
#include "../Utilities/Utilities.h"
#include <vector>
#include <string>

// Define a structure to hold product information
struct Product {
    int productID;
    char gender;
    std::string collection, productType, size, colour;
    double dailyRentalPrice, totalPrice;
};

// Declaration of the DataReader class
class DataReader {
public:
    explicit DataReader(const std::string& filePath);
    std::vector<Product> readProducts();

private:
    std::string filePath;
};

#endif // DATA_READER_H
