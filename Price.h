

#ifndef CPP_FIXED_POINT_SHOAMCO_PRICE_H
#define CPP_FIXED_POINT_SHOAMCO_PRICE_H

#define REPRESENTATION_CENT 100

#include <iostream>

class Price {
public:
    Price(int dollar = 0, int cent = 0);
    Price(const Price &other);

    int GetPrice() const;

    double GetPriceDollar() const;

    Price &operator=(const Price &other);

    Price &operator=(int dollar);

    /* Price &operator=(int dollar);*/
    friend std::ostream &operator<<(std::ostream &stream, const Price &price1);

    /****Binary arithmetic operators***/
    Price operator-() const;/*unary -*/
    /***operators + ***/
    Price &operator+=(const Price &other);

    Price &operator+=(int val);

    Price operator+(const Price &other);

    Price operator+(int val);

    /***operators -***/
    Price &operator-=(const Price &other);

    Price &operator-=(int val);

    Price operator-(const Price &other);

    Price operator-(int val);

/***   operators *   ***/

    Price &operator*=(const Price &other);

    Price &operator*=(int val);

    Price operator*(const Price &other);

    Price operator*(int val);

/***   operators /   ***/

    Price &operator/=(const Price &other);

    Price &operator/=(int val);

    Price operator/(const Price &other);

    Price operator/(int val);

    /***   operators %   ***/

    Price &operator%=(const Price &other);

    Price &operator%=(int val);

    Price operator%(const Price &other);

    Price operator%(int val);


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
inline Price::Price(const Price &other) : price(other.price) {

}

inline int Price::GetPrice() const {
    return price;
}

inline double Price::GetPriceDollar() const {
    return ((double) price) / REPRESENTATION_CENT;
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

/****Binary arithmetic operators***/
inline bool operator==(Price &price1, Price &price2) {
    return price1.GetPrice() == price2.GetPrice();

}

inline bool operator!=(Price &price1, Price &price2) {
    return price1.GetPrice() != price2.GetPrice();

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
    return stream << "price: " << price1.price << std::endl;

}

inline Price &Price::operator++() {
    price += REPRESENTATION_CENT;
    return *this;
}

inline Price Price::operator++(int) {
    Price temp = *this;
    ++*this;
    return temp;
}


inline Price &Price::operator--() {
    price -= REPRESENTATION_CENT;
    return *this;
}

inline Price Price::operator--(int) {
    Price temp = *this;
    --*this;
    return temp;
}

/***operators + ***/
inline Price &Price::operator+=(const Price &other) {
    price += other.price;
    return *this;
}

inline Price &Price::operator+=(int val) {
    price += val * REPRESENTATION_CENT;
    return *this;
}

inline Price Price::operator+(const Price &other) {
    Price temp = *this;

    temp.price += other.price;
    return temp;

}

inline Price Price::operator+(int val) {
    Price temp = *this;
    temp.price += val * REPRESENTATION_CENT;

    return temp;


}

/***operators - ***/
inline Price &Price::operator-=(const Price &other) {
    price -= other.price;
    return *this;
}

inline Price &Price::operator-=(int val) {
    price -= val * REPRESENTATION_CENT;
    return *this;
}

inline Price Price::operator-(const Price &other) {
    Price temp = *this;

    temp.price -= other.price;
    return temp;

}

inline Price Price::operator-(int val) {
    Price temp = *this;
    temp.price -= val * REPRESENTATION_CENT;

    return temp;
}

/***operators * ***/
inline Price &Price::operator*=(const Price &other) {
    price *= other.price;
    price /= REPRESENTATION_CENT;
    return *this;
}

inline Price &Price::operator*=(int val) {
    price *= val * REPRESENTATION_CENT;
    price /= REPRESENTATION_CENT;
    return *this;
}

inline Price Price::operator*(const Price &other) {
    Price temp = *this;
    temp.price *= other.price;
    temp.price /= REPRESENTATION_CENT;
    return temp;

}

inline Price Price::operator*(int val) {
    Price temp = *this;
    temp.price *= val * REPRESENTATION_CENT;
    temp.price /= REPRESENTATION_CENT;
    return temp;
}

/***operators / ***/
inline Price &Price::operator/=(const Price &other) {
    price = (price * REPRESENTATION_CENT )/ (other.price);
    return *this;
}

inline Price &Price::operator/=(int val) {
    price = (price * REPRESENTATION_CENT) / (val * REPRESENTATION_CENT);
    return *this;
}

inline Price Price::operator/(const Price &other) {
    Price temp = *this;
    temp.price = (temp.price * REPRESENTATION_CENT )/ (other.price);

    return temp;

}

inline Price Price::operator/(int val) {
    Price temp = *this;
    temp.price = (temp.price * REPRESENTATION_CENT )/ (val * REPRESENTATION_CENT);
    return temp;
}


/***operators % ***/
inline Price &Price::operator%=(const Price &other) {
    price = (price  )% (other.price);

    return *this;
}

inline Price &Price::operator%=(int val) {
    price = (price ) % (val * REPRESENTATION_CENT);
    std::cout<<"in %= val"<<*this;
    return *this;
}

inline Price Price::operator%(const Price &other) {
    Price temp = *this;
    temp.price = (temp.price  )% (other.price);
    return temp;

}

inline Price Price::operator%(int val) {
    Price temp = *this;
    temp.price = (temp.price  )%(val * REPRESENTATION_CENT);
    std::cout<<"in % val "<<temp;
    return temp;
}
/***  unary -  ***/
inline Price Price::operator-()const{
    Price temp =*this;
    temp.price = price*(-1);
    return temp;
}
#endif //CPP_FIXED_POINT_SHOAMCO_PRICE_H
