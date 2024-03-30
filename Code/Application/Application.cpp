#include "Application.h"

Application::Application(UserInterface ui, DataReader d){
    this->UI = ui;
    this->data = d;
}

Application::~Application(){}

UserInterface Application::getUI(){
    return this->UI;
}

DataReader Application::getData(){
    return this->data;
}

void Application::start() {
    loopLoginMenu();
}

void Application::loopLoginMenu() {
    int choice;
    do {
        this->getUI().loadLogin();
        choice = getInput<int>();

        switch (choice) {
            case 0: this->getUI().exitProgram(); break;
            case 1: login(); break;
            case 2: addMerchant(); break;
            default: this->getUI().invalidMenuChoiceMessage();
        }
    } while (choice != 0);
}

void Application::login() {
    loopMainMenu();
}

void Application::addMerchant() {

}

void Application::loopMainMenu() {
    int choice;
    do {
        this->getUI().loadMenu();
        choice = getInput<int>();

        switch (choice) {
            case 0: this->getUI().logout(); break;
            case 1: loopStockManagement(); break;
            case 2: issueProduct(); break;
            case 3: returnProduct(); break;
            case 4: seeBorrows(); break;
            case 5: seeProductStatus(); break;
            case 6: addCustomer(); break;
            default: this->getUI().invalidMenuChoiceMessage();
        }
    } while (choice != 0);
}

void Application::loopStockManagement() {
    int choice;
    do {
        this->getUI().loadStockManagementMenu();
        choice = getInput<int>();

        switch (choice) {
            case 0: this->getUI().abortMessage(); break;
            case 1: addProduct(); break;
            case 2: removeProduct(); break;
            case 3: updateProductPrice(); break;
            default: this->getUI().invalidMenuChoiceMessage();
        }
    } while (choice != 0);
}

void Application::addProduct() {
    this->getUI().printAddProductInstruction();
}

void Application::removeProduct() {
    this->getUI().printRemoveProductInstruction();
}

void Application::updateProductPrice() {
    this->getUI().printUpdatePriceInstruction();
}

void Application::issueProduct() {
    this->getUI().issueProductInstruction();
}

void Application::returnProduct() {
    this->getUI().returnProductInstruction();
}

void Application::seeBorrows() {
    this->getUI().seeBorrowsInstruction();
}

void Application::seeProductStatus() {
    this->getUI().productStatusInstruction();
}

void Application::addCustomer() {
    this->getUI().addCustomerInstruction();
}