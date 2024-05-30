#include "BigNumber.hpp"
#include <iostream>

const int BigNumber::max_digit = 20;

BigNumber::BigNumber() {
    this->digit = new int[BigNumber::max_digit]();
}

BigNumber::BigNumber(int number) {
    this->digit = new int[BigNumber::max_digit];
    for (int i = 0; i < BigNumber::max_digit; i++) {
        this->digit[i] = number % 10;
        number /= 10;
    }
}

BigNumber::BigNumber(std::string aVeryBigNumber) {
    this->digit = new int[BigNumber::max_digit];
    int strSize = aVeryBigNumber.size();
    for (int i = 0; i < strSize; i++) {
        this->digit[i] = aVeryBigNumber[strSize - 1 - i] - '0';
    }
}

BigNumber::BigNumber(const BigNumber& bn) {
    this->digit = new int[BigNumber::max_digit];
    for (int i = 0; i < BigNumber::max_digit; i++) {
        this->digit[i] = bn[i];
    }
}

int BigNumber::getMaxDigit() {
    return BigNumber::max_digit;
}

void BigNumber::setDigit(int i, int digit) {
    this->digit[i] = digit;
}

int& BigNumber::operator[](int i) {
    return this->digit[i];
}

int BigNumber::operator[](int i) const {
    return this->digit[i];
}

BigNumber::~BigNumber() {
    delete[] this->digit;
}

bool BigNumber::operator==(const BigNumber& other) {
    for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
        if (this->digit[i] != other[i]) {
            return false;
        }
    }
    return true;
}

bool BigNumber::operator<(const BigNumber& other) {
    for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
        if (this->digit[i] < other[i]) {
            return true;
        } else if (this->digit[i] > other[i]) {
            return false;
        }
    }
    return false; // Both numbers are equal
}

bool BigNumber::operator>(const BigNumber& other) {
    for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
        if (this->digit[i] > other[i]) {
            return true;
        } else if (this->digit[i] < other[i]) {
            return false;
        }
    }
    return false; // Both numbers are equal
}

BigNumber BigNumber::operator+(const BigNumber& other) {
    BigNumber result;
    int carry = 0;
    for (int i = 0; i < BigNumber::getMaxDigit(); i++) {
        int sum = this->digit[i] + other[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
    return result;
}
