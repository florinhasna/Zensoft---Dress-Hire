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

    // instructions messages, printed first when a menu option
    // is chosen
    void issueProductInstruction();
    void returnProductInstruction();
    void seeBorrowsInstruction();
    void productStatusInstruction();
    void addCustomerInstruction();

    void printCustomerData(std::string data);
    int getNumberOfDays();
    void printProductConfirmation(std::string aProduct);
    void printTotalPay(double price);

    void noProductsLoaned(std::string customer);
    std::string isReturningMore();
    void noMoreProducts(std::string customer);

    static std::string LoginSuccesfull();
    static std::string LoginUnsuccesfull();
    static std::string MaximumLoginAttemps();
    static std::string RegistrationSuccesfull();
    static std::string CustomerRegistrationSuccesfull();

    // methods used to read inputs from user and returns
    // the relevant data
    static std::string getMerchantIDInput();
    static std::string getNameInput();
    static std::string getEmailInput();
    static std::string getAddressInput();
    static std::string getIDInput();
    static std::string getPinInput();
    static std::string getGenderInput();
    static std::string getAgeInput();
    static std::string getphoneNumberInput();
    static int getProductIDInput();
    static int getNumberOfItems();

    // message when the user chooses to abort an action
    void abortMessage();
    void exitProgram();
    void logout();

    // error messages, printed mainly when wrong input is given
    void invalidMenuChoiceMessage();
    void errorMessage();
    static void invalidName(const std::string& name);
    static void invalidEmail(const std::string& email);
    static void invalidAddress(const std::string& address);
    static void invalidID(const std::string& ID);
    static void invalidPin(const std::string& PIN);
    static void invalidgender(const std::string& gender);
    static void invalidAge();
    static void invalidphoneNumber();
    static void productUnavailable(std::string product);
};

#endif