#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <iostream>
#include <string>
#include <vector>
#include "Hash.h"

class Date{

private:
    std::string date; //date in string format 

public:
    Date(const std::string& date);
    Date();

    std::string getDateOfBorrowal() const;
    std::string getDueDate() const;

    void setDateOfBorrowal(const Date& aDate);
    void setDueDate(const Date& aDate); 

    
};



#endif