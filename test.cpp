#include "gtest/gtest.h"

#include "op.hpp"
#include "Mult.hpp"
#include "Sub.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Pow.hpp"
#include "MockClasses.hpp"

TEST(Rand1, OpPositive) {
    Op* test = new Op(rand() % 100);
    EXPECT_TRUE(test->evaluate() >= 0 && test->evaluate() < 100);
}

TEST(Rand2, RandNumber) { 
    Op* test1 = new Op(rand() % 100);
    EXPECT_TRUE(test1->evaluate() >= 0 && test1->evaluate() < 100);
}

TEST(Mult1, OpNegativeAndPositive) {
    Base* test1 = new NegativeOp();
    Base* test2 = new PositiveOp();
    Base* mult = new Mult(test1, test2);
    EXPECT_EQ(mult->evaluate(),- 38.5);
    EXPECT_EQ(mult->stringify(), "(-7.0*5.5)");
}

TEST(Mult2, OpZeroAndNegative) {
    Base* test1 = new ZeroOp();
    Base* test2 = new NegativeOp();
    Base* mult = new Mult(test1, test2);    
    EXPECT_EQ(mult->evaluate(), 0);
    EXPECT_EQ(mult->stringify(), "(0.0*-7.0)");
}

TEST(Div1, OpNegativeAndZeroBottom) {
    Base* test1 = new NegativeOp();
    Base* test2 = new ZeroOp();
    Base* div = new Div(test1, test2);
    EXPECT_EQ(div->evaluate(), 0);
    EXPECT_EQ(div->stringify(), "Undefined");
}

TEST(Div2, OpZeroTopAndPositive) {
    Base* test1 = new ZeroOp();
    Base* test2 = new PositiveOp();
    Base* div = new Div(test1, test2);
    EXPECT_EQ(div->evaluate(),0);
    EXPECT_EQ(div->stringify(), "(0.0/5.5)");
}

TEST(Div3, OpPos2AndNeg) {
    Base* test1 = new NegativeOp();
    Base* test2 = new PositiveOp2();
    Base* div = new Div(test1, test2);    
    EXPECT_EQ(div->evaluate(), -1.75);
    EXPECT_EQ(div->stringify(), "(-7.0/4.0)");
}

TEST(Sub1, OpZeroAndNegative) {
    Base* test1 = new ZeroOp();
    Base* test2 = new NegativeOp();
    Base* sub = new Sub(test1, test2);    
    EXPECT_EQ(sub->evaluate(), 7.0);
    EXPECT_EQ(sub->stringify(), "(0.0--7.0)");
}

TEST(Sub2, OpZeroAndPositive) {
    Base* test1 = new ZeroOp();
    Base* test2 = new PositiveOp();
    Base* sub = new Sub(test1, test2);    
    EXPECT_EQ(sub->evaluate(), -5.5);
    EXPECT_EQ(sub->stringify(), "(0.0-5.5)");
}

TEST(Sub3, OpPosAndNeg) {
    Base* test1 = new PositiveOp();
    Base* test2 = new NegativeOp();
    Base* sub = new Sub(test1, test2);    
    EXPECT_EQ(sub->evaluate(), 12.5);
    EXPECT_EQ(sub->stringify(), "(5.5--7.0)");
}

TEST(Sub4, OpNegAndPos) {
    Base* test1 = new NegativeOp();
    Base* test2 = new PositiveOp();
    Base* sub = new Sub(test1, test2);    
    EXPECT_EQ(sub->evaluate(), -12.5);
    EXPECT_EQ(sub->stringify(), "(-7.0-5.5)");
}

TEST(Add1, OpPosAndNegative) {
    Base* test1 = new PositiveOp();
    Base* test2 = new NegativeOp();
    Base* add = new Add(test1, test2);    
    EXPECT_EQ(add->evaluate(), -1.5);
    EXPECT_EQ(add->stringify(), "(5.5+-7.0)");
}

TEST(Pow1, OpNegAndZero) {
    Base* test1 = new NegativeOp();
    Base* test2 = new ZeroOp();
    Base* pow = new Pow(test1, test2);    
    EXPECT_EQ(pow->evaluate(), 1);
    EXPECT_EQ(pow->stringify(), "(-7.0**0.0)");
}

TEST(Pow2, OpPosAndPos2) {
    Base* test1 = new PositiveOp();
    Base* test2 = new PositiveOp2();
    Base* pow = new Pow(test1, test2);    
    EXPECT_EQ(pow->evaluate(), 915.0625);
    EXPECT_EQ(pow->stringify(), "(5.5**4.0)");
}

TEST(Pow3, OpNegAndPos2) {
    Base* test1 = new NegativeOp();
    Base* test2 = new PositiveOp2();
    Base* pow = new Pow(test1, test2);    
    EXPECT_EQ(pow->evaluate(), 2401);
    EXPECT_EQ(pow->stringify(), "(-7.0**4.0)");
}

TEST(CombinedTests, Combined) {
    Op* test1 = new Op(1);
    Op* test2 = new Op(2);
    Op* test3 = new Op(3);
    Op* test4 = new Op(4);
    Op* test5 = new Op(5);

    Base* pow = new Pow(test1, test2); 
    Base* div = new Div(test4, test2);
    Base* add = new Add(test5, pow);
    Base* sub = new Sub(add, test3);
    Base* mult = new Mult(sub, div); 
	
    EXPECT_EQ(add->evaluate(), 6.0 );
    EXPECT_EQ(add->stringify(), "((5.000000)+((1.000000)**(2.000000)))");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}