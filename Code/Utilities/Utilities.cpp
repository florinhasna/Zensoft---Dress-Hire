#include "utilities.h"

#include <ctime>
#include <sstream>
#include <iomanip>


// template <typename T>
// T getInput()
// {
//     T input;
//     std::cout << " > ";
//     std::cin >> input;
//     return input;
// }

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


bool ValidateName(const std::string &rawName){
    std::string trimmedName = std::regex_replace(rawName, std::regex("^\\s+|\\s+$"), "");
    std::regex name_pattern("^[A-Za-z]{2,}\\s[A-Za-z]{2,}$", std::regex_constants::icase);
    return std::regex_match(trimmedName, name_pattern);
}

inline bool ValidatePostcode(const std::string &address){
    std::regex address_pattern("^[A-Z]{1,2}\\d{1,2}\\s\\d[A-Z]{2}$",std::regex_constants::icase);
    return regex_match(address, address_pattern);
}

inline bool ValidateEmail(const std::string &rawEmail){
    std::string email = std::regex_replace(rawEmail, std::regex("^\\s+|\\s+$"), "");
    std::regex email_pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return std::regex_match(email, email_pattern);
}

inline bool ValidatePIN(const std::string &pin){
    std::regex pin_pattern("^\\d{4}$");
    return regex_match(pin, pin_pattern);
}

inline bool ValidateGender(const std::string &gender){
    std::regex gender_pattern("^(Male|Female)$", std::regex_constants::icase);
    return std::regex_match(gender, gender_pattern);
}

inline bool ValidatephoneNumber(const std::string &phoneNumber){
    std::regex phone_pattern("^(\\+44\\s?7\\d{3}|07\\d{3})\\s?\\d{3}\\s?\\d{3}$");
    return std::regex_match(phoneNumber, phone_pattern);
}

inline bool Validateage(const std::string &age){
    std::regex age_pattern("^(\\d{1,3})$");
    return std::regex_match(age, age_pattern);
}

template <typename T>
inline std::string generateMemberID(const std::vector<T>& existingItems, const std::string &name) {
    if (name.empty())
        return "";

    std::string newID;
    bool isUnique;
    do {
        // Random ID generation logic remains the same
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(1000, 9999);
        char firstLetter = std::toupper(name[0]);
        int randomNumbers = uni(rng);
        newID = firstLetter + std::to_string(randomNumbers);

        // Check if this newID is unique among existingItems
        isUnique = std::none_of(existingItems.begin(), existingItems.end(),
            [&newID](const T& item) {
                return item.getID() == newID; // T must have a getID() method
            });
    } while (!isUnique);

    return newID;
}
