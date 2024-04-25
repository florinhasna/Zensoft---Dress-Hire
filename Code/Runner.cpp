#include "Data/DataReader.h"
#include "Application/Application.h"
#include "Utilities/Hash.h"
#include <iostream> 
#include "UserInterface/UserInterface.h"

int main() {
    DataReader dataReader("Products.csv", "Merchants.csv", "Customers.csv");
    UserInterface ui;
    Application application(ui, dataReader);

    // Initialize hash tables for Products, Merchants, and Customers
    LinearProbingHash<int, Product> productHashTable; // For products with int IDs
    LinearProbingHash<std::string, Merchant> merchantHashTable; // For merchants with string IDs
    LinearProbingHash<std::string, Customer> customerHashTable; // For customers with string IDs

    // Read and insert products
    auto products = dataReader.readProducts();
    for (const auto& product : products) {
        productHashTable.put(product.getProductID(), product);
    }

    // Read and insert merchants
    auto merchants = dataReader.readMerchants();
    for (const auto& merchant : merchants) {
        merchantHashTable.put(merchant.getStaffID(), merchant);
    }

    // Read and insert customers
    auto customers = dataReader.readCustomers();
    for (const auto& customer : customers) {
        customerHashTable.put(customer.getID(), customer);
    }

    // Display products 
    std::cout << "Products stored in the hash table:\n";
    for (const auto& product : products) {
        Product& storedProduct = productHashTable.get(product.getProductID());
        std::cout << "Product ID: " << storedProduct.getProductID()
                  << ", Gender: " << storedProduct.getGender()
                  << ", Collection: " << storedProduct.getCollection()
                  << ", Product Type: " << storedProduct.getProductType()
                  << ", Name: " << storedProduct.getProductName()
                  << ", Size: " << storedProduct.getProductSize()
                  << ", Colour: " << storedProduct.getProductColour()
                  << ", Daily Rental Price: $" << storedProduct.getDailyRentalPrice()
                  << ", Full Price: $" << storedProduct.getFullPrice()
                  << std::endl;
    }

    // Display merchants
    std::cout << "\nMerchants stored in the hash table:\n";
    for (const auto& merchant : merchants) {
        Merchant& storedMerchant = merchantHashTable.get(merchant.getStaffID());
        std::cout << "Merchant ID: " << storedMerchant.getStaffID()
                  << ", Name: " << storedMerchant.getName()
                  << ", Address: " << storedMerchant.getAddress()
                  << ", Email: " << storedMerchant.getEmail()
                  << ", PIN: " << storedMerchant.getPIN()
                  << std::endl;
    }

    // Display customers 
    std::cout << "\nCustomers stored in the hash table:\n";
    for (const auto& customer : customers) {
        Customer& storedCustomer = customerHashTable.get(customer.getID());
        std::cout << "Customer ID: " << storedCustomer.getID()
                  << ", Name: " << storedCustomer.getName()
                  << ", Address: " << storedCustomer.getAddress()
                  << ", Email: " << storedCustomer.getEmail()
                  << ", Gender: " << storedCustomer.getGender()
                  << ", Age: " << storedCustomer.getAge()
                  << ", Phone Number: " << storedCustomer.getPhoneNumber()
                  << std::endl;
    }

    // Start the application 
    application.start();

    return 0;
}
