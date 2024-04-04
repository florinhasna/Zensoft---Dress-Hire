#include "UserInterface/UserInterface.h"
#include "Data/DataReader.h"
#include "Application/Application.h"

int main() {
    UserInterface ui;
    DataReader data;
    Application application(ui, data);

    application.start();
    return 0;
}