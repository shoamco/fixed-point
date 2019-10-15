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
//template<typename T , unsigned char I,unsigned char F>
/**********************************************
 *             class FixedPoint
  |S-sing bit|I-integer part bit|-F-fractional part bit|

 * @tparam T -: type
 * @tparam I :The integer part bit
 * @tparam F :The fractional part bit
 *
 * ********************************************/


template< unsigned int SIZE ,typename T = int>
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

class FixedPoint {
public:
    FixedPoint(T number);

//    FixedPoint(T dollar = 0, T cent = 0, T pip = 0);
    FixedPoint(const FixedPoint< SIZE ,T> &other);

    int GetDataFixedPoint() const;
    double GetDataInFormatFixedPoint() const;



    FixedPoint<SIZE ,T> &operator=(const FixedPoint<SIZE ,T> &other);

    FixedPoint<SIZE ,T> &operator=(T dollar);

    double GetPriceDollar() const;

    FixedPoint<SIZE ,T> GetNumberFixedPoint() const;

    /* TemplatePrice &operator=( T dollar);*/
//    template<typename U>
//    friend std::ostream &operator<<(std::ostream &stream, const FixedPoint<U> &price1);

private:

    int data;// fixed-point data type is an integer

};

template<unsigned int SIZE ,typename T>
inline
FixedPoint<SIZE ,T>::FixedPoint(T num) : data(static_cast<int>(num*pow( 10,SIZE ))) {
}
template<unsigned int SIZE ,typename T>
inline int FixedPoint<SIZE ,T>::GetDataFixedPoint()const{
    return data;

}
template<unsigned int SIZE ,typename T>
inline double FixedPoint<SIZE ,T>:: GetDataInFormatFixedPoint() const{
    return static_cast<double >(data)/ pow( 10,SIZE );

}

#endif //CPP_FIXED_POINT_SHOAMCO_FIXEDPOINT_H
