#include "UserInterface.h"

UserInterface::UserInterface(){} // constructor
UserInterface::~UserInterface(){}

void UserInterface::loadLogin(){
    std::cout << "\nPlease choose an option from the following list:\n";
    std::cout << "1. Merchant login ..............\n";
    std::cout << "2. Create merchant account .....\n";
    std::cout << "................................\n";
    std::cout << "0. EXIT.........................\n";
}

void UserInterface::loadMenu(){
    std::cout << "\nPlease choose an option from the following list:\n";
    std::cout << "1. Stock management ..............\n";
    std::cout << "2. Issue a product ...............\n";
    std::cout << "3. Return a product ..............\n";
    std::cout << "4. See customer's borrows ........\n";
    std::cout << "5. Status of a product ...........\n";
    std::cout << "6. Add customer ..................\n";
    std::cout << "..................................\n";
    std::cout << "0. EXIT ..........................\n";
}

void UserInterface::loadStockManagementMenu(){
    std::cout << "\nPlease choose an option from the following list:\n";
    std::cout << "1. Add product ...................\n";
    std::cout << "2. Remove product ................\n";
    std::cout << "3. Update rental price ...........\n";
    std::cout << "..................................\n";
    std::cout << "0. EXIT ..........................\n";
}

void UserInterface::printAddProductInstruction(){
    std::cout << "\nTo add a product, details like product type, product name,\n";
    std::cout << "collection, gender, size, colour, daily rental price and full\n";
    std::cout << "price.\n";
}

void UserInterface::printRemoveProductInstruction(){
    std::cout << "\nTo remove a product, the product's ID is required.\n";
}

void UserInterface::printUpdatePriceInstruction(){
    std::cout << "\nTo update the price of a product, the product ID is required.\n";
}

void UserInterface::issueProductInstruction(){
    std::cout << "\nTo issue a product to a customer, the CRN is required\n";
    std::cout << "as well as the product ID/s that the customer wish to\n";
    std::cout << "rent.\n";
}

void UserInterface::returnProductInstruction(){
    std::cout << "\nTo return a product to a customer, the CRN is required\n";
    std::cout << "as well as the product ID/s that the customer wish to\n";
    std::cout << "rent.\n";
}

void UserInterface::seeBorrowsInstruction(){
    std::cout << "\nTo see the borrows of a customer, the CRN is required.\n";
}

void UserInterface::productStatusInstruction(){
    std::cout << "\nTo see the status of a product, the product ID is required.\n";
}

void UserInterface::addCustomerInstruction(){
    std::cout << "\nTo add a new customer, certain details are required, such as:\n";
    std::cout << "\t- name\n\t- gender\n\t- age \n\t- address\n\t- email\n\t- phone number\n";
}


// methods used to read inputs from user and returns
// the relevant data
std::string UserInterface::getNameInput(){
    std::cout << "\nEnter name";
    return "";
}

std::string UserInterface::getEmailInput(){
    std::cout << "\nEnter email";
    return "";
}

std::string UserInterface::getAddressInput(){
    std::cout << "\nEnter address";
    return "";
}

int UserInterface::getIDInput(){
    std::cout << "\nEnter ID";
    return 0;
}

int UserInterface::getPinInput(){
    std::cout << "\nEnter PIN number";
    return 0;
}

double UserInterface::getPriceInput(){
    std::cout << "\nEnter price";
    return 0;
}

std::string UserInterface::getProductTypeInput(){
    std::cout << "\nEnter product type";
    return "";
}

std::string UserInterface::getProductNameInput(){
    std::cout << "\nEnter product name";
    return "";
}

std::string UserInterface::getCollectionInput(){
    std::cout << "\nEnter collection";
    return "";
}

std::string UserInterface::getGenderInput(){
    std::cout << "\nEnter gender";
    return "";
}

std::string UserInterface::getSizeInput(){
    std::cout << "\nEnter size";
    return "";
}

std::string UserInterface::getColourInput(){
    std::cout << "\nEnter colour";
    return "";
}

double UserInterface::getDailyRentalPriceInput(){
    std::cout << "\nEnter daily rental price";
    return 0;
}

double UserInterface::getFullPriceInput(){
    std::cout << "\nEnter full price";
    return 0;
}

// message when the user chooses to abort an action
void UserInterface::abortMessage(){
    std::cout << "\nAction cancelled, going back...\n";
}

void UserInterface::invalidMenuChoiceMessage(){
    std::cout << "\nInvalid choice, please enter a valid number label!\n";
}

void UserInterface::errorMessage(){
    std::cout << "\nAn error has occurred, please try again later...\n";
}

void UserInterface::invalidName(std::string name){
    std::cout << "\nThe name \"" << name << "\" is invalid.\n";
    std::cout << "Make sure you are entering a valid name only using letters.\n";
}

void UserInterface::invalidEmail(std::string email){
    std::cout << "\nThe email \"" << email << "\" is invalid.\n";
    std::cout << "Make sure you are entering a valid name,\n";
    std::cout << "usually of the format name@domain.co.uk\n";
}

void UserInterface::invalidAddress(std::string address){
    std::cout << "\nThe address \"" << address << "\" is invalid.\n";
    std::cout << "Make sure you are entering a valid address.\n";
    std::cout << "E.g.: \n";
}

void UserInterface::invalidID(int id){
    std::cout << "\nThe ID \"" << id << "\" is invalid.\n";
    std::cout << "Make sure you are entering a valid ID.\n";
}

void UserInterface::invalidPin(int PIN){
    std::cout << "\nThe PIN \"" << PIN << "\" is invalid, try again.\n";
}

void UserInterface::invalidPrice(double price){
    std::cout << "\nThe price \"£" << price << "\" is invalid.\n";
}

void UserInterface::invalidProductType(std::string productType){
    std::cout << "\nThe product type \"" << productType << "\" is invalid.\n";
}

void UserInterface::invalidProductName(std::string productName){
    std::cout << "\nThe product name \"" << productName << "\" is invalid.\n";
}

void UserInterface::invalidCollection(std::string collection){
    std::cout << "\nThe collection \"" << collection << "\" is invalid.\n";
    std::cout << "Please enter: Summer, Autumn, Winter or Spring.\n";
}

void UserInterface::invalidGender(std::string gender){
    std::cout << "\nThe gender \"" << gender << "\" is invalid.\n";
    std::cout << "Please enter Male or Female.\n";
}

void UserInterface::invalidSize(std::string size){
    std::cout << "\nThe size \"" << size << "\" is invalid.\n";
    std::cout << "Please enter XS, S, M, L, etc.\n";
}

void UserInterface::invalidColour(std::string colour){
    std::cout << "\nThe colour \"" << colour << "\" is invalid.\n";
    std::cout << "Please enter Red, Green, Blue, etc.\n";
}