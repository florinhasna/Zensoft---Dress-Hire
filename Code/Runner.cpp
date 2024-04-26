#include "Data/DataReader.h"
#include "Application/Application.h"
#include "Utilities/Hash.h"
#include <iostream> 
#include "UserInterface/UserInterface.h"

int main() {
    //Test for Late and borrowal to show it works
    //Product p(1, "Male", "Winter", "Jacket", "Warm Jacket", "L", "Black", 10.0, 100.0);
    //p.setDateOfBorrowal("24-04-2024");

//std::cout << "Total cost for borrowal: $" 
          //<< std::fixed << std::setprecision(2) 
          //<< p.calculateTotalForBorrowal() << std::endl;
//std::cout << "Is the product late? " << (p.isLate() ? "Yes" : "No") << std::endl;
    DataReader dataReader("Products.csv", "Merchants.csv", "Customers.csv");
    UserInterface ui;
    Application application(ui, dataReader);

    // Start the application 
    application.start();

    return 0;
}
