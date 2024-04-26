#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <ctime>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "hash.h"
#include "Help.h"

class Date {
private:
    std::string date; // Date in string format
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
        oss << std::setfill('0') << std::setw(2) << now->tm_mday << '-'
            << std::setw(2) << (now->tm_mon + 1) << '-'
            << (now->tm_year + 1900);
        return oss.str();
    }

    void setDateOfBorrowal(const std::string& aDate);
    void setDueDate(const int rentalDays);

    static int daysBetween(const std::string& start, const std::string& end) {
        std::tm startDate = {};
        std::tm endDate = {};
        std::istringstream ssStart(start);
        std::istringstream ssEnd(end);
        ssStart >> std::get_time(&startDate, "%d-%m-%Y");
        ssEnd >> std::get_time(&endDate, "%d-%m-%Y");

        std::chrono::system_clock::time_point startTp = std::chrono::system_clock::from_time_t(std::mktime(&startDate));
        std::chrono::system_clock::time_point endTp = std::chrono::system_clock::from_time_t(std::mktime(&endDate));

        return std::chrono::duration_cast<std::chrono::hours>((endTp - startTp)).count() / 24;
    }

    static bool isAfter(const std::string& date1, const std::string& date2) {
        std::tm date1Tm = {};
        std::tm date2Tm = {};
        std::istringstream ssDate1(date1);
        std::istringstream ssDate2(date2);

        ssDate1 >> std::get_time(&date1Tm, "%d-%m-%Y");
        ssDate2 >> std::get_time(&date2Tm, "%d-%m-%Y");

        std::chrono::system_clock::time_point tpDate1 = std::chrono::system_clock::from_time_t(std::mktime(&date1Tm));
        std::chrono::system_clock::time_point tpDate2 = std::chrono::system_clock::from_time_t(std::mktime(&date2Tm));

        return tpDate1 > tpDate2;
    }
};

#endif // _UTILITIES_H_
