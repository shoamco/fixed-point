

#ifndef CPP_FIXED_POINT_SHOAMCO_PRICE_H
#define CPP_FIXED_POINT_SHOAMCO_PRICE_H

#define REPRESENTATION_CENT 100
#include <iostream>
class Price {
public:
    Price(int dollar=0,int cent=0);
    int GetPrice() const;
    Price &operator=(const Price &other);
   /* Price &operator=(int dollar);*/

private:
    int price;
};
inline Price::Price(int dollar,int cent):price(dollar*REPRESENTATION_CENT + cent){

}
inline int Price::GetPrice()const {
    return price ;
}
inline  Price &Price::operator=(const Price &other){
    if(this!=&other){
        this->price=other.price;
    }
    return *this;
}

#endif //CPP_FIXED_POINT_SHOAMCO_PRICE_H
