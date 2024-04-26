#include "utilities.h"

//initialises the member variable date with the
//value of the date parameter passed to the constructor.
Date::Date(const std::string& date) : date(date) , dueDate("") {}
Date::Date() : date(""), dueDate("") {}

std::string Date::getDateOfBorrowal() const{
    return date;
}

std::string Date::getDueDate() const{
    return dueDate ;
}

void Date::setDateOfBorrowal(const std::string& aDate){
    date = aDate;
}

void Date::setDueDate(const int rentalDays){
    if (!date.empty()){
        dueDate = addDays(date, rentalDays);
    }
}

//method adds days to the given borrow date
std::string Date::addDays(const std::string &borrowDate, int rentalDays) const{
    std::tm tm={};
    std::istringstream ss(borrowDate);
    ss >> std::get_time(&tm,"%d-%m-%Y");
    
    //handle error
    if (ss.fail()){
        throw std::runtime_error("Failed to parse data");
    }

    //convert rental days to seconds then
    //add them to borrow date  
    std::time_t time = std::mktime(&tm) + rentalDays * 86400; 
    std::tm *newTm = std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(newTm, "%d-%m-%Y");
    
    return oss.str();

}

