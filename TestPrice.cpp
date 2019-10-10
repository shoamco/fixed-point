
#include "TestPrice.h"
TEST(PriceTests, CTOR_Price) {
Price p1(5);
Price p2(5,2);
Price p3(-5,2);
Price p4(-5,-2);
ASSERT_TRUE(p1.GetPrice() == 500);
ASSERT_TRUE(p2.GetPrice() == 502);
ASSERT_TRUE(p3.GetPrice() == -498);
ASSERT_TRUE(p4.GetPrice() == -502);


}
TEST(PriceTests, assignmentOpertorPrice) {
    Price p1(5);
    Price p2(5,2);
    p2=p1;
    ASSERT_TRUE(p2.GetPrice() == p1.GetPrice());
    p1=6;
    ASSERT_TRUE(p1.GetPrice() == 600);


}
TEST(PriceTests, OpertorOverlodingPrice) {
    Price p1(5);
    Price p2(5,2);

    ASSERT_TRUE(p2.GetPrice() != p1.GetPrice());
    ASSERT_TRUE(p1.GetPrice() == p1.GetPrice());
    ASSERT_TRUE(p2.GetPrice() >= p1.GetPrice());
    ASSERT_FALSE(p2.GetPrice() <= p1.GetPrice());



}
TEST(PriceTests, postfixPostfixIncrementOperatorPrice ) {
    Price p1(5);
   ++p1;

    ASSERT_TRUE(p1.GetPrice() ==600);
    p1++;

    ASSERT_TRUE(p1.GetPrice() ==700);


}