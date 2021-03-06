//
// Created by shoam on 10/13/19.
//

#ifndef CPP_FIXED_POINT_SHOAMCO_FIXEDPOINT_H
#define CPP_FIXED_POINT_SHOAMCO_FIXEDPOINT_H

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>
#include "FixedPointException.h"
#include <iomanip>
#include <locale>




/************************************************************************************************************
                             class FixedPoint

 * @tparam T -the data type (for example:int unsigned short int...)
 * @tparam SIZE -the  accuracy of the number,(for example:(1, 5) SIZE=2->1.05 )


    ************   member class:  *********************************

    T integer_part -for the integer part
    int fractional_part-for the fractional part ,9-digit accuracy after the point
    bool sign; //true if is Positive else false
    long int data;//hold all the fixed size in inger-to make the calculations easier

**********************************************************************************************************************


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
#define  BASE 10

template<unsigned int SIZE, typename T = int>
class FixedPoint {
public:
    static const unsigned int Precision = SIZE;
    typedef T theType;

    FixedPoint(T integer_part, int fractional_part);

    FixedPoint(const FixedPoint<SIZE, T> &other);

    T GetIntegerPart();

    long int GetData();

    unsigned int GetFractionalPart();

    bool GetSing();

    std::string asString();

    int getStringSize();

    unsigned int GetPrecision();


//
//    long long int GetDataInFormatFixedPoint() const;
//
    FixedPoint<SIZE, T> &operator=(const FixedPoint<SIZE, T> &other);

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


//    FixedPoint<SIZE, T> operator+(const FixedPoint<SIZE, T> &other);
//
//    FixedPoint<SIZE, T> operator+(T val);

    /***operators -***/
    FixedPoint<SIZE, T> &operator-=(const FixedPoint<SIZE, T> &other);

//    FixedPoint<SIZE, T> &operator-=(T val);

//    FixedPoint<SIZE, T> operator-(const FixedPoint<SIZE, T> &other);
//
//    FixedPoint<SIZE, T> operator-(T val);
    /***    operators *    ***/
    FixedPoint<SIZE, T> &operator*=(const FixedPoint<SIZE, T> &other);

    /***operators /   ***/
    FixedPoint<SIZE, T> &operator/=(const FixedPoint<SIZE, T> &other);


private:

    T integer_part;// the integer part
    int fractional_part; //the fractional part,9-digit accuracy after the point
    bool sign; //true if is Positive else false todo:  represent '-'  when  integer_part =0 and sign is Negative, for example -0.1,
    long int data;//todo: type of int64_t


    /*asString,getStringSize is inline private static function(sto handel with namespace pollution), and  FixedPoint its friend*/

    friend std::string asString(T integer_part, int fractional_part, unsigned int precision);

    friend int getStringSize(T integer_part, unsigned int precision);


};

template<unsigned int SIZE, typename T>
inline unsigned int FixedPoint<SIZE, T>::GetPrecision() {
    return Precision;
}

/***    template metaprogramming    ***/
template<int n,int base=BASE>
struct pow_base_n {
    static int const value = base* pow_base_n<n - 1,base>::value;
};


/**  template specialization for Conditions recursion when n=0*/
template<>
struct pow_base_n<0> {
    static int const value = 1;
};



template<unsigned int SIZE, typename T>
inline
FixedPoint<SIZE, T>::FixedPoint(T integer_part, int fractional_part) :integer_part(integer_part),
                                                                      fractional_part(fractional_part),
                                                                      sign(integer_part >= 0),
                                                                      data(integer_part * pow_base_n<SIZE,BASE>::value +
                                                                           fractional_part) {
}
/***
         handle with  code-bloating:

  to avoid a code-bloating we make the function  not depend on the template
 argument,by calling to global function with the arguments that nit depend in the type template
  and In addition we make them functions inline-which means that the compiler just replaces it by the
direct call ,Plus, there are no more  copies (for all type of template)-since it does not exist in the final code.


 the inline  internal function -  depend only the type template,
and get all the argument that not depend in the template
 we dont do it global to avoid namespace pollution


 to handle with the Problem namespace pollution:(that the 'global' function can cause)
  1.  Make them static it the file
  2. Hide the  it in a deeper namespace
  3. Make it private static in a class, and make FixedPoint its friend

 * ***/
namespace namespace_details {/* add deeper namespace*/
    template<typename T>
    inline static std::string asString(T integer_part, int fractional_part, unsigned int precision) {
        std::ostringstream convert1;
        std::ostringstream convert2;
        convert1 << integer_part;
        convert2 <<  std::setfill('0')<<std::setw(precision)<<fractional_part;
        return convert1.str() +  "."+ convert2.str(); // set 'Result' to the contents of the stream

    }
}


template<unsigned int SIZE, typename T>
inline std::string FixedPoint<SIZE, T>::asString() {

    return namespace_details::asString(integer_part, fractional_part, SIZE); //call global function with the arguments

}

template<typename T>
inline int countDigit(T n) {
    if (n == 0)
        return 0;
    return 1 + countDigit(n / 10);
}

namespace namespace_details {/* add deeper namespace*/
    template<typename T>
    inline static int getStringSize(T integer_part, unsigned int precision) {

        return countDigit(integer_part) + precision;

    }
}

template<unsigned int SIZE, typename T>
inline int FixedPoint<SIZE, T>::getStringSize() {
    return namespace_details::getStringSize(integer_part, SIZE);
}

template<unsigned int SIZE, typename T>
inline
FixedPoint<SIZE, T>::FixedPoint(const FixedPoint<SIZE, T> &other):integer_part(other.integer_part),
                                                                  fractional_part(other.fractional_part),
                                                                  sign(other.sign), data(other.data) {

}


template<unsigned int SIZE2, typename U>
inline std::ostream &operator<<(std::ostream &stream, const FixedPoint<SIZE2, U> &fixedPoint) {
    return stream
            << "integer_part : " << fixedPoint.integer_part
            << " fractional_part " << fixedPoint.fractional_part
            << " sign: " << fixedPoint.sign
            << " data: " << fixedPoint.data
            << " all number" << fixedPoint.integer_part << "." << std::setfill('0') << std::setw(SIZE2)
            << fixedPoint.fractional_part << std::endl;

}

template<unsigned int SIZE, typename T>
inline long int FixedPoint<SIZE, T>::GetData() {
    return data;
}

template<unsigned int SIZE, typename T>
inline T FixedPoint<SIZE, T>::GetIntegerPart() {
    return integer_part;
}

template<unsigned int SIZE, typename T>
inline unsigned int FixedPoint<SIZE, T>::GetFractionalPart() {
    return fractional_part;
}

template<unsigned int SIZE, typename T>
inline bool FixedPoint<SIZE, T>::GetSing() {
    return sign;
}

template<unsigned int SIZE, typename T>

inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator=(const FixedPoint<SIZE, T> &other) {
    integer_part = other.integer_part;
    fractional_part = other.fractional_part;
    sign = other.sign;
    return *this;
}

//inline bool checkOverflowFractional(const int &num, unsigned int size) {
//    return num >=  pow_base_n<SIZE,BASE>::value;
//}

/***operators + ***/
template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator+=(const FixedPoint<SIZE, T> &other) {
    data += other.data;
    integer_part = data / static_cast<long int>( pow_base_n<SIZE,BASE>::value);
    fractional_part = data % static_cast<long int>( pow_base_n<SIZE,BASE>::value);
    if (sign != integer_part > 0) {//if the sing is change
        fractional_part *= -1;
        sign = !sign;
    }

    return *this;
}

/***operators - ***/
template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator-=(const FixedPoint<SIZE, T> &other) {
    data -= other.data;
//    std::cout<<"data  "<<data<<"pow_base_n(SIZE) " <<pow_base_n(SIZE) <<" data/pow_base_n(SIZE) "<< data/static_cast<int>(pow_base_n(SIZE))<<"  ,  "<<data%static_cast<int>(pow_base_n(SIZE))<<std::endl;

    integer_part = data / static_cast<long int>( pow_base_n<SIZE,BASE>::value);

    fractional_part = data % static_cast<long int>( pow_base_n<SIZE,BASE>::value);
    if (sign != integer_part > 0) {//if the sing is change
        fractional_part *= -1;
        sign = !sign;
    }

    return *this;
}

///***operators * ***/
template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator*=(const FixedPoint<SIZE, T> &other) {
    data *= other.data;
    data /= pow_base_n<SIZE,BASE>::value;
//    std::cout << "data  " << data << "pow_base_n(SIZE) " << pow_base_n<SIZE>((BASE * 2)) << " data/pow_base_n(SIZE) "<< data /static_cast<int>(pow_base_n<SIZE>((BASE * 2)) << "  ,  " << data % static_cast<int>(pow_base_n<SIZE>((BASE*2)) << std::endl;
//    std::cout<<" data / static_cast<int>(pow_base_n<SIZE>((BASE * 2))"<< data / static_cast<int>(pow_base_n<SIZE>((BASE * 2));
    integer_part = data / static_cast<long int>(pow_base_n<SIZE,BASE>::value);

    fractional_part = data % static_cast<long int>(pow_base_n<SIZE,BASE>::value);
    if (sign != integer_part > 0) {//if the sing is change
        fractional_part *= -1;
        sign = !sign;
    }

    return *this;
}


///***operators * ***/
template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator/=(const FixedPoint<SIZE, T> &other) {

    data = (data *pow_base_n<SIZE*2,BASE>::value) / (other.data * pow_base_n<SIZE,BASE>::value);

    integer_part = data / static_cast<long int>(pow_base_n<SIZE,BASE>::value);
    fractional_part = data % static_cast<long int>(pow_base_n<SIZE,BASE>::value);


    if (sign != integer_part >= 0) {
        std::cout << "in if sign" << sign << "integer_part > 0" << (integer_part > 0) << std::endl;
        fractional_part *= -1;
        sign = !sign;
    }

    return *this;
}

/***   Boolan operators  ***/
template<unsigned int SIZE, typename T>
inline bool operator==(FixedPoint<SIZE, T> &fixedpoint1, FixedPoint<SIZE, T> &fixedpoint2) {
    return fixedpoint1.GetData() == fixedpoint2.GetData();

}

template<unsigned int SIZE, typename T>
inline bool operator!=(FixedPoint<SIZE, T> &fixedpoint1, FixedPoint<SIZE, T> &fixedpoint2) {
    return fixedpoint1.GetData() != fixedpoint2.GetData();

}

template<unsigned int SIZE, typename T>
inline bool operator<=(FixedPoint<SIZE, T> &fixedpoint1, FixedPoint<SIZE, T> &fixedpoint2) {
    return fixedpoint1.GetData() <= fixedpoint2.GetData();

}

template<unsigned int SIZE, typename T>
inline bool operator>=(FixedPoint<SIZE, T> &fixedpoint1, FixedPoint<SIZE, T> &fixedpoint2) {
    return fixedpoint1.GetData() >= fixedpoint2.GetData();

}

template<unsigned int SIZE, typename T>
inline bool operator<(FixedPoint<SIZE, T> &fixedpoint1, FixedPoint<SIZE, T> &fixedpoint2) {
    return fixedpoint1.GetData() < fixedpoint2.GetData();
}

template<unsigned int SIZE, typename T>
inline bool operator>(FixedPoint<SIZE, T> &fixedpoint1, FixedPoint<SIZE, T> &fixedpoint2) {
    return fixedpoint1.GetData() > fixedpoint2.GetData();
}

#endif //CPP_FIXED_POINT_SHOAMCO_FIXEDPOINT_H
