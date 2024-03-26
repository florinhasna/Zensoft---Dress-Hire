#ifndef _USERINTERFACE_H_
#define _USERINTERFACE_H_
#include "../Utilities/Utilities.h"

class UserInterface{
public:
    UserInterface(); // constructor
    ~UserInterface(); // destructor

    // menus
    void loadLogin();
    void loadMenu();
    void loadStockManagementMenu();

    // instructions messages, printed first when a menu option
    // is chosen
    void printAddProductInstruction();
    void printRemoveProductInstruction();
    void printUpdatePriceInstruction();
    void issueProductInstruction();
    void returnProductInstruction();
    void seeBorrowalsInstruction();
    void productStatusInstruction();
    void addCustomerInstruction();

    // methods used to read inputs from user and returns
    // the relevant data
    std::string getNameInput();
    std::string getEmailInput();
    std::string getAddressInput();
    int getIDInput();
    int getPinInput();
    double getPriceInput();
    std::string getProductTypeInput();
    std::string getProductNameInput();
    std::string getCollectionInput();
    std::string getGenderInput();
    std::string getSizeInput();
    std::string getColourInput();
    double getDailyRentalPriceInput();
    double getFullPriceInput();

    // message when the user chooses to abort an action
    void abortMessage();

    // error messages, printed mainly when wrong input is given
    void invalidMenuChoiceMessage();
    void errorMessage();
    void invalidIDMessage();
    void invalidInput();
};

#endif