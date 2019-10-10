
#include "TestPrice.h"
TEST(PriceTests, CTOR_Price) {
Price p1(5);
Price p2(5,2);
Price p3(-5,2);
ASSERT_TRUE(p1.GetPrice() == 500);
ASSERT_TRUE(p2.GetPrice() == 502);


}
TEST(PriceTests, assignmentOpertorPrice) {
    Price p1(5);
    Price p2(5,2);
 p2=p1;
    ASSERT_TRUE(p2.GetPrice() == p1.GetPrice());



}