#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <ctime>
#include <string>
#include <iomanip>
#include "Hash.h"
#include <random>

class Date{

private:
    std::string date; //date in string format 

// public:
    // Date(const std::string& date);
//     Date();

//     std::string getDateOfBorrowal() const;
//     std::string getDueDate() const;

//     void setDateOfBorrowal(const Date& aDate);
//     void setDueDate(const Date& aDate); 

    
};


inline bool ValidateName(const std::string& name);
inline bool ValidatePostcode(const std::string& address);
inline bool ValidateEmail(const std::string& email);
inline bool ValidatePIN(const std::string& pin); 
inline bool ValidateGender(const std::string& gender); 
inline bool Validateage(const std::string& age); 
inline bool ValidatephoneNumber(const std::string& phoneNumber); 
template <typename T>
std::string generateMemberID(const std::vector<T>& existingItems, const std::string &name);

#endif
