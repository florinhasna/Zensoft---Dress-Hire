#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include "hash.h"
#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>
#include <ctime>
#include <string>
#include <iomanip>
#include <random>
#include <ctime>
#include <sstream>

class Date{

private:
    std::string date; //date in string format 
    std::string dueDate;
    std::string addDays(const std::string &borrowDate, int rentalDays) const;

public:
    Date();
    Date(const std::string& date);

    std::string getDateOfBorrowal() const;
    std::string getDueDate() const;

    void setDateOfBorrowal(const std::string& aDate);
    void setDueDate(const int rentalDays);   
};

#endif