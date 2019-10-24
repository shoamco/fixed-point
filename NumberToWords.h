//
// Created by shoam on 10/24/19.
//

#ifndef CPP_FIXED_POINT_SHOAMCO_NUMBERTOWORDS_H
#define CPP_FIXED_POINT_SHOAMCO_NUMBERTOWORDS_H

#include <iostream>
#include <string>
using std::string;
const string EMPTY = "";
const string X[] = { EMPTY, "One ", "Two ", "Three ", "Four ", "Five ",
                     "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ",
                     "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
                     "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
const string Y[] = { EMPTY, EMPTY, "Twenty ", "Thirty ", "Forty ", "Fifty ",
                     "Sixty ", "Seventy ", "Eighty ", "Ninety " };
// Function to convert single digit or two digit number into words
inline string convert2digit(int n, string suffix)
{
    // if n is zero
    if (n == 0) {
        return EMPTY;
    }
    // split n if it is more than 19
    if (n > 19) {
        return Y[n / 10] + X[n % 10] + suffix;
    }
    else {
        return X[n] + suffix;
    }
}
// Function to convert a given number (max 9-digits) into words
inline string numberToWords(unsigned long long int n)
{
    // string to store word representation of given number
    string res;
    // this handles digits at ones & tens place
    res = convert2digit((n % 100), "");
    if (n > 100 && n % 100) {
        res = "and " + res;
    }
    // this handles digit at hundreds place
    res = convert2digit(((n / 100) % 10), "Hundred ") + res;
    // this handles digits at thousands & tens thousands place
    res = convert2digit(((n / 1000) % 100), "Thousand ") + res;
    // this handles digits at hundred thousands & one millions place
    res = convert2digit(((n / 100000) % 100), "Lakh, ") + res;
    // this handles digits at ten millions & hundred millions place
    res = convert2digit((n / 10000000) % 100, "Crore, ") + res;
    // this handles digits at ten millions & hundred millions place
    res = convert2digit((n / 1000000000) % 100, "Billion, ") + res;
    return res;
}
inline std::string digitsToWord(const std::string str, std::size_t startIndex, std::size_t endIndex)
{
    return str.substr(startIndex, endIndex);
}
#endif //CPP_FIXED_POINT_SHOAMCO_NUMBERTOWORDS_H
