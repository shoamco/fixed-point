//
// Created by shoam on 10/13/19.
//

#ifndef CPP_FIXED_POINT_SHOAMCO_FIXEDPOINT_H
#define CPP_FIXED_POINT_SHOAMCO_FIXEDPOINT_H

#include <iostream>
#include <math.h>
#include "FixedPointException.h"

#define  BASE 10
//template<typename T = int, unsigned int SIZE = 4, typename Type = signed>
//template<typename T = int, unsigned int SIZE=2>


//T-type
//template<typename T , unsigned char I,unsigned char F>
/**********************************************
 *             class FixedPoint
  |S-sing bit|I-integer part bit|-F-fractional part bit|

 * @tparam T -: type
 * @tparam I :The integer part bit
 * @tparam F :The fractional part bit
 *
 * ********************************************/



/************************************************************************************************************
                             class FixedPoint

 * @tparam T -the data type (for example:int unsigned short int...)
 * @tparam SIZE -the scale

 fixed-point data type is essentially an integer that is scaled by an implicit specific factor determined by the type
 *  For example, the value 1.23 can be represented as 1230 in a fixed-point data type with scaling factor of 1/1000
    and the value 1,230,000 can be represented as 1230 with a scaling factor of 1000

 *   Unlike floating-point data types, the scaling factor is the same for all values of the same type ,
    and does not change during the entire computation.


 *   To add/subtract: it is sufficient to add or subtract the underlying
    integers, and keep their common scaling factor,The result can be exactly represented in the same type(as long as no
    overflow occurs)
    for example:
    1.23 + 2.43 ==> 123/100 + 243/100 ==>  (123+243)/100 ==> 366/100 = 3.66


 * To multiply two fixed-point numbers, it suffices to multiply the two underlying integers, and assume that the scaling
   factor of the result is the product of their scaling factors ,the result may have to be rounded
   (in this case the result may have to be rounded, and overflow may occur)
   for example:
    1.23 * 2.43 ==>123/100 * 243/100 ==>  (123*243)/(100*100) ==> 29889 /1000 ==> rounded 298/100 =2.89

 * To divide two fixed-point numbers: divide the two underlying integers, and divide the scaling
   factor,for a more accurate result multiply the first by the scale\SIZE.
   the result may have to be rounded
   (in this case the result may have to be rounded, and overflow may occur)
   for example:
    4.52 / 1.25 ==>(452/100) / (125/100) ==> (for a more accurate result multiply the first by the scale)
    (45200/10000) / (125/100) ==>  45200/125 =361.6   (1/10000  / 1/100 ) =100 ==> 361.6/100 ==>
    rounded  361/100 =3.62

 * *************************************************************************************************************/
template<unsigned int SIZE, typename T = int>
class FixedPoint {
public:
    FixedPoint(T number);

    FixedPoint(const FixedPoint<SIZE, T> &other);

    int GetDataFixedPoint() const;

    size_t GetScale() const;

    double GetDataInFormatFixedPoint() const;

    FixedPoint<SIZE, T> &operator=(const FixedPoint<SIZE, T> &other);

    FixedPoint<SIZE, T> &operator=(T dollar);

    template<unsigned int SIZE2, typename U>
    friend std::ostream &operator<<(std::ostream &stream, const FixedPoint<SIZE2, U> &fixedPoint);
/****Binary arithmetic operators***/


    // Declare prefix and postfix increment operators.
    FixedPoint<SIZE, T> &operator++();       // Prefix increment operator.
    FixedPoint<SIZE, T> operator++(int);     // Postfix increment operator.

    // Declare prefix and postfix decrement operators.
    FixedPoint<SIZE, T> &operator--();       // Prefix decrement operator.
    FixedPoint<SIZE, T> operator--(int);     // Postfix decrement operator
    /*unary -*/
    FixedPoint<SIZE, T> operator-() const;

    /***operators + ***/
    FixedPoint<SIZE, T> &operator+=(const FixedPoint<SIZE, T> &other);

    FixedPoint<SIZE, T> &operator+=(T val);

    FixedPoint<SIZE, T> operator+(const FixedPoint<SIZE, T> &other);

    FixedPoint<SIZE, T> operator+(T val);

    /***operators -***/
    FixedPoint<SIZE, T> &operator-=(const   FixedPoint<SIZE, T> &other);

    FixedPoint<SIZE, T> &operator-=(T val);

    FixedPoint<SIZE, T> operator-(const    FixedPoint<SIZE, T> &other);

    FixedPoint<SIZE, T> operator-(T val);

private:

    int data;// fixed-point data type is an integer
    size_t scale;

};

template<unsigned int SIZE, typename T>
inline
FixedPoint<SIZE, T>::FixedPoint(T num) : data(static_cast<int>(num * pow(BASE, SIZE))), scale(pow(BASE, SIZE)) {
}

template<unsigned int SIZE, typename T>
inline
FixedPoint<SIZE, T>::FixedPoint(const FixedPoint<SIZE, T> &other):data(other.data), scale(other.scale) {

}

template<unsigned int SIZE, typename T>
inline int FixedPoint<SIZE, T>::GetDataFixedPoint() const {
    return data;

}

template<unsigned int SIZE, typename T>
inline size_t FixedPoint<SIZE, T>::GetScale() const {
    return scale;
}

template<unsigned int SIZE, typename T>
inline double FixedPoint<SIZE, T>::GetDataInFormatFixedPoint() const {
    return static_cast<double >(data) / scale;

}

template<unsigned int SIZE, typename T>

inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator=(const FixedPoint<SIZE, T> &other) {
    data = other.data;
    return *this;
}

template<unsigned int SIZE, typename T>

inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator=(T val) {
    this->data = static_cast<int>(val * scale);
    return *this;
}

template<unsigned int SIZE2, typename U>
inline std::ostream &operator<<(std::ostream &stream, const FixedPoint<SIZE2, U> &fixedPoint) {
    return stream << "fixedPoint data: " << fixedPoint.data << "  scaling factor: 1/" << pow(BASE, SIZE2)
                  << " fixed point format: "<<fixedPoint.GetDataInFormatFixedPoint() << std::endl;

}

inline bool checkOverflow(const int &num, unsigned int size) {
    return num >= pow(BASE, size + 1) || num<= -1*pow(BASE, size + 1) ;//for signed data
}

/***operators + ***/
template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator+=(const FixedPoint<SIZE, T> &other) {
    data += other.data;
    if (checkOverflow(data, SIZE))//todo: rounding
//        data /= 10;//round
        throw OverflowFixedPointException();

    return *this;
}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator+=(T val) {
    data += val * scale;
    if (checkOverflow(data, SIZE))//todo: rounding
//        data /= 10;//round
        throw OverflowFixedPointException();
    return *this;
}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator+(const FixedPoint<SIZE, T> &other) {
    FixedPoint<SIZE, T> temp = *this;
    temp.data += other.data;
    if (checkOverflow(temp.data, SIZE))//todo: rounding
//        temp.data /= 10;
        throw OverflowFixedPointException();
    return temp;

}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator+(T val) {
    FixedPoint<SIZE, T> temp = *this;
    temp.data += val * scale;
    if (checkOverflow(temp.data, SIZE))//todo: rounding
//        temp.data /= 10;
        throw OverflowFixedPointException();
    return temp;


}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator++() {
    data+=SIZE;
    return *this;
}
template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator++( int) {
    FixedPoint<SIZE, T> temp = *this;
    ++*this;
    return temp;
}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator--() {
    data-=SIZE;
    return *this;
}
template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator--( int) {
    FixedPoint<SIZE, T> temp = *this;
    --*this;
    return temp;
}
/***operators - ***/
template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator-=(const FixedPoint<SIZE, T> &other) {
    data -= other.data;
    if (checkOverflow(data, SIZE))//todo: rounding
//        data /= 10;//round
        throw OverflowFixedPointException();

    return *this;
}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator-=(T val) {
    data -= val * scale;
    if (checkOverflow(data, SIZE))//todo: rounding
//        data /= 10;//round
        throw OverflowFixedPointException();
    return *this;
}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator-(const FixedPoint<SIZE, T> &other) {
    FixedPoint<SIZE, T> temp = *this;
    temp.data -= other.data;
    if (checkOverflow(temp.data, SIZE))//todo: rounding
        temp.data /= 10;

    return temp;

}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator-(T val) {
    FixedPoint<SIZE, T> temp = *this;
    temp.data -= val * scale;
    if (checkOverflow(temp.data, SIZE))//todo: rounding
        throw OverflowFixedPointException();
    return temp;


}

#endif //CPP_FIXED_POINT_SHOAMCO_FIXEDPOINT_H
