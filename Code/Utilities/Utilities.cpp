#include "Utilities.h"

template <typename T>
T getInput(){
    T input;
    std::cout << " > ";
    std::cin >> input;
    return input;
}

// //initializes the member variable date with the 
// //value of the date parameter passed to the constructor.
// Date::Date(const std::string& date) : date(date) {}
// Date::Date() {}

// std::string Date::getDateOfBorrowal() const{
//     return date;
// }

// std::string Date::getDueDate(int rentalDays) const{
//     return date + "Due in " + rentalDays + "days";
// }

// void Date::setDateOfBorrowal(const std::string& aDate){
//     date = aDate;
// }

// void Date::setDueDate(const std::string& aDate){
//     date = aDate;
//     //will need to calculate amount of days in seconds
//     //then convert to days 
// }

// bool testName(std::string name){
//     std::regex name_pattern("^[A-Za-z]{3,}\\s[A-Za-z]{3,}$");

//     return regex_match(name, name_pattern);
// }

// bool testAddress(std::string address){
//     std::regex address_pattern("^[1-9]+\\s[a-zA-Z]{3,}\\s[a-zA-Z]{3,}\\,\\s[A-Z0-9]{2,}\\s[A-Z0-9]{3,3}$");

//     return regex_match(address, address_pattern);
// }

// bool testEmail(std::string email){
//     std::regex email_pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
 
//     return regex_match(email, email_pattern);
// }
