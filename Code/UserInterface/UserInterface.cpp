#include "UserInterface.h"

UserInterface::UserInterface() {} // constructor
UserInterface::~UserInterface() {}

void UserInterface::loadLogin()
{
    std::cout << "\nPlease choose an option from the following list:\n";
    std::cout << "1. Merchant login ..............\n";
    std::cout << "2. Create merchant account .....\n";
    std::cout << "................................\n";
    std::cout << "0. EXIT.........................\n\n";

    std::cout << "Enter";
}

void UserInterface::loadMenu()
{
    std::cout << "\nPlease choose an option from the following list:\n";
    std::cout << "1. Issue a product ...............\n";
    std::cout << "2. Return a product ..............\n";
    std::cout << "3. See customer's borrows ........\n";
    std::cout << "4. Status of a product ...........\n";
    std::cout << "5. Add customer ..................\n";
    std::cout << "..................................\n";
    std::cout << "0. EXIT ..........................\n\n";

    std::cout << "Enter";
}

void UserInterface::issueProductInstruction()
{
    std::cout << "\nTo issue a product to a customer, the CRN is required\n";
    std::cout << "as well as the product ID/s that the customer wish to\n";
    std::cout << "rent.\n";
}

void UserInterface::returnProductInstruction()
{
    std::cout << "\nTo return a product to a customer, the CRN is required\n";
    std::cout << "as well as the product ID/s that the customer wish to\n";
    std::cout << "rent.\n";
}

void UserInterface::seeBorrowsInstruction()
{
    std::cout << "\nTo see the borrows of a customer, the CRN is required.\n";
}

void UserInterface::productStatusInstruction()
{
    std::cout << "\nTo see the status of a product, the product ID is required.\n";
}

void UserInterface::addCustomerInstruction()
{
    std::cout << "\nTo add a new customer, certain details are required, such as:\n";
    std::cout << "\t- name\n\t- gender\n\t- age \n\t- address\n\t- email\n\t- phone number\n";
}

void UserInterface::printCustomerData(std::string data) {
    std::cout << "You selected:";
    std::cout << data << std::endl;
}

void UserInterface::printProductConfirmation(std::string aProduct) {
    std::cout << "Borrowed " << aProduct << std::endl;
}

void UserInterface::printTotalPay(double price) {
    std::cout << "\nTotal amount to pay: £" << price << std::endl;
}

void UserInterface::noProductsLoaned(std::string customer) {
    std::cout << "The customer " << customer << " has no loaned products.\n";
}

std::string UserInterface::isReturningMore() {
    std::cout << "Would you like to return more items? (Y/n)";
    return getInput<std::string>(); 
}

void UserInterface::noMoreProducts(std::string customer) {
    std::cout << "The customer " << customer << " has no more items loaned.\n";
}

std::string UserInterface::LoginSuccesfull()
{
    std::string message = "\nLogin successful!\n";
    std::cout << message;
    return message;
}

std::string UserInterface::LoginUnsuccesfull()
{
    std::string message = "\nInvalid name or PIN. Please try again.\n";
    std::cout << message;
    return message;
}

std::string UserInterface::MaximumLoginAttemps()
{
    std::string message = "\nMaximum login attempts reached. Access denied.\n";
    std::cout << message;
    return message;
}

std::string UserInterface::RegistrationSuccesfull()
{
    std::string message = "Merchant added successfully with ID: ";
    std::cout << message;
    return message;
}

std::string UserInterface::CustomerRegistrationSuccesfull()
{
    std::string message = "Customer added successfully with ID: ";
    std::cout << message;
    return message;
}

// methods used to read inputs from user and returns
// the relevant data
std::string UserInterface::getNameInput()
{
    std::string name;
    std::cout << "\nEnter Name: ";
    std::getline(std::cin, name);
    return name;
}

std::string UserInterface::getMerchantIDInput()
{
     std::string ID;
    std::cout << "\nEnter Merchant ID: ";
    std::getline(std::cin, ID);
    return ID;
}

std::string UserInterface::getEmailInput()
{
    std::string email;
    std::cout << "\nEnter email: ";
    std::getline(std::cin, email);
    return email;
}

std::string UserInterface::getAddressInput()
{
    std::string Address;
    std::cout << "\nEnter Postcode: ";
    std::getline(std::cin, Address);
    return Address;
}

std::string UserInterface::getIDInput()
{
    std::string ID;
    std::cout << "\nEnter CRN: ";
    std::getline(std::cin, ID);
    return ID;
}

std::string UserInterface::getPinInput()
{
    std::string Pin;
    std::cout << "\nEnter PIN (4-digit number): ";
    std::getline(std::cin, Pin);
    return Pin;
}

std::string UserInterface::getGenderInput()
{
    std::string gender;
    std::cout << "\nEnter gender(male/female): ";
    std::getline(std::cin, gender);
    return gender;
}

int UserInterface::getProductIDInput() {
    std::cout << "\nEnter product ID";
    return getInput<int>();
}

int UserInterface::getNumberOfItems() {
    std::cout << "\nEnter the number of items";
    return getInput<int>();
}


void UserInterface::invalidgender(const std::string &gender)
{
    std::cout << "\nThe gender \"" << gender << "\" is invalid, try again.\n";
    std::cout << "\nEnter gender : ";
}


std::string UserInterface::getAgeInput()
{
    std::string age;
    std::cout << "\nEnter age: ";
    std::getline(std::cin, age);
    return age;
}

void UserInterface::invalidAge()
{
    std::cout << "\nThe age should be a number\n";
    std::cout << "\nEnter Age : ";
}

std::string UserInterface::getphoneNumberInput()
{
    std::string phoneNumber;
    std::cout << "\nEnter phone Number: ";
    std::getline(std::cin, phoneNumber);
    return phoneNumber;
}

void UserInterface::invalidphoneNumber()
{
    std::cout << "\nThe phone Number should be a number\n";
    std::cout << "\nEnter phone Number : ";
}


// message when the user chooses to abort an action
void UserInterface::abortMessage()
{
    std::cout << "\nAction cancelled, going back...\n";
}

void UserInterface::invalidMenuChoiceMessage()
{
    std::cout << "\nInvalid choice, please enter a valid number label!\n";
}

void UserInterface::errorMessage()
{
    std::cout << "\nAn error has occurred, please try again later...\n";
}

void UserInterface::exitProgram()
{
    std::cout << "\nExiting...\n";
}

void UserInterface::logout()
{
    std::cout << "\nLogging out...\n";
}

void UserInterface::invalidName(const std::string &name)
{
    std::cout << "\nThe name \"" << name << "\" is invalid.\n";
    std::cout << "Make sure you are entering a valid name only using letters.\n ";
    std::cout << "\nEnter Name : ";
}

void UserInterface::invalidEmail(const std::string &email)
{
    std::cout << "\nThe email \"" << email << "\" is invalid.\n";
    std::cout << "Make sure you are entering a valid email,\n";
    std::cout << "usually of the format name@domain.co.uk\n";
    std::cout << "\nEnter Email : ";
}

void UserInterface::invalidAddress(const std::string &address)
{
    std::cout << "\nThe Postcode \"" << address << "\" is invalid.\n";
    std::cout << "Make sure you are entering a valid Postcode.\n";
    std::cout << "\nEnter Postcode : ";
}

void UserInterface::invalidID(const std::string &id)
{
    std::cout << "\nThe ID \"" << id << "\" is invalid.\n";
    std::cout << "Make sure you are entering a valid ID.\n";
}

void UserInterface::invalidPin(const std::string &PIN)
{
    std::cout << "\nThe PIN \"" << PIN << "\" is invalid, try again.\n";
    std::cout << "\nEnter PIN : ";
}

void UserInterface::productUnavailable(std::string product){
    std::cout << "The product " << product << " is unavailable.\n";
}