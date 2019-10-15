

#ifndef CPP_FIXED_POINT_SHOAMCO_FIXEDPOINTEXCEPTION_H
#define CPP_FIXED_POINT_SHOAMCO_FIXEDPOINTEXCEPTION_H

#include <iostream>


class FixedPointException : public std::runtime_error {
public:
    FixedPointException(const std::string &message) : std::runtime_error(message) {}
};

class OverflowFixedPointException : public FixedPointException {
public:
    OverflowFixedPointException() : FixedPointException("Overflow!(from the scale )") {}
};

class SizeFixedPointException : public FixedPointException {
public:
    SizeFixedPointException() : FixedPointException("The size  bit out of rang.") {}
};

#endif //CPP_FIXED_POINT_SHOAMCO_FIXEDPOINTEXCEPTION_H
