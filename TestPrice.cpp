
#include "TestPrice.h"
/*********** Phase I- class Price ***********/

TEST(PriceTests, CTOR_Price) {
    Price p1(5);
    Price p2(5, 2);
    Price p3(-5, 2);
    Price p4(-5, -2);
    ASSERT_TRUE(p1.GetPrice() == 500);
    ASSERT_TRUE(p2.GetPrice() == 502);
    ASSERT_TRUE(p3.GetPrice() == -498);
    ASSERT_TRUE(p4.GetPrice() == -502);


}

TEST(PriceTests, assignmentOpertorPrice) {
    Price p1(5);
    Price p2(5, 2);
    p2 = p1;
    ASSERT_TRUE(p2.GetPrice() == p1.GetPrice());
    p1 = 6;
    ASSERT_TRUE(p1.GetPrice() == 600);


}

TEST(PriceTests, OpertorOverlodingPrice) {
    Price p1(5);
    Price p2(5, 2);

    ASSERT_TRUE(p2 != p1);
    ASSERT_TRUE(p1 == p1);
    ASSERT_TRUE(p2 >= p1);
    ASSERT_FALSE(p2 <= p1);


}

TEST(PriceTests, postfixPostfixIncrementOperatorPrice) {
    Price p1(5);
    ++p1;

    ASSERT_TRUE(p1.GetPrice() == 600);
    p1++;

    ASSERT_TRUE(p1.GetPrice() == 700);


}

TEST(PriceTests, postfixPostfixdecreaseOperatorPrice) {
    Price p1(5);
    --p1;

    ASSERT_TRUE(p1.GetPrice() == 400);
    p1--;

    ASSERT_TRUE(p1.GetPrice() == 300);


}

TEST(PriceTests, PlusOperators) {
    Price p1(5);
    Price p2(3);

    p1 += p2;
    ASSERT_TRUE(p1.GetPrice() == 800);


    p2 += 3;
    ASSERT_TRUE(p2.GetPrice() == 600);

    p2 = p1 + p1;
    ASSERT_TRUE(p2.GetPrice() == 1600);


    p1 = p1 + 2;
    ASSERT_TRUE(p1.GetPrice() == 1000);


}

TEST(PriceTests, MinusOperators) {
    Price p1(5);
    Price p2(3);

    p1 -= p2;
    ASSERT_TRUE(p1.GetPrice() == 200);


    p2 -= 3;
    ASSERT_TRUE(p2.GetPrice() == 0);
    p2 = 5;
    p2 = p2 - p1;
    ASSERT_TRUE(p2.GetPrice() == 300);


    p1 = p1 - 1;
    ASSERT_TRUE(p1.GetPrice() == 100);


}

TEST(PriceTests, MultiplicationOperator) {
    Price p1(5);
    Price p2(3);

    p1 *= p2;
    ASSERT_TRUE(p1.GetPrice() == 1500);


    p2 *= 3;
    ASSERT_TRUE(p2.GetPrice() == 900);

    p2 = p2 * p1;
    ASSERT_TRUE(p2.GetPrice() == 13500);


    p1 = p1 * 0;
    ASSERT_TRUE(p1.GetPrice() == 0);


}

TEST(PriceTests, DivideOperator) {
    Price p1(6);
    Price p2(3);

    p1 /= p2;


    ASSERT_TRUE(p1.GetPrice() == 200);

    p2 = 12;
    p2 /= 2;
    ASSERT_TRUE(p2.GetPrice() == 600);

    p2 = p2 / p1;
    std::cout << p2;

    ASSERT_TRUE(p2.GetPrice() == 300);
    p1 = 5;
    p2 = 2;
    p1 /= p2;
    ASSERT_TRUE(p1.GetPrice() == 250);

    p2 = 3;
    p2 = p2 / 3;
    ASSERT_TRUE(p2.GetPrice() == 100);
    p2 = p2 / 3;
    ASSERT_TRUE(p2.GetPrice() == 33);

}
TEST(PriceTests,ModuloOperator) {
    Price p1(6);
    Price p2(3);
    Price p3(4);


    p1 %= p3;
    ASSERT_TRUE(p1.GetPrice() == (6%4)*100);

    p1=6;
    p1 %= 4;
    ASSERT_TRUE(p1.GetPrice() == (6%4)*100);

    p1=10;
    p1=p1%4;
    ASSERT_TRUE(p1.GetPrice() == (10%4)*100);

    p1=10;
    p1=p1%p3;
    ASSERT_TRUE(p1.GetPrice() == (10%4)*100);

}

TEST(PriceTests, GetPriceDollar) {
    Price p1(5, 5);
    ASSERT_TRUE(p1.GetPriceDollar() == (double) 5.05);

}
/*********************************************
 *                                           *
 *  Phase II- test for class Template Price  *
 *                                           *
**********************************************/


TEST(TemplatePriceTests, CTOR_TemplatePrice) {
    TemplatePrice<int> p1(5);
    TemplatePrice<float> p2(5.5);
    TemplatePrice<float> p3(4.3, 2.1);
    TemplatePrice<double> p4(-5, -2);


    ASSERT_TRUE(p1.GetPrice() == 500);
    ASSERT_TRUE(p2.GetPrice() == (float) 550.0);
    /*ASSERT_TRUE(p3.GetTemplatePrice() == float() 432.1);*/
    ASSERT_TRUE(p4.GetPrice() == (double) -502);


}

TEST(TemplatePriceTests, GetPriceDollar) {
    TemplatePrice<int> p1(5, 5);
    TemplatePrice<float> p2(5.5);

    ASSERT_TRUE(p1.GetPriceDollar() == (double) 5.05);
    ASSERT_TRUE(p2.GetPriceDollar() == (double) 5.5);

}

TEST(TemplatePriceTests, assignmentOpertorPrice) {
    TemplatePrice<int> p1(5, 5);
    TemplatePrice<int> p2(5, 2);
    TemplatePrice<float> p3(5.1, 2);
    p2 = p1;
    p3 = p1;
    ASSERT_TRUE(p2.GetPrice() == p1.GetPrice());
    //   ASSERT_TRUE(p3.GetPrice() == p1.GetPrice());//todo: assigment operator to other type
    p1 = 6;
    ASSERT_TRUE(p1.GetPrice() == 600);


}

TEST(TemplatePriceTests, OpertorOverlodingPrice) {
    TemplatePrice<int> p1(5);
    TemplatePrice<int> p2(5, 2);
    TemplatePrice<float> p3(5.1, 2);
    TemplatePrice<int> p4(5);
    TemplatePrice<float> p5(5.1, 7);
    ASSERT_TRUE(p1 == p4);
    ASSERT_TRUE(p2 != p1);
    ASSERT_TRUE(p2 >= p1);
    ASSERT_FALSE(p2 <= p4);
    ASSERT_TRUE(p5 >= p3);


}

TEST(TemplatePriceTests, postfixPostfixIncrementOperatorPrice) {
    TemplatePrice<int> p1(5, 2);
    TemplatePrice<float> p2(5.1, 2);
    ++p1;
    ASSERT_TRUE(p1.GetPrice() == 602);
    p1++;
    ASSERT_TRUE(p1.GetPrice() == 702);

    p2++;
    ASSERT_TRUE(p2.GetPrice() == 612);


}

TEST(TemplatePriceTests, postfixPostfixDecreaseOperatorPrice) {
    TemplatePrice<int> p1(5, 2);
    TemplatePrice<float> p2(5.1, 2);
    --p1;
    ASSERT_TRUE(p1.GetPrice() == 402);
    p1--;
    ASSERT_TRUE(p1.GetPrice() == 302);

    p2--;
    ASSERT_TRUE(p2.GetPrice() == 412);
std::cout<<p1;

}