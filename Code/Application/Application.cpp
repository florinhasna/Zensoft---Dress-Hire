#include "Application.h"
#include "../Utilities/Utilities.h"

Application::Application(UserInterface ui, DataReader d)
{
    this->UI = ui;
    this->data = d;

    // Read and insert products
    auto products = d.readProducts();
    for (const auto &product : products)
    {
        productHashTable.put(product.getProductID(), product);
    }

    // Read and insert merchants
    auto merchants = d.readMerchants();
    for (const auto &merchant : merchants)
    {
        merchantHashTable.put(merchant.getStaffID(), merchant);
    }

    // Read and insert customers
    auto customers = d.readCustomers();
    for (const auto &customer : customers)
    {
        customerHashTable.put(customer.getID(), customer);
    }
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
    std::string merchantID, pin;
    bool loginSuccess = false;
    const int maxLoginAttempts = 3;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int attempts = 0; attempts < maxLoginAttempts; attempts++)
    {
        merchantID = UserInterface::getMerchantIDInput();
        pin = UserInterface::getPinInput();

        // Check if merchant exists in  merchanthastables
        if (merchantHashTable.contains(merchantID))
        {
            try
            {
                Merchant *merchant = &merchantHashTable.get(merchantID);
                if (merchant->getPIN() == pin)
                {
                    UserInterface::LoginSuccesfull();
                    loginSuccess = true;
                    loggedIn = merchant;
                    loopMainMenu();
                    break;
                }
                else
                {
                    UserInterface::LoginUnsuccesfull();
                }
            }
            catch (const std::exception &e)
            {
                UserInterface::LoginUnsuccesfull();
            }
        }
        else
        {
            UserInterface::LoginUnsuccesfull();
        }

        if (!loginSuccess && attempts == maxLoginAttempts - 1)
        {
            UserInterface::MaximumLoginAttemps();
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

    Merchant newMerchant(name, email, address, merchantID, pin);
    DataReader::AppendMerchantToCSV("Merchants.csv", newMerchant);
    merchantHashTable.put(merchantID, std::move(newMerchant));
    UserInterface::RegistrationSuccesfull();
    std::cout << merchantID << std::endl;
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
    // print instructions for the selected action
    this->getUI().issueProductInstruction();

    // initialise a Customer pointer
    Customer *aCustomerPtr = this->getACustomer();

    if (aCustomerPtr == nullptr)
    {
        return;
    }

    // print the customer data
    this->getUI().printCustomerData(aCustomerPtr->toString());

    // initialise an integer variable to hold number of items customer is borrowing
    int items;
    do
    {
        // read in the number of items
        items = this->getUI().getNumberOfItems();
        if (items == 0)
        { // choice to abort
            this->getUI().abortMessage();
            return;
        }
    } while (items < 0); // until the number is valid

    int daysOfBorrowal;
    do{
        daysOfBorrowal = this->getUI().getNumberOfDays();

        if(daysOfBorrowal <= 0) {
            this->getUI().errorMessage();
        } else if(daysOfBorrowal == 0){
            this->getUI().abortMessage();
            return;
        }
    } while (daysOfBorrowal <= 0);

    std::vector<Product *> products;
    for (int i = 0; i < items; i++)
    {
        Product *aProduct = this->getAProduct();
        if (aProduct->getIsAvailable())
        {
            products.push_back(aProduct);
        }
        else
        {
            this->getUI().productUnavailable(aProduct->getProductName() + " - " + aProduct->getCollection());
        }
    }

    double price = 0;
    for (Product *p : products)
    {
        loggedIn->issueProduct(aCustomerPtr, p); // Assumes this function changes availability but does not set dates.
        p->setDateOfBorrowal(Date::getCurrentDate());
        p->setDueDate(daysOfBorrowal);          // Needs to be added
        price += p->getDailyRentalPrice();

        this->getUI().printProductConfirmation(p->getProductName() + " " + p->getProductSize() + " - " + p->getCollection());
    }

    if (products.size() != 0)
    {
        this->getUI().printTotalPay(price);
    }


}
void Application::returnProduct()
{
    this->getUI().returnProductInstruction();

    // get the customer
    Customer *aCustomer = this->getACustomer();

    if (aCustomer == nullptr) // aborting
    {
        return;
    }

    std::string choice;
    do
    {
        // if the customer does not have any loaned products
        if (aCustomer->getProductsLoaned().empty())
        {
            this->getUI().noProductsLoaned(aCustomer->getName());
            break;
        }

        // print the products
        for (Product *p : aCustomer->getProductsLoaned())
        {
            std::cout << p->toString() << std::endl;
        }

        // get the product input
        Product *aProduct = this->getAProduct();

        // aborting
        if(aProduct == nullptr) {
            return;
        }

        // return the product
        loggedIn->returnProduct(aCustomer, aProduct);

        // if the customer has no more products loaned, exit the loop
        if (aCustomer->getProductsLoaned().size() == 0)
        {
            this->getUI().noMoreProducts(aCustomer->getName());
            break;
        }

        // return more products prompt
        choice = this->getUI().isReturningMore();
        if (choice == "N" || choice == "n")
        {
        }
        else
        {
            this->getUI().errorMessage();
            choice = this->getUI().isReturningMore();
        }
    } while (choice == "Y" || choice == "y");
}

void Application::seeBorrows()
{
    this->getUI().seeBorrowsInstruction();

    Customer *aCustomer = this->getACustomer();

    if (aCustomer == nullptr)
    {
        return;
    }

    auto borrows = aCustomer->getProductsLoaned();

    std::cout << "\nBorrows:\n";
    for (auto borrow : borrows)
    {
        std::cout << borrow->toString();
    }
}

void Application::seeProductStatus()
{
    this->getUI().productStatusInstruction();

    Product *aProduct = this->getAProduct();

    if (aProduct == nullptr)
    {
        return;
    }

    if (aProduct->getIsAvailable()) {
        std::cout << "The product is currently available\n";
    } else {
        std::cout << "Borrowed by: " << aProduct->getBorrowedBy() << std::endl;
    }
    
    std::cout << aProduct->toString();
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
        UserInterface::invalidAge();
        std::getline(std::cin, age);
    }

    std::string phoneNumber = UserInterface::getphoneNumberInput();
    while (!ValidatephoneNumber(phoneNumber))
    {
        UserInterface::invalidphoneNumber();
        std::getline(std::cin, phoneNumber);
    }

    std::vector<Customer> Customers = this->data.readCustomers();
    std::string CustomerID = generateMemberID(Customers, name);
    Customer newCustomer(name, address, CustomerID, email, gender, age, phoneNumber);
    DataReader::AppendCustomerToCSV("Customers.csv", newCustomer);
    UserInterface::CustomerRegistrationSuccesfull();
    std::cout << CustomerID << std::endl;
}

Customer *Application::getACustomer()
{
    // read from user an ID input for a customer
    std::cin.ignore();
    std::string crn = this->getUI().getIDInput();

    // initialise a Customer pointer
    Customer *aCustomerPtr = nullptr;
    do
    {
        // check if the customer exists
        if (customerHashTable.contains(crn))
        {
            aCustomerPtr = &customerHashTable.get(crn); // if it does, assign to pointer
        }
        else
        {
            // invalid message
            this->getUI().invalidID(crn);

            // choice is to abort the action
            if (crn == "0")
            {
                this->getUI().abortMessage();
                return nullptr;
            }
            else
            { // try again
                std::cin.ignore();
                crn = this->getUI().getIDInput();
            }
        }
    } while (aCustomerPtr == nullptr); // until a customer is found

    return aCustomerPtr;
}

Product *Application::getAProduct()
{
    // to be repeated for every item
    int pID; // holdin a product ID
    do
    {
        // read in the ID of a product
        pID = this->getUI().getProductIDInput();

        // if the choice is to abort
        if (pID == 0)
        {
            this->getUI().abortMessage();
            return nullptr;
        }
    } while (!productHashTable.contains(pID)); // until a product is found

    // assing the product address to a pointer
    return &productHashTable.get(pID);
}
