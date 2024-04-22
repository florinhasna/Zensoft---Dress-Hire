#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "../UserInterface/UserInterface.h"
#include "../Data/DataReader.h"
#include <unordered_map>

class Application {
private:
    UserInterface UI;
    DataReader data;

    void loopLoginMenu();
    void login();
    void addMerchant();
    void loopMainMenu();
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
