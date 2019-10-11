

#ifndef CPP_FIXED_POINT_SHOAMCO_PRICE_H
#define CPP_FIXED_POINT_SHOAMCO_PRICE_H

#define REPRESENTATION_CENT 100

#include <iostream>

class Price {
public:
    Price(int dollar = 0, int cent = 0);

    int GetPrice() const;
    double GetPriceDollar() const;

    Price &operator=(const Price &other);

    Price &operator=(int dollar);

    /* Price &operator=(int dollar);*/
    friend std::ostream &operator<<(std::ostream &stream, const Price &price1);

    Price &operator+(const Price &other);

    // Declare prefix and postfix increment operators.
    Price &operator++();       // Prefix increment operator.
    Price operator++(int);     // Postfix increment operator.

    // Declare prefix and postfix decrement operators.
    Price &operator--();       // Prefix decrement operator.
    Price operator--(int);     // Postfix decrement operator


private:
    int price;
};

inline Price::Price(int dollar, int cent) : price(dollar * REPRESENTATION_CENT + cent) {

}

inline int Price::GetPrice() const {
    return price;
}
inline double Price::GetPriceDollar() const{
    return ((double )price)/REPRESENTATION_CENT;
}

inline Price &Price::operator=(const Price &other) {
    if (this != &other) {
        price = other.price;
    }
    return *this;
}

inline Price &Price::operator=(int dollar) {
   price = dollar * REPRESENTATION_CENT;
    return *this;
}

/* operator overload methods*/
inline bool operator==(Price &price1, Price &price2) {
    return price1.GetPrice() == price2.GetPrice();

}
inline bool operator!=(Price &price1, Price &price2) {
    return price1.GetPrice()!= price2.GetPrice();

}
inline bool operator<=(Price &price1, Price &price2) {
    return price1.GetPrice() <= price2.GetPrice();

}

inline bool operator>=(Price &price1, Price &price2) {
    return price1.GetPrice() >= price2.GetPrice();

}

inline bool operator<(Price &price1, Price &price2) {
    return price1.GetPrice() < price2.GetPrice();
}

inline bool operator>(Price &price1, Price &price2) {
    return price1.GetPrice() > price2.GetPrice();
}

inline std::ostream &operator<<(std::ostream &stream, const Price &price1) {
    return stream << "price: " << price1 << std::endl;

}

inline Price &Price::operator++() {
    price+=REPRESENTATION_CENT;
    return *this;
}

inline Price Price::operator++(int) {
    Price temp = *this;
    ++*this;
    return temp;
}


inline Price &Price::operator--() {
    price-=REPRESENTATION_CENT;
    return *this;
}

inline Price Price::operator--(int) {
    Price temp = *this;
    --*this;
    return temp;
}

#endif //CPP_FIXED_POINT_SHOAMCO_PRICE_H
