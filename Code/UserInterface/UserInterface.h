#ifndef _USERINTERFACE_H_
#define _USERINTERFACE_H_
#include "../Utilities/Utilities.h"
#include "../Utilities/Utilities.cpp"

class UserInterface{
public:
    UserInterface(); // constructor
    ~UserInterface(); // destructor

    // menus
    void loadLogin();
    void loadMenu();

    // instructions messages, printed first when a menu option
    // is chosen
    void issueProductInstruction();
    void returnProductInstruction();
    void seeBorrowsInstruction();
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

    // message when the user chooses to abort an action
    void abortMessage();
    void exitProgram();
    void logout();

    // error messages, printed mainly when wrong input is given
    void invalidMenuChoiceMessage();
    void errorMessage();
    void invalidName(std::string name);
    void invalidEmail(std::string email);
    void invalidAddress(std::string address);
    void invalidID(int ID);
    void invalidPin(int PIN);
    void invalidPrice(double price);
};

#endif