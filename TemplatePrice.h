

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
    friend std::ostream &operator<<(std::ostream &stream, const TemplatePrice<T> &price1);



    // Declare prefix and postfix increment operators.
    TemplatePrice<T> &operator++();       // Prefix increment operator.
    TemplatePrice<T> operator++( int);     // Postfix increment operator.

    // Declare prefix and postfix decrement operators.
    TemplatePrice<T> &operator--();       // Prefix decrement operator.
    TemplatePrice<T> operator--( int);     // Postfix decrement operator
/****Binary arithmetic operators***/

    /***operators + ***/
    TemplatePrice<T> &operator+=(const TemplatePrice<T> &other);

    TemplatePrice<T>  &operator+=(int val);


    TemplatePrice<T> operator+(const   TemplatePrice<T> &other);
    TemplatePrice<T> operator+(int val);

    /***operators -***/
    TemplatePrice<T> &operator-=(const   TemplatePrice<T> &other);

    TemplatePrice<T> &operator-=(int val);

    TemplatePrice<T> operator-(const   TemplatePrice<T> &other);

    TemplatePrice<T> operator-(int val);

/***   operators *   ***/

    TemplatePrice<T> &operator*=(const   TemplatePrice<T> &other);

    TemplatePrice<T> &operator*=(int val);

    TemplatePrice<T> operator*(const   TemplatePrice<T> &other);

    TemplatePrice<T> operator*(int val);

///***   operators /   ***/

    TemplatePrice<T> &operator/=(const   TemplatePrice<T> &other);

    TemplatePrice<T> &operator/=(int val);

    TemplatePrice<T> operator/(const   TemplatePrice<T> &other);

    TemplatePrice<T> operator/(int val);

    /***   operators %   ***/

    TemplatePrice<T> &operator%=(const   TemplatePrice<T> &other);

    TemplatePrice<T> &operator%=(int val);

    TemplatePrice<T> operator%(const   TemplatePrice<T> &other);

    TemplatePrice<T> operator%(int val);



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
inline std::ostream &operator<<(std::ostream &stream, const TemplatePrice<T> &price1) {
    return stream << "price: " << price1.price << std::endl;

}

template <typename T>
inline TemplatePrice<T> &TemplatePrice<T>::operator++() {
    price+=REPRESENTATION_CENT;
    return *this;
}
template <typename T>
inline TemplatePrice<T> TemplatePrice<T>::operator++( int) {
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
inline TemplatePrice<T> TemplatePrice<T>::operator--( int) {
    TemplatePrice temp = *this;
    --*this;
    return temp;
}


/***operators + ***/
template <typename T>
inline TemplatePrice<T> &TemplatePrice<T>::operator+=(const TemplatePrice<T> &other) {
    price += other.price;
    return *this;
}
template <typename T>
inline TemplatePrice<T> &TemplatePrice<T>::operator+=(int val) {
    price += val * REPRESENTATION_CENT;
    return *this;
}
template <typename T>
inline TemplatePrice<T> TemplatePrice<T>::operator+(const TemplatePrice<T> &other) {
    TemplatePrice<T> temp = *this;

    temp.price += other.price;
    return temp;

}
template <typename T>
inline TemplatePrice<T> TemplatePrice<T>::operator+(int val) {
    TemplatePrice<T> temp = *this;
    temp.price += val * REPRESENTATION_CENT;

    return temp;


}
/***operators - ***/

template <typename T>
inline TemplatePrice<T> &TemplatePrice<T>::operator-=(const TemplatePrice<T> &other) {
    price -= other.price;
    return *this;
}
template <typename T>
inline TemplatePrice<T> &TemplatePrice<T>::operator-=(int val) {
    price -= val * REPRESENTATION_CENT;
    return *this;
}

template <typename T>
inline TemplatePrice<T> TemplatePrice<T>::operator-(const TemplatePrice<T> &other) {
    TemplatePrice<T> temp = *this;

    temp.price -= other.price;
    return temp;

}

template <typename T>
inline TemplatePrice<T> TemplatePrice<T>::operator-(int val) {
    TemplatePrice<T> temp = *this;
    temp.price -= val * REPRESENTATION_CENT;

    return temp;
}

/***operators * ***/

template <typename T>
inline TemplatePrice<T>  &TemplatePrice<T> ::operator*=(const TemplatePrice<T>  &other) {
    price *= other.price;
    price /= REPRESENTATION_CENT;
    return *this;
}

template <typename T>
inline TemplatePrice<T>  &TemplatePrice<T> ::operator*=(int val) {
    price *= val * REPRESENTATION_CENT;
    price /= REPRESENTATION_CENT;
    return *this;
}

template <typename T>
inline TemplatePrice<T>  TemplatePrice<T> ::operator*(const TemplatePrice<T>  &other) {
    TemplatePrice<T>  temp = *this;
    temp.price *= other.price;
    temp.price /= REPRESENTATION_CENT;
    return temp;

}

template <typename T>
inline TemplatePrice<T>  TemplatePrice<T> ::operator*(int val) {
    TemplatePrice<T>  temp = *this;
    temp.price *= val * REPRESENTATION_CENT;
    temp.price /= REPRESENTATION_CENT;
    return temp;
}

/***operators / ***/

template <typename T>
inline TemplatePrice<T>  &TemplatePrice<T>::operator/=(const TemplatePrice<T>  &other) {
    price = (price * REPRESENTATION_CENT )/ (other.price);
    return *this;
}

template <typename T>
inline TemplatePrice<T>  &TemplatePrice<T> ::operator/=(int val) {
    price = (price * REPRESENTATION_CENT) / (val * REPRESENTATION_CENT);
    return *this;
}

template <typename T>
inline TemplatePrice<T>  TemplatePrice<T> ::operator/(const TemplatePrice<T>  &other) {
    TemplatePrice<T>  temp = *this;
    temp.price = (temp.price * REPRESENTATION_CENT )/ (other.price);

    return temp;

}

template <typename T>
inline TemplatePrice<T>  TemplatePrice<T> ::operator/(int val) {
    TemplatePrice<T>  temp = *this;
    temp.price = (temp.price * REPRESENTATION_CENT )/ (val * REPRESENTATION_CENT);
    return temp;
}

/***operators % ***/

template <typename T>
inline  TemplatePrice<T>  & TemplatePrice<T> ::operator%=(const  TemplatePrice<T>  &other) {
    price = (price  )% (other.price);

    return *this;
}

template <typename T>
inline  TemplatePrice<T>  & TemplatePrice<T> ::operator%=(int val) {
    price = (price ) % (val * REPRESENTATION_CENT);

    return *this;
}

template <typename T>
inline  TemplatePrice<T>   TemplatePrice<T> ::operator%(const  TemplatePrice<T>  &other) {
    TemplatePrice<T>  temp = *this;
    temp.price = (temp.price  )% (other.price);
    return temp;

}

template <typename T>
inline  TemplatePrice<T>   TemplatePrice<T> ::operator%(int val) {
    TemplatePrice<T>  temp = *this;
    temp.price = (temp.price  )%(val * REPRESENTATION_CENT);
    return temp;
}
#endif //CPP_FIXED_POINT_SHOAMCO_TEMPLATETemplatePrice_H
