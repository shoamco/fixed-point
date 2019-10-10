
#include "TestPrice.h"
/*********** Phase I- class Price ***********/

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

/*********** Phase II- class Template Price ***********/

TEST(TemplatePriceTests, CTOR_TemplatePrice) {
    TemplatePrice <int>p1(5);
  TemplatePrice <float>p2(5.5);
    TemplatePrice <float>p3(4.3f,2.0f);
    TemplatePrice <double >p4(-5,-2);
    ASSERT_TRUE(p1.GetTemplatePrice() == 500);

    ASSERT_TRUE(p2.GetTemplatePrice() == (float) 550.0);
   /*ASSERT_TRUE(p3.GetTemplatePrice() == (float) 630.0);*/
  ASSERT_TRUE(p4.GetTemplatePrice() == (double)-502);


}