#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "../UserInterface/UserInterface.h"
#include "../Data/DataReader.h"
#include "../UserInterface/UserInterface.h"
#include <unordered_map>

class Application {
private:
    UserInterface UI;
    DataReader data;
    Merchant* loggedIn = nullptr;
    // Initialize hash tables for Products, Merchants, and Customers
    LinearProbingHash<int, Product> productHashTable; // For products with int IDs
    LinearProbingHash<std::string, Merchant> merchantHashTable; // For merchants with string IDs
    LinearProbingHash<std::string, Customer> customerHashTable; // For customers with string IDs

    void loopLoginMenu();
    void login();
    void addMerchant();
    void loopMainMenu();
    void issueProduct();
    void returnProduct();
    void seeBorrows();
    void seeProductStatus();
    void addCustomer();
    Customer* getACustomer();
    Product* getAProduct();
public:
    Application(UserInterface ui, DataReader d);
    ~Application();
    UserInterface getUI();
    DataReader getData();

    void start();
};

#endif
