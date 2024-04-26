#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Utilities/Hash.h"
#include "../Domain/Merchant.h"
#include "../Domain/Product.h"
#include "../Domain/Customer.h"
#include "../Data/DataReader.h"
#include "../Utilities/Utilities.h" 

#include <fstream>
#include <vector>
#include <string>

// Mock class used to simulate members in the system for ID generation testing.
class MockMember {
    std::string id;
public:
    MockMember(const std::string& id) : id(id) {}
    std::string getID() const { return id; }
};

// Test suite for generating member IDs
TEST_CASE("Member ID Generation", "[ID Generation]") {
    std::vector<MockMember> members; // Vector to hold mock members for ID uniqueness checking

    // Testing ID generation with a standard alphabetic name
    SECTION("Generate ID for standard names") {
        std::string name = "John Doe";
        std::string id = generateMemberID(members, name);
        REQUIRE_FALSE(id.empty()); // Ensure an ID is generated and it is not empty
        INFO("Generated ID: " + id); // Output the generated ID for inspection
    }

    // Testing ID generation with a name that includes numeric characters
    SECTION("Generate ID for names with numbers") {
        std::string name = "John123";
        std::string id = generateMemberID(members, name);
        REQUIRE_FALSE(id.empty()); // Ensure an ID is generated and it is not empty
        INFO("Generated ID: " + id); // Output the generated ID for inspection
    }

    // Testing ID generation with a name that includes special characters
    SECTION("Generate ID for names with special characters") {
        std::string name = "@Jane$%^";
        std::string id = generateMemberID(members, name);
        REQUIRE_FALSE(id.empty()); // Ensure an ID is generated and it is not empty
        INFO("Generated ID: " + id); // Output the generated ID for inspection
    }
}

// Test suite for various input validations
TEST_CASE("Validation Functions", "[Validation]") {
    // Validate typical and correctly formatted names
    SECTION("Validate Names") {
        REQUIRE(ValidateName("John Doe")); // Should return true for a valid name
        REQUIRE_FALSE(ValidateName("John123")); // Should return false for a name with numbers
        REQUIRE_FALSE(ValidateName("12345")); // Should return false for a numeric string
        REQUIRE_FALSE(ValidateName("@John!")); // Should return false for a name with special characters
    }

    // Validate email addresses against a typical pattern
    SECTION("Validate Email") {
        REQUIRE(ValidateEmail("email@example.com")); // Should return true for a valid email
        REQUIRE_FALSE(ValidateEmail("email@example")); // Should return false for missing domain
        REQUIRE_FALSE(ValidateEmail("email.com")); // Should return false for missing '@' symbol
        REQUIRE_FALSE(ValidateEmail("@example.com")); // Should return false for missing local part
    }

    // Validate PIN numbers to be exactly four digits
    SECTION("Validate PIN") {
        REQUIRE(ValidatePIN("1234")); // Should return true for a valid four-digit PIN
        REQUIRE_FALSE(ValidatePIN("12345")); // Should return false for a five-digit number
        REQUIRE_FALSE(ValidatePIN("abcd")); // Should return false for non-numeric input
        REQUIRE_FALSE(ValidatePIN("12")); // Should return false for a two-digit number
    }

    // Validate phone numbers according to a specific format
    SECTION("Validate Phone Number") {
        REQUIRE(ValidatephoneNumber("+44 7700 900123")); // Should return true for a valid format
        REQUIRE_FALSE(ValidatephoneNumber("+44 7700 900")); // Should return false for incomplete number
        REQUIRE_FALSE(ValidatephoneNumber("1234567890")); // Should return false for incorrect format
    }

    // Validate ages to ensure they are numeric and within a reasonable range
    SECTION("Validate Age") {
        REQUIRE(Validateage("30")); // Should return true for a valid numeric age
        REQUIRE_FALSE(Validateage("abc")); // Should return false for non-numeric age
        REQUIRE_FALSE(Validateage("-1")); // Should return false for negative numbers
    }
}

// Define a test case for the LinearProbingHash class functionality
TEST_CASE("LinearProbingHash functionality tests", "[hash]") {
    // Create an instance of the hash table with string keys and integer values
    LinearProbingHash<std::string, int> hash;

    // Test inserting and retrieving values from the hash table
    SECTION("Insert and retrieve values") {
        // Insert some key-value pairs
        hash.put("one", 1);
        hash.put("two", 2);
        hash.put("three", 3);

        // Check that values can be retrieved correctly
        REQUIRE(hash.get("one") == 1);  // Expect value associated with "one" to be 1
        REQUIRE(hash.get("two") == 2);  // Expect value associated with "two" to be 2
        REQUIRE(hash.get("three") == 3);  // Expect value associated with "three" to be 3
    }

    // Test updating the value associated with an existing key in the hash table
    SECTION("Update existing key") {
        // Insert a key-value pair and then update the value
        hash.put("one", 1);
        hash.put("one", 100);  // Update the value associated with key "one"

        // Verify that the value has been updated correctly
        REQUIRE(hash.get("one") == 100);  // Expect the updated value to be 100
    }

    // Test the behavior when trying to retrieve a value using a non-existing key
    SECTION("Handle non-existing key") {
        // Insert a single key-value pair
        hash.put("one", 1);

        // Attempt to get a value using a non-existing key should throw a runtime error
        REQUIRE_THROWS_AS(hash.get("two"), std::runtime_error);  // "two" has not been inserted
    }

    // Test resizing of the hash table when load factor exceeds threshold
    SECTION("Resize hash table") {
        // Insert enough items to trigger a resize of the hash table
        int n_items = 50;  // Assuming a resize threshold at load factor > 0.5, this should trigger a resize
        for (int i = 0; i < n_items; ++i) {
            hash.put("key" + std::to_string(i), i);  // Insert sequential keys with their index as the value
        }

        // Check if the number of keys is correct after resizing
        REQUIRE(hash.keys().size() == n_items);  // Ensure all items are still accessible and correctly counted

        // Verify that all values remain correct after the hash table has been resized
        for (int i = 0; i < n_items; ++i) {
            REQUIRE(hash.get("key" + std::to_string(i)) == i);  // Each key should retrieve its corresponding value
        }
    }
}

// Test cases for the Product class
TEST_CASE("Product class tests", "[Product]") {
    SECTION("Check if product ID is set and retrieved correctly") {
        Product product(1, "Male", "Spring Collection", "Shirt", "Slim Fit Shirt", "Large", "Blue", 25.99, 49.99);
        REQUIRE(product.getProductID() == 1);
    }

}

// Test cases for the Merchant class
TEST_CASE("Merchant class tests", "[Merchant]") {
    SECTION("Check if PIN is set and retrieved correctly") {
        Merchant merchant("John Doe", "john@example.com", "123 Main St", "M123", "1234");
        REQUIRE(merchant.getPIN() == "1234");
    }
}

// Helper function to check if a file exists
bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

// Test case for appending new merchant and customer data to existing CSV files
TEST_CASE("Append Merchant and Customer Data to Existing CSV Files", "[DataReader]") {
    // Define filenames for existing CSV files
    std::string productsFile = "TEST"; 
    std::string merchantsFile = "../Merchants.csv";
    std::string customersFile = "../Customers.csv"; // Update the path as necessary

    // Create DataReader object - needs 3 args
    DataReader dataReader(productsFile, merchantsFile, customersFile);

    // Define data for new merchant
    std::string newMerchantName = "New Merchant";
    std::string newMerchantEmail = "new_merchant@example.com";
    std::string newMerchantAddress = "123 New Street";
    std::string newMerchantStaffID = "M12345";
    std::string newMerchantPIN = "1234";

    // Define data for new customer
    std::string newCustomerName = "New Customer";
    std::string newCustomerAddress = "456 Old Road";
    std::string newCustomerID = "C67890";
    std::string newCustomerEmail = "new_customer@example.com";
    std::string newCustomerGender = "Non-Binary";
    std::string newCustomerAge = "40";
    std::string newCustomerPhoneNumber = "+1234567890";

    // Append new merchant data to existing CSV file
    dataReader.AppendMerchantToCSV(merchantsFile, Merchant(newMerchantName, newMerchantEmail, newMerchantAddress, newMerchantStaffID, newMerchantPIN));

    // Append new customer data to existing CSV file
    dataReader.AppendCustomerToCSV(customersFile, Customer(newCustomerName, newCustomerAddress, newCustomerID, newCustomerEmail, newCustomerGender, newCustomerAge, newCustomerPhoneNumber));

    // Verify that the data was successfully appended
    REQUIRE(fileExists(merchantsFile)); // Check if merchants file still exists
    REQUIRE(fileExists(customersFile)); // Check if customers file still exists

    // Read back the updated data
    std::vector<Merchant> updatedMerchants = dataReader.readMerchants();
    std::vector<Customer> updatedCustomers = dataReader.readCustomers();

    // Check if the new merchant data was added
    bool newMerchantFound = false;
    for (const auto& merchant : updatedMerchants) {
        if (merchant.getName() == newMerchantName &&
            merchant.getEmail() == newMerchantEmail &&
            merchant.getAddress() == newMerchantAddress &&
            merchant.getStaffID() == newMerchantStaffID &&
            merchant.getPIN() == newMerchantPIN) {
            newMerchantFound = true;
            break;
        }
    }

    // Check if the new customer data was added
    bool newCustomerFound = false;
    for (const auto& customer : updatedCustomers) {
        if (customer.getName() == newCustomerName &&
            customer.getEmail() == newCustomerEmail &&
            customer.getAddress() == newCustomerAddress &&
            customer.getID() == newCustomerID &&
            customer.getGender() == newCustomerGender &&
            customer.getAge() == newCustomerAge &&
            customer.getPhoneNumber() == newCustomerPhoneNumber) {
            newCustomerFound = true;
            break;
        }
    }

    REQUIRE(newMerchantFound); // Ensure new merchant was added successfully
    REQUIRE(newCustomerFound); // Ensure new customer was added successfully
}

// Test suite for Date class
TEST_CASE("Date Class Tests", "[Date]") {
    // Test constructor and date retrieval
    SECTION("Constructor and Date Retrieval") {
        Date dateObj("01-01-2020");
        REQUIRE(dateObj.getDateOfBorrowal() == "01-01-2020");
    }

    // Test due date setting and retrieval
    SECTION("Set and Retrieve Due Date") {
        Date dateObj("01-01-2020");
        dateObj.setDueDate(30); // Set due date 30 days later
        REQUIRE(dateObj.getDueDate() == "31-01-2020");
    }

    // Test handling of invalid date formats
    SECTION("Handle Invalid Date Format") {
        Date dateObj("invalid-date");
        REQUIRE_THROWS_AS(dateObj.setDueDate(30), std::runtime_error);
    }

    // Test behavior with empty date string
    SECTION("Empty Date String") {
        Date dateObj;
        REQUIRE(dateObj.getDateOfBorrowal().empty());
        REQUIRE(dateObj.getDueDate().empty());
        REQUIRE_NOTHROW(dateObj.setDueDate(30)); // Should not throw, dueDate should remain empty
        REQUIRE(dateObj.getDueDate().empty());
    }

    // Test setting new borrowal date
    SECTION("Set New Borrowal Date") {
        Date dateObj;
        dateObj.setDateOfBorrowal("15-02-2020");
        REQUIRE(dateObj.getDateOfBorrowal() == "15-02-2020");
    }
}
