

#ifndef CPP_FIXED_POINT_SHOAMCO_TEMPLATETemplatePrice_H
#define CPP_FIXED_POINT_SHOAMCO_TEMPLATETemplatePrice_H

#define REPRESENTATION_CENT 100

#include <iostream>
template <typename T>
class TemplatePrice {
public:
    TemplatePrice( T dollar = 0,  T cent = 0);

    T GetPrice() const;
    template <typename T2 >
    TemplatePrice<T> &operator=(const TemplatePrice<T2>  &other);
    TemplatePrice<T> &operator=(const TemplatePrice<T>  &other);

    TemplatePrice<T> &operator=( T dollar);
    double GetPriceDollar() const;

    /* TemplatePrice &operator=( T dollar);*/
    friend std::ostream &operator<<(std::ostream &stream, const TemplatePrice<T> &templatePrice);

    TemplatePrice<T> &operator+(const TemplatePrice<T> &other);
/*
    // Declare prefix and postfix increment operators.
    TemplatePrice<T> &operator++();       // Prefix increment operator.
    TemplatePrice<T> operator++( T);     // Postfix increment operator.

    // Declare prefix and postfix decrement operators.
    TemplatePrice<T> &operator--();       // Prefix decrement operator.
    TemplatePrice<T> operator--( T);     // Postfix decrement operator
*/


private:
     T price;
};
template<typename T>
inline TemplatePrice<T>::TemplatePrice( T dollar,  T cent) : price(dollar * REPRESENTATION_CENT + cent) {

}

template <typename T>
 inline   T TemplatePrice<T>::GetPrice() const {
    return   price;
}
template <typename T>
inline double TemplatePrice<T>::GetPriceDollar() const{
    return ((double )price)/REPRESENTATION_CENT;
}

template <typename T >
template <typename T2 >
inline TemplatePrice<T> &TemplatePrice<T>::operator=(const TemplatePrice<T2> &other) {


   /*  price = static_cast<T>(other.price);*///todo:casting from T2 TO t

    return *this;
}
template <typename T >
inline TemplatePrice<T> &TemplatePrice<T>::operator=(const TemplatePrice<T> &other) {
    price = static_cast<T>(other.price);
    return *this;
}
template <typename T>
inline TemplatePrice<T> &TemplatePrice<T>::operator=( T dollar) {
    this->price = dollar * REPRESENTATION_CENT;
    return *this;
}

template <typename T>
inline bool operator==(TemplatePrice<T> &templatePrice1, TemplatePrice<T> &templatePrice2) {
    return templatePrice1.GetPrice() == templatePrice2.GetPrice();

}

template <typename T>
inline bool operator!=(TemplatePrice<T> &templatePrice1, TemplatePrice<T> &templatePrice2) {
    return templatePrice1.GetPrice() != templatePrice2.GetPrice();

}
template <typename T>
inline bool operator<=(TemplatePrice<T> &templatePrice1, TemplatePrice<T> &templatePrice2) {
    return templatePrice1.GetPrice() <= templatePrice2.GetPrice();

}
template <typename T>
inline bool operator>=(TemplatePrice<T> &templatePrice1, TemplatePrice<T> &templatePrice2) {
    return templatePrice1.GetPrice() >= templatePrice2.GetPrice();

}
template <typename T>
inline bool operator<(TemplatePrice<T> &templatePrice1, TemplatePrice<T> &templatePrice2) {
    return templatePrice1.GetPrice() < templatePrice2.GetPrice();
}
template <typename T>
inline bool operator>(TemplatePrice<T> &templatePrice1, TemplatePrice<T> &templatePrice2) {
    return templatePrice1.GetPrice() > templatePrice2.GetPrice();
}
template <typename T>
inline std::ostream &operator<<(std::ostream &stream, const TemplatePrice<T> &templatePrice1) {
    return stream << "TemplatePrice: " <<  templatePrice1.price<< std::endl;

}
/*
template <typename T>
inline TemplatePrice<T> &TemplatePrice<T>::operator++() {
    price+=REPRESENTATION_CENT;
    return *this;
}
template <typename T>
inline TemplatePrice<T> TemplatePrice<T>::operator++( T) {
    TemplatePrice temp = *this;
    ++*this;
    return temp;
}

template <typename T>
inline TemplatePrice<T> &TemplatePrice<T>::operator--() {
    price-=REPRESENTATION_CENT;
    return *this;
}
template <typename T>
inline TemplatePrice<T> TemplatePrice<T>::operator--( T) {
    TemplatePrice temp = *this;
    --*this;
    return temp;
}

*/
#endif //CPP_FIXED_POINT_SHOAMCO_TEMPLATETemplatePrice_H
