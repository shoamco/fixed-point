

#ifndef CPP_FIXED_POINT_SHOAMCO_TEMPLATETemplatePrice_H
#define CPP_FIXED_POINT_SHOAMCO_TEMPLATETemplatePrice_H

#define REPRESENTATION_CENT 100

#include <iostream>
template <typename T>
class TemplatePrice {
public:
    TemplatePrice( T dollar = 0,  T cent = 0);

    T GetTemplatePrice() const;

    TemplatePrice &operator=(const TemplatePrice &other);

    TemplatePrice &operator=( T dollar);

    /* TemplatePrice &operator=( T dollar);*/
    friend std::ostream &operator<<(std::ostream &stream, const TemplatePrice &templatePrice);

    TemplatePrice &operator+(const TemplatePrice &other);
/*
    // Declare prefix and postfix increment operators.
    TemplatePrice &operator++();       // Prefix increment operator.
    TemplatePrice operator++( T);     // Postfix increment operator.

    // Declare prefix and postfix decrement operators.
    TemplatePrice &operator--();       // Prefix decrement operator.
    TemplatePrice operator--( T);     // Postfix decrement operator
    */


private:
     T price;
};
template<typename T>
inline TemplatePrice<T>::TemplatePrice( T dollar,  T cent) : price(dollar * REPRESENTATION_CENT + cent) {

}

template <typename T>
 inline   T TemplatePrice<T>::GetTemplatePrice() const {
    return   price;
}
/*
inline TemplatePrice &TemplatePrice::operator=(const TemplatePrice &other) {
    if (this != &other) {
        this->TemplatePrice = other.TemplatePrice;
    }
    return *this;
}

inline TemplatePrice &TemplatePrice::operator=( T dollar) {
    this->TemplatePrice = dollar * REPRESENTATION_CENT;
    return *this;
}


inline bool operator==(TemplatePrice &TemplatePrice1, TemplatePrice &TemplatePrice2) {
    return TemplatePrice1 == TemplatePrice2;

}

inline bool operator<=(TemplatePrice &TemplatePrice1, TemplatePrice &TemplatePrice2) {
    return TemplatePrice1 <= TemplatePrice2;

}

inline bool operator>=(TemplatePrice &TemplatePrice1, TemplatePrice &TemplatePrice2) {
    return TemplatePrice1 >= TemplatePrice2;

}

inline bool operator<(TemplatePrice &TemplatePrice1, TemplatePrice &TemplatePrice2) {
    return TemplatePrice1 < TemplatePrice2;
}

inline bool operator>(TemplatePrice &TemplatePrice1, TemplatePrice &TemplatePrice2) {
    return TemplatePrice1 > TemplatePrice2;
}

inline std::ostream &operator<<(std::ostream &stream, const TemplatePrice &TemplatePrice1) {
    return stream << "TemplatePrice: " << TemplatePrice1 << std::endl;

}

inline TemplatePrice &TemplatePrice::operator++() {
    TemplatePrice+=REPRESENTATION_CENT;
    return *this;
}

inline TemplatePrice TemplatePrice::operator++( T) {
    TemplatePrice temp = *this;
    ++*this;
    return temp;
}


inline TemplatePrice &TemplatePrice::operator--() {
    TemplatePrice-=REPRESENTATION_CENT;
    return *this;
}

inline TemplatePrice TemplatePrice::operator--( T) {
    TemplatePrice temp = *this;
    --*this;
    return temp;
}
*/

#endif //CPP_FIXED_POINT_SHOAMCO_TEMPLATETemplatePrice_H
