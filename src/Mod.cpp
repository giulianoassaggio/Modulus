#include <iostream>
#include <cctype>
#include <string>

std::string calculateModulus(const std::string& number, int base, int divisor) {
    int remainder = 0;

    for (char digit : number) {
        int currentDigit;
        if (isdigit(digit)) {
            currentDigit = digit - '0';
        } else {
            currentDigit = toupper(digit) - 'A' + 10;
        }

        remainder = (remainder * base + currentDigit) % divisor;
    }

    std::string result;
    while (remainder > 0) {
        int digit = remainder % base;
        char baseDigit = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        result = baseDigit + result;
        remainder /= base;
    }

    return (result.empty() ? "0" : result);
}

int main() {
    std::string number;
    int base, divisor;

    std::cout << "Enter the number: ";
    std::cin >> number;

    std::cout << "Enter the base: ";
    std::cin >> base;

    std::cout << "Enter the divisor: ";
    std::cin >> divisor;

    std::string result = calculateModulus(number, base, divisor);
    std::cout << "Modulus result: " << result << std::endl;

    return 0;
}
