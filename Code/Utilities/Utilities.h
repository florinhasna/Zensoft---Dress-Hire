#ifndef _UTILITIES_H_
#define _UTILITIES_H_
#include <ctime>
#include <sstream>
#include "hash.h"
#include "Help.h"

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
    static std::string getCurrentDate() {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        std::ostringstream oss;
        oss << now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900);
        return oss.str();
    }

    void setDateOfBorrowal(const std::string& aDate);
    void setDueDate(const int rentalDays);   
};

#endif
