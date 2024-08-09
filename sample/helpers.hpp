/*
This file defines useful inline functions for the project:
- GenerateRandomNumber: generates a random number in a given range
- GetWelcomeMessage: returns a random welcome message
- ValidatePhoneNumber: validates a phone number using a regular expression pattern
- GetCurrentDate: returns the current date as a string
- StringDateToTime: transforms a date string into a time_t object

*/

#pragma once

#include <regex>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <sstream>
#include <iomanip>

/*
 * Generate an inline function named 'GenerateRandomNumber' that returns a random number in a given range.
 * Arguments:
 * - 'min': an integer representing the minimum value of the range
 * - 'max': an integer representing the maximum value of the range
 * Returns:
 * - an integer representing a random number in the given range
 * Details:
 * Implement the function using the C++11 random number generation library.
 *
 */
int GenerateRandomNumber(int min, int max)
{
    // Create a random device
    std::random_device rd;

    // Create a random number generator
    std::mt19937 gen(rd());

    // Create a uniform distribution of random numbers
    std::uniform_int_distribution<int> dis(min, max);

    // Return a random number in the given range
    return dis(gen);
}

/*
 *
 * Generate an inline function named 'GetWelcomeMessage' that returns a random welcome message.
 * Arguments: None
 * Returns: A string representing a welcome message
 * Details:
 * Implement the function by creating a collection of welcome messages and returning a random message from the vector.
 * Example: "Hello, World!"
 */
std::string GetWelcomeMessage()
{
    // Create a vector of welcome messages
    std::vector<std::string> messages = {
        "Hello, World!",
        "Welcome to the program!",
        "Thanks for using the program!"};
    // Return a random welcome message
    return messages[GenerateRandomNumber(0, messages.size() - 1)];
}

/*
 * Generate a function that validates a phone number using a regular expression pattern.
 * Arguments:
 *  - 'phoneNumbee': a string representing a phone number
 * Returns:
 *  - a boolean value indicating whether the phone number is valid
 * Details:
 * The phone number must be in the format XXX-XXX-XXXX, where X represents a digit.
 * The phone number may contain optional hyphens, periods, or spaces as separators.
 * Example:
 * - "123-456-7890" is a valid phone number
 * - "123.456.7890" is a valid phone number
 * - "123 456 7890" is a valid phone number
 * - "1234567890" is not a valid phone number
 * - "12-34-5678" is not a valid phone number
 * - "123-456-789" is not a valid phone number
 */
inline bool ValidatePhoneNumber(std::string phoneNumber)
{
    // Create a regular expression to validate a phone number
    std::regex pattern("([0-9]{3})[-. ]?([0-9]{3})[-. ]?([0-9]{4})");

    // Return the result of the regular expression match
    return std::regex_match(phoneNumber, pattern);
}

/**
 * Generate a function that returns the current date as a string.
 * Arguments: None
 * Returns: A string representing the current date
 * Example: "Sun Sep 16 01:03:52 1973"
 */
std::string GetCurrentDate()
{
    // Get the current time
    std::time_t now = std::time(0);

    // Convert the current time to a string
    std::string currentDate = std::ctime(&now);

    // Remove the newline character from the end of the string
    currentDate.pop_back();

    // Return the current date
    return currentDate;
}

/*
Generate a function named 'StringDateToTime' that transforms a date string into a time_t object.
Arguments:
- date: a string representing a date in the format "YYYY-MM-DD HH:MM:SS"
Returns:
- a time_t object representing the date and time
Exceptions:
- If the date string is invalid, the function throws an invalid_argument exception "Invalid date string".
Example:
std::string date = "2022-01-01 00:00:00";
std::time_t result = StringToTime(date);
*/
std::time_t StringDateToTime(const std::string &date)
{
    // Create a time struct and initialize it to zero
    std::tm time = {};

    // Create a string stream from the date string
    std::istringstream ss(date);

    // Parse the date string using the time struct
    ss >> std::get_time(&time, "%c");
    if (ss.fail())
    {
        throw std::invalid_argument("Invalid date string");
    }

    // Convert the time struct to a time_t object
    std::time_t timeObject = std::mktime(&time);

    // Return the time_t object
    return timeObject;
}
