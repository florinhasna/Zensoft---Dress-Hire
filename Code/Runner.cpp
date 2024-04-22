#include "UserInterface/UserInterface.h"
#include "Data/DataReader.h"
#include "Application/Application.h"

int main() {
    UserInterface ui;
    DataReader data("Products.csv", "Merchants.csv", "Customers.csv");
    Application application(ui, data);
    auto products = data.readProducts();
    auto merchants = data.readMerchants();
    auto customers = data.readCustomers();

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

    application.start();
    return 0;
}