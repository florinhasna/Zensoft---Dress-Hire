#include "Data/DataReader.h"
#include "Application/Application.h"
#include "Utilities/Hash.h"
#include <iostream> 
#include "UserInterface/UserInterface.h"

int main() {
    DataReader dataReader("Products.csv", "Merchants.csv", "Customers.csv");
    UserInterface ui;
    Application application(ui, dataReader);

    // Start the application 
    application.start();

    return 0;
}
