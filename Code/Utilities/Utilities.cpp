#include "Utilities.h"

#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <iomanip>

template <typename T>
T getInput(){
    T input;
    std::cout << " > ";
    std::cin >> input;
    return input;
}

//initializes the member variable date with the 
//value of the date parameter passed to the constructor.
Date::Date(const std::string& date) : date(date) {}
Date::Date() {}

std::string Date::getDateOfBorrowal() const{
    return date;
}

std::string Date::getDueDate(int rentalDays) const{
    return date + "Due in " + rentalDays + "days";
}

void Date::setDateOfBorrowal(const std::string& aDate){
    date = aDate;
}

void Date::setDueDate(const std::string& aDate){
    date = aDate;
    //will need to calculate amount of days in seconds
    //then convert to days 
}
