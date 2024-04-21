#include "Application.h"
#include "../Utilities/Utilities.h"

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
    DataReader dataReader("Merchants.csv"); 
    std::vector<Merchant> merchants = dataReader.readMerchants();

    std::string name, pin;
    bool loginSuccess = false;
   const int maxLoginAttempts = 3;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int attempts = 1; attempts <= maxLoginAttempts; attempts++) { 
        std::cout << "Enter Merchant Name: ";
        std::getline(std::cin, name);
        
        std::cout << "Enter PIN: ";
        std::getline(std::cin, pin);

        for (const auto& merchant : merchants) {
            if (merchant.getName() == name && merchant.getPIN() == pin) {
                std::cout << "Login successful!" << std::endl;
                loginSuccess = true;
                loopMainMenu();
                return; 
            }
        }

        if (!loginSuccess) {
            if (attempts == maxLoginAttempts) {
                std::cout << "Maximum login attempts reached. Access denied." << std::endl;
                return;
            } else {
                std::cout << "Invalid name or PIN. Please try again." << std::endl;
            }
        }
    }
}

void Application::addMerchant() {
  std::string name, address, email, pin;
    
std::cout << "Enter Name: ";
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
std::getline(std::cin, name);  
while (!ValidateName(name)) {
    std::cout << "ddd " << name;
    std::cout << "Invalid name. Please enter a valid name (e.g., John Doe): ";
    std::getline(std::cin, name); 
}


    std::cout << "Enter Postcode: ";
   std::getline(std::cin, address); 
     while (!ValidatePostcode(address)) {
        std::cout << "Invalid Postcode. Please enter a valid Postcode (e.g., kt4 3eg): ";
     std::getline(std::cin, address);
    }
     
    std::cout << "Enter Email: ";
    std::getline(std::cin, email); 
        while (!ValidateEmail(email)) {
        std::cout << "Invalid email. Please enter a valid email (e.g., example@example.com): ";
        std::getline(std::cin, email);
    }
	
    std::cout << "Enter PIN (4-digit number): ";
    std::getline(std::cin, pin); 
   while (!ValidatePIN(pin)) {
        std::cout << "Invalid PIN. Please enter a 4-digit number: ";
       std::getline(std::cin, pin); 
    }

    std::string staffID = generateMemberID(name);
       
    Merchant newMerchant(name, email, address, staffID, pin);  
    //function to write to csv missing  

      std::cout << "Merchant added successfully with ID: " << staffID << std::endl;

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
