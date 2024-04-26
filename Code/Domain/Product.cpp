#include "Product.h"

// Constructor 
Product::Product(int productID, const std::string& gender, const std::string& collection,
                 const std::string& productType, const std::string& productName,
                 const std::string& size, const std::string& colour,
                 double dailyRentalPrice, double fullPrice)
    : productID(productID), gender(gender), collection(collection),
      productType(productType), productName(productName), size(size),
      colour(colour), dailyRentalPrice(dailyRentalPrice), fullPrice(fullPrice),
      isAvailable(true), borrowedAndDue() {}

//getters
int Product::getProductID() const {
    return productID;
}

std::string Product::getGender() const {
    return gender;
}

std::string Product::getCollection() const {
    return collection;
}

std::string Product::getProductType() const {
    return productType;
}

std::string Product::getProductName() const {
    return productName;
}

std::string Product::getProductSize() const {
    return size;
}

std::string Product::getProductColour() const {
    return colour;
}

double Product::getDailyRentalPrice() const {
    return dailyRentalPrice;
}

double Product::getFullPrice() const {
    return fullPrice;
}

bool Product::getIsAvailable() const {
    return isAvailable;
}

Date Product::getBorrowedAndDue() const {
    return borrowedAndDue;
}

std::string Product::getBorrowedBy() const {
    return borrowedBy;
}

//seters
void Product::setProductID(int newProductID) {
    productID = newProductID;
}

void Product::setGender(const std::string& newGender) {
    gender = newGender;
}

void Product::setCollection(const std::string& newCollection) {
    collection = newCollection;
}

void Product::setProductType(const std::string& newProductType) {
    productType = newProductType;
}

void Product::setProductName(const std::string& newProductName) {
    productName = newProductName;
}

void Product::setProductSize(const std::string& newSize) {
    size = newSize;
}

void Product::setProductColour(const std::string& newColour) {
    colour = newColour;
}

void Product::setDailyRentalPrice(double newDailyRentalPrice) {
    dailyRentalPrice = newDailyRentalPrice;
}

void Product::setFullPrice(double newFullPrice) {
    fullPrice = newFullPrice;
}

void Product::setIsAvailable(bool newIsAvailable) {
    isAvailable = newIsAvailable;
}

void Product::setBorrowedAndDue(const Date& newDateOfBorrowal) {
    borrowedAndDue = newDateOfBorrowal;
}

void Product::setBorrowedBy(const std::string& ID) {
    borrowedBy = ID;
}


//methods
double Product::calculateTotalForBorrowal() const {
    int daysBorrowed = Date::daysBetween(borrowedAndDue.getDateOfBorrowal(), Date::getCurrentDate());
    return daysBorrowed * dailyRentalPrice;
}


bool Product::isLate() const {
    return Date::isAfter(Date::getCurrentDate(), borrowedAndDue.getDueDate());
}

std::string Product::getDateOfBorrowal() const {
    return borrowedAndDue.getDateOfBorrowal();
}

std::string Product::getDueDate() const {
    return borrowedAndDue.getDueDate();
}

void Product::setDateOfBorrowal(const std::string& date) {
    borrowedAndDue.setDateOfBorrowal(date);
    setIsAvailable(false);  
}

void Product::setDueDate(int rentalDays) {
    borrowedAndDue.setDueDate(rentalDays);
}

std::string Product::toString() const {
    std::ostringstream stream;
    stream << "Product ID: " << getProductID() << "\n"
           << "Gender: " << getGender() << "\n"
           << "Collection: " << getCollection() << "\n"
           << "Product Type: " << getProductType() << "\n"
           << "Name: " << getProductName() << "\n"
           << "Size: " << getProductSize() << "\n"
           << "Colour: " << getProductColour() << "\n"
           << "Daily Rental Price: " << getDailyRentalPrice() << "\n"
           << "Full Price: " << getFullPrice() << "\n"
           << "Date of Borrowal: " << getDateOfBorrowal() << "\n"
           << "Due Date: " << getDueDate();
    return stream.str();
}
