#ifndef PRODUCT_H
#define PRODUCT_H

#include "../Utilities/Utilities.h"

class Product {
private:
    int productID;
    std::string gender;
    std::string collection;
    std::string productType;
    std::string productName;
    std::string size;
    std::string colour;
    double dailyRentalPrice;
    double fullPrice;
    bool isAvailable;
    Date borrowedAndDue;
    std::string borrowedBy;
    std::string getDateOfBorrowal() const;

public:
    Product(int productID, const std::string& gender, const std::string& collection,
            const std::string& productType, const std::string& productName,
            const std::string& size, const std::string& colour,
            double dailyRentalPrice, double fullPrice);

    // Getters
    int getProductID() const;
    std::string getGender() const;
    std::string getCollection() const;
    std::string getProductType() const;
    std::string getProductName() const;
    std::string getProductSize() const;
    std::string getProductColour() const;
    double getDailyRentalPrice() const;
    double getFullPrice() const;
    bool getIsAvailable() const;
    Date getBorrowedAndDue() const;
    std::string getBorrowedBy() const;
    std::string getDueDate() const;

    // Setters
    void setProductID(int newProductID);
    void setGender(const std::string& newGender);
    void setCollection(const std::string& newCollection);
    void setProductType(const std::string& newProductType);
    void setProductName(const std::string& newProductName);
    void setProductSize(const std::string& newSize);
    void setProductColour(const std::string& newColour);
    void setDailyRentalPrice(double newDailyRentalPrice);
    void setFullPrice(double newFullPrice);
    void setIsAvailable(bool newIsAvailable);
    void setBorrowedAndDue(const Date& newDateOfBorrowal);
    void setBorrowedBy(const std::string& ID);
    void setDateOfBorrowal(const std::string& date);
    void setDueDate(int rentalDays);

    // methods
    double calculateTotalForBorrowal(int daysBorrowed) const;
    bool isLate() const;
    std::string toString() const;
};

#endif 
