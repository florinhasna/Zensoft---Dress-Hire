#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "../UserInterface/UserInterface.h"
#include "../Data/DataReader.h"
//#include "../Domain/Person.h"
//#include "../Domain/Merchant.h"
//#include "../Domain/Customer.h"
//#include "../Domain/Product.h"

class Application {
private:
    UserInterface UI;
    DataReader data;

    void loopLoginMenu();
    void login();
    void addMerchant();
    void loopMainMenu();
    void loopStockManagement();
    void addProduct();
    void removeProduct();
    void updateProductPrice();
    void issueProduct();
    void returnProduct();
    void seeBorrows();
    void seeProductStatus();
    void addCustomer();
public:
    Application(UserInterface ui, DataReader d);
    ~Application();
    UserInterface getUI();
    DataReader getData();

    void start();
};

#endif