#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Utilities/Utilities.cpp"

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

