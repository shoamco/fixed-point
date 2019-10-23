
#include "TestPrice.h"

/*********************************************
 *                                           *
 *       Phase I- test for class  Price      *
 *                                           *
**********************************************/

TEST(PriceTests, CTOR_Price) {
    Price p1(5);
    Price p2(5, 2);
    Price p3(-5, 2);
    Price p4(-5, -2);
    Price p5(p4);//copy CTOR

    ASSERT_TRUE(p1.GetPrice() == 500);
    ASSERT_TRUE(p2.GetPrice() == 502);
    ASSERT_TRUE(p3.GetPrice() == -498);
    ASSERT_TRUE(p4.GetPrice() == -502);
    ASSERT_TRUE(p5.GetPrice() == -502);


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

TEST(PriceTests, ModuloOperator) {
    Price p1(6);
    Price p2(3);
    Price p3(4);


    p1 %= p3;
    ASSERT_TRUE(p1.GetPrice() == (6 % 4) * 100);

    p1 = 6;
    p1 %= 4;
    ASSERT_TRUE(p1.GetPrice() == (6 % 4) * 100);

    p1 = 10;
    p1 = p1 % 4;
    ASSERT_TRUE(p1.GetPrice() == (10 % 4) * 100);

    p1 = 10;
    p1 = p1 % p3;
    ASSERT_TRUE(p1.GetPrice() == (10 % 4) * 100);

}

TEST(PriceTests, GetPriceDollar) {
    Price p1(5, 5);
    ASSERT_TRUE(p1.GetPriceDollar() == (double) 5.05);

}

TEST(PriceTests, UnaryOperator) {
    Price p1(6);

    std::cout << -p1;
    ASSERT_TRUE(p1.GetPrice() == 600);
    p1 = -p1;
    ASSERT_TRUE(p1.GetPrice() == -600);

}



/*********************************************
 *                                           *
 *  Phase II- test for class Template Price  *
 *                                           *
**********************************************/


TEST(TemplatePriceTests, CTOR_TemplatePrice) {
    TemplatePrice<int> p1(5);
    TemplatePrice<float> p2(5.5f);
    TemplatePrice<float> p3(4.3f, 2.1f);
    TemplatePrice<double> p4(-5, -2);
    TemplatePrice<double> p5(p4);//copy CTOR


    ASSERT_TRUE(p1.GetPrice() == 500);
    ASSERT_TRUE(p2.GetPrice() == (float) 550.0);
//    ASSERT_TRUE(p3.GetPrice() ==  432.1f); todo:fix
    ASSERT_TRUE(p4.GetPrice() == (double) -502);
    ASSERT_TRUE(p5.GetPrice() == (double) -502);


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
    TemplatePrice<float> p3(5.1f, 2.0f);
    p2 = p1;

    ASSERT_TRUE(p2.GetPrice() == p1.GetPrice());
    //   ASSERT_TRUE(p3.GetPrice() == p1.GetPrice());//todo: assigment operator to other type
    p1 = 6;
    ASSERT_TRUE(p1.GetPrice() == 600);


}

TEST(TemplatePriceTests, OpertorOverlodingPrice) {
    TemplatePrice<int> p1(5);
    TemplatePrice<int> p2(5, 2);
    TemplatePrice<float> p3(5.1f, 2.0f);
    TemplatePrice<int> p4(5);
    TemplatePrice<float> p5(5.1f, 7.0f);
    ASSERT_TRUE(p1 == p4);
    ASSERT_TRUE(p2 != p1);
    ASSERT_TRUE(p2 >= p1);
    ASSERT_FALSE(p2 <= p4);
    ASSERT_TRUE(p5 >= p3);


}

TEST(TemplatePriceTests, postfixPostfixIncrementOperatorPrice) {
    TemplatePrice<int> p1(5, 2);
    TemplatePrice<float> p2(5.1f, 2.0f);
    ++p1;
    ASSERT_TRUE(p1.GetPrice() == 602);
    p1++;
    ASSERT_TRUE(p1.GetPrice() == 702);

    p2++;
    ASSERT_TRUE(p2.GetPrice() == 612);


}

TEST(TemplatePriceTests, postfixPostfixDecreaseOperatorPrice) {
    TemplatePrice<int> p1(5, 2);
    TemplatePrice<float> p2(5.1f, 2.0f);
    --p1;
    ASSERT_TRUE(p1.GetPrice() == 402);
    p1--;
    ASSERT_TRUE(p1.GetPrice() == 302);

    p2--;
    ASSERT_TRUE(p2.GetPrice() == 412);
    std::cout << p1.GetPrice();


}

TEST(TemplatePriceTests, PlusOperators) {
    TemplatePrice<int> p1(5);
    TemplatePrice<int> p2(3);

    p1 += p2;


    ASSERT_TRUE(p1.GetPrice() == 800);


    p2 += 3;
    ASSERT_TRUE(p2.GetPrice() == 600);

    p2 = p1 + p1;
    ASSERT_TRUE(p2.GetPrice() == 1600);


    p1 = p1 + 2;
    ASSERT_TRUE(p1.GetPrice() == 1000);


}

TEST(TemplatePriceTests, MinusOperators) {
    TemplatePrice<int> p1(5);
    TemplatePrice<int> p2(3);
    TemplatePrice<float> p3(5.2f);
    TemplatePrice<float> p4(3.1f);

    p1 -= p2;
    ASSERT_TRUE(p1.GetPrice() == 200);

    p3 -= p4;
    ASSERT_TRUE(p3.GetPrice() == 210);

    p2 -= 3;
    ASSERT_TRUE(p2.GetPrice() == 0);
    p2 = 5;
    p2 = p2 - p1;
    ASSERT_TRUE(p2.GetPrice() == 300);


    p1 = p1 - 1;
    ASSERT_TRUE(p1.GetPrice() == 100);


}


TEST(TemplatePriceTests, MultiplicationOperator) {
    TemplatePrice<int> p1(5);
    TemplatePrice<int> p2(3);

    p1 *= p2;
    ASSERT_TRUE(p1.GetPrice() == 1500);


    p2 *= 3;
    ASSERT_TRUE(p2.GetPrice() == 900);

    p2 = p2 * p1;
    ASSERT_TRUE(p2.GetPrice() == 13500);


    p1 = p1 * 0;
    ASSERT_TRUE(p1.GetPrice() == 0);


}

TEST(TemplatePriceTests, DivideOperator) {
    TemplatePrice<int> p1(6);
    TemplatePrice<int> p2(3);

    p1 /= p2;


    ASSERT_TRUE(p1.GetPrice() == 200);

    p2 = 12;
    p2 /= 2;
    ASSERT_TRUE(p2.GetPrice() == 600);

    p2 = p2 / p1;
//    std::cout << p2;

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
    std::cout << p1;
}


TEST(TemplatePriceTests, ModuloOperator) {
    TemplatePrice<int> p1(6);
    TemplatePrice<int> p2(3);
    TemplatePrice<int> p3(4);


    p1 %= p3;
    ASSERT_TRUE(p1.GetPrice() == (6 % 4) * 100);

    p1 = 6;
    p1 %= 4;
    ASSERT_TRUE(p1.GetPrice() == (6 % 4) * 100);

    p1 = 10;
    p1 = p1 % 4;
    ASSERT_TRUE(p1.GetPrice() == (10 % 4) * 100);

    p1 = 10;
    p1 = p1 % p3;
    ASSERT_TRUE(p1.GetPrice() == (10 % 4) * 100);

}

TEST(TemplatePriceTests, UnaryOperator) {
    TemplatePrice<int> p1(6);

    std::cout << -p1;
    ASSERT_TRUE(p1.GetPrice() == 600);
    p1 = -p1;
    ASSERT_TRUE(p1.GetPrice() == -600);

}

/*********************************************
 *                                           *
 *  Phase III- test for class FixedPoint *
 *                                           *
**********************************************/


TEST(FixPointTests, CTOR_FixPoint) {
    FixedPoint<2, int> p1(5,4);
    FixedPoint<2> p2(p1);//copy CTOR
    std::cout << p1;
    ASSERT_TRUE(p1.GetIntegerPart() == 5 && p1.GetFractionalPart()==4 );
    ASSERT_TRUE(p2.GetIntegerPart() == 5 && p2.GetFractionalPart()==4 );



}

TEST(FixPointTests, assignmentOpertorPrice) {
    FixedPoint<2, int> p1(5,4);;
    FixedPoint<2, int> p2(6,777);

    std::cout << p1;

    std::cout << p2;

    p2 = p1;
    std::cout << p2;

    ASSERT_TRUE(p2.GetIntegerPart() == 5 && p2.GetFractionalPart()==4 );


}


TEST(FixPointTests, PlusOperators) {
    FixedPoint<2, int> p1(3,40);
    FixedPoint<2, int> p2(5,90);
    FixedPoint<2, int> p3(1,1);
    FixedPoint<2, int> p4(3,40);
    std::cout <<"p1  "<< p1;

    p1 += p3;
    std::cout <<"p1  "<< p1;
    ASSERT_TRUE(p1.GetIntegerPart() == 4 && p1.GetFractionalPart()==41 );
//    p4 += p2;
//    std::cout <<"p4  "<< p4;
//    ASSERT_TRUE(p4.GetIntegerPart() == 9 && p1.GetFractionalPart()==30 );


//
//
//    ASSERT_TRUE(p1.GetDataFixedPoint() == 800);
//    ASSERT_TRUE(p1.GetDataInFormatFixedPoint() == 8);
//
//
//    p2 += 3;
//
//    ASSERT_TRUE(p2.GetDataFixedPoint() == 600);
//    ASSERT_TRUE(p2.GetDataInFormatFixedPoint() == 6);
//
//
//    ASSERT_ANY_THROW(p2 = p1 + p1;);//exception overflow p2=1600 not in scale of 100
//    ASSERT_ANY_THROW(p1 = p1 + 2;);//exception overflow p1=1000 not in scale of 100
//    std::cout << "before +0.1"<<p4;
//p4+=0.1f;
//    std::cout << "after +0.1"<<p4;
//    ASSERT_TRUE(p4.GetDataInFormatFixedPoint() == 2.45);

}
//
//
//TEST(FixPointTests, MinusOperators) {
//    FixedPoint<2, int> p1(5);
//    FixedPoint<2, int> p2(3);
//    FixedPoint<2, float> p3(5.52f);
//    FixedPoint<2, float> p4(2.36f);
//
//
//    std::cout << p3;
//    std::cout << p4;
//    p1 -= p2;
//    std::cout << p1;
//
//    ASSERT_TRUE(p1.GetDataFixedPoint() == 200);
//    ASSERT_TRUE(p1.GetDataInFormatFixedPoint() == 2);
//
//
//    p2 -= 3;
//
//    ASSERT_TRUE(p2.GetDataFixedPoint() == 0);
//    ASSERT_TRUE(p2.GetDataInFormatFixedPoint() == 0);
//
//    p1=6;
//    std::cout << p1;
//    std::cout << p2;
//
//    std::cout << p2;
//    p2 -=  p1;
//    std::cout << p2;
//    ASSERT_ANY_THROW(   p2 -=  p1;);//exception overflow p2=-1200 not in scale of 100
////    ASSERT_ANY_THROW(p1 = p1 - 12;);//exception overflow p1=-1000 not in scale of 100
////
////    p4-=0.1f;
////
////    ASSERT_TRUE(p4.GetDataInFormatFixedPoint() == 5.42);
//
//}