//
// Created by shoam on 10/13/19.
//

#ifndef CPP_FIXED_POINT_SHOAMCO_FIXEDPOINT_H
#define CPP_FIXED_POINT_SHOAMCO_FIXEDPOINT_H

#include <iostream>
#include <math.h>
//template<typename T = int, unsigned int SIZE = 4, typename Type = signed>
//template<typename T = int, unsigned int SIZE=2>


//T-type

/**********************************************
 *             class FixedPoint
 *
  |S-sing bit|I-integer part bit|-F-fractional part bit|

 * @tparam T -: type
 * @tparam I :The integer part bit
 * @tparam F :The fractional part bit
 *
 * ********************************************/
class FixedPoint {
public:
    FixedPoint(T number);
//    FixedPoint(T dollar = 0, T cent = 0, T pip = 0);
    FixedPoint(const FixedPoint<T,SIZE> &other);

    T GetPrice() const;

    template<typename T2>
    FixedPoint<T,SIZE> &operator=(const FixedPoint<T2> &other);

    FixedPoint<T,SIZE>&operator=(const FixedPoint<T,SIZE> &other);

    FixedPoint<T,SIZE> &operator=(T dollar);

    double GetPriceDollar() const;

    /* TemplatePrice &operator=( T dollar);*/
    template<typename U>
    friend std::ostream &operator<<(std::ostream &stream, const FixedPoint<U> &price1);
//
///****Binary arithmetic operators***/
//
//
//
//    // Declare prefix and postfix increment operators.
//    FixedPoint<T> &operator++();       // Prefix increment operator.
//    FixedPoint<T> operator++( int);     // Postfix increment operator.
//
//    // Declare prefix and postfix decrement operators.
//    FixedPoint<T> &operator--();       // Prefix decrement operator.
//    FixedPoint<T> operator--( int);     // Postfix decrement operator
//     /*unary -*/
//     FixedPoint<T> operator-() const;
//
//    /***operators + ***/
//    FixedPoint<T> &operator+=(const TemplatePrice<T> &other);
//
//    FixedPoint<T>  &operator+=(int val);
//
//
//    TemplatePrice<T> operator+(const   TemplatePrice<T> &other);
//    TemplatePrice<T> operator+(int val);
//
//    /***operators -***/
//    TemplatePrice<T> &operator-=(const   TemplatePrice<T> &other);
//
//    TemplatePrice<T> &operator-=(int val);
//
//    TemplatePrice<T> operator-(const   TemplatePrice<T> &other);
//
//    TemplatePrice<T> operator-(int val);
//
///***   operators *   ***/
//
//    TemplatePrice<T> &operator*=(const   TemplatePrice<T> &other);
//
//    TemplatePrice<T> &operator*=(int val);
//
//    TemplatePrice<T> operator*(const   TemplatePrice<T> &other);
//
//    TemplatePrice<T> operator*(int val);
//
/////***   operators /   ***/
//
//    TemplatePrice<T> &operator/=(const   TemplatePrice<T> &other);
//
//    TemplatePrice<T> &operator/=(int val);
//
//    TemplatePrice<T> operator/(const   TemplatePrice<T> &other);
//
//    TemplatePrice<T> operator/(int val);
//
//    /***   operators %   ***/
//
//    TemplatePrice<T> &operator%=(const   TemplatePrice<T> &other);
//
//    TemplatePrice<T> &operator%=(int val);
//
//    TemplatePrice<T> operator%(const   TemplatePrice<T> &other);
//
//    TemplatePrice<T> operator%(int val);
//


private:
    T price;
};
template<typename T, unsigned int SIZE>
inline
FixedPoint<T, SIZE>::FixedPoint(T number) : price(number*pow( 10,SIZE )) {
}
//template<typename T, unsigned int SIZE>
//inline
//FixedPoint<T, SIZE>::FixedPoint(T dollar, T cent, T pip) : price(dollar * (10 ^ (SIZE)) + cent * (10 ^ (SIZE - 2))+pip) {
//
//}

template<typename T, unsigned int SIZE>
inline FixedPoint<T, SIZE>::FixedPoint(const FixedPoint<T,SIZE> &other) : price(other.price) {

}

template<typename T, unsigned int SIZE>
inline T FixedPoint<T,SIZE>::GetPrice() const {
    return price;
}

#endif //CPP_FIXED_POINT_SHOAMCO_FIXEDPOINT_H
