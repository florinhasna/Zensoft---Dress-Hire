#include "Application.h"

Application::Application(UserInterface ui, DataReader d)
{
    this->UI = ui;
    this->data = d;
}

Application::~Application() {}

UserInterface Application::getUI()
{
    return this->UI;
}

DataReader Application::getData()
{
    return this->data;
}

void Application::start()
{
    loopLoginMenu();
}

void Application::loopLoginMenu()
{
    int choice;
    do
    {
        this->getUI().loadLogin();
        choice = getInput<int>();

        switch (choice)
        {
        case 0:
            this->getUI().exitProgram();
            break;
        case 1:
            login();
            break;
        case 2:
            addMerchant();
            break;
        default:
            this->getUI().invalidMenuChoiceMessage();
        }
    } while (choice != 0);
}

void Application::login()
{
    std::vector<Merchant> merchants = this->data.readMerchants();

    std::string merchantID, pin;
    bool loginSuccess = false;
    const int maxLoginAttempts = 3;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int attempts = 1; attempts <= maxLoginAttempts; attempts++)
    {
        merchantID = UserInterface::getMerchantIDInput();

        pin = UserInterface::getPinInput();
        
        for (const auto &merchant : merchants)
        {
            if (merchant.getStaffID() == merchantID && merchant.getPIN() == pin)
            {
                UserInterface::LoginSuccesfull();
                loginSuccess = true;
                loopMainMenu();
                return;
            }
        }

        if (!loginSuccess)
        {
            if (attempts == maxLoginAttempts)
            {
                UserInterface::MaximumLoginAttemps();
                return;
            }
            else
            {
                UserInterface::LoginUnsuccesfull();
            }
        }
    }
}

void Application::addMerchant()
{
    std::string name, address, email, pin;
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     name = UserInterface::getNameInput();
    while (!ValidateName(name))
    {
        UserInterface::invalidName(name);
        std::getline(std::cin, name);
    }

    address = UserInterface::getAddressInput();
    while (!ValidatePostcode(address))
    {
        UserInterface::invalidAddress(address);
        std::getline(std::cin, address);
    }

   email = UserInterface::getEmailInput();
    while (!ValidateEmail(email))
    {
        UserInterface::invalidEmail(email);
        std::getline(std::cin, email);
    }

    pin = UserInterface::getPinInput();
    while (!ValidatePIN(pin))
    {
        UserInterface::invalidPin(pin);
        std::getline(std::cin, pin);
    }

  std::vector<Merchant> merchants = this->data.readMerchants();
 std::string merchantID = generateMemberID(merchants, name);
    //std::string staffID = generateMemberID(name);
    
    Merchant newMerchant(name, email, address, merchantID, pin);
    DataReader::AppendMerchantToCSV("Merchants.csv", newMerchant);
    UserInterface::RegistrationSuccesfull(); 
    std::cout <<  merchantID << std::endl;
}

void Application::loopMainMenu()
{
    int choice;
    do
    {
        this->getUI().loadMenu();
        choice = getInput<int>();

        switch (choice)
        {
        case 0:
            this->getUI().logout();
            break;
        case 1:
            issueProduct();
            break;
        case 2:
            returnProduct();
            break;
        case 3:
            seeBorrows();
            break;
        case 4:
            seeProductStatus();
            break;
        case 5:
            addCustomer();
            break;
        default:
            this->getUI().invalidMenuChoiceMessage();
        }
    } while (choice != 0);
}

void Application::issueProduct()
{
    this->getUI().issueProductInstruction();
}

void Application::returnProduct()
{
    this->getUI().returnProductInstruction();
}

void Application::seeBorrows()
{
    this->getUI().seeBorrowsInstruction();
}

void Application::seeProductStatus()
{
    this->getUI().productStatusInstruction();
}

void Application::addCustomer()
{
    this->getUI().addCustomerInstruction();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string name = UserInterface::getNameInput();
    while (!ValidateName(name))
    {
        UserInterface::invalidName(name);
        std::getline(std::cin, name);
    }
    std::string email = UserInterface::getEmailInput();
    while (!ValidateEmail(email))
    {
        UserInterface::invalidEmail(email);
        std::getline(std::cin, email);
    }

    std::string address = UserInterface::getAddressInput();
    while (!ValidatePostcode(address))
    {
        UserInterface::invalidAddress(address);
        std::getline(std::cin, address);
    }

    std::string gender = UserInterface::getGenderInput();
    while (!ValidateGender(gender))
    {
        UserInterface::invalidgender(gender);
        std::getline(std::cin, gender);
    }

    std::string age = UserInterface::getAgeInput();
    while (!Validateage(age))
    {
        UserInterface::invalidAge(age);
        std::getline(std::cin, age);
    }

    std::string phoneNumber = UserInterface::getphoneNumberInput();
    while (!ValidatephoneNumber(phoneNumber))
    {
        UserInterface::invalidphoneNumber(phoneNumber);
        std::getline(std::cin, phoneNumber);
    }

    std::vector<Customer> Customers = this->data.readCustomers();
    std::string CustomerID = generateMemberID(Customers, name);
   Customer newCustomer(name, address, CustomerID, email, gender, age, phoneNumber);
    DataReader::AppendCustomerToCSV("Customers.csv", newCustomer);
    UserInterface::CustomerRegistrationSuccesfull();
    std::cout << CustomerID << std::endl;
}
