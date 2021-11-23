#include "gtest/gtest.h"

#include "op.hpp"
#include "Mult.hpp"
#include "Sub.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Pow.hpp"
#include "Rand.hpp"
#include "concreteVisitor.hpp"
#include "iterator.hpp"
#include "iterator.cpp"
#include "visitor.hpp"

using namespace std;

TEST(Iterator, Add) {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* add = new Add(three, two);

    concreteVisitor* v = new concreteVisitor();
    string latex = v->PrintLateX(add);
    EXPECT_EQ("(3.000000 + 2.000000)", add->stringify());
    EXPECT_EQ(5, add->evaluate());
    EXPECT_EQ("${({3.000000}+{2.000000})}$", latex);
}

TEST(Iterator, Mult) {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);
    
    concreteVisitor* v = new concreteVisitor();
    string latex = v->PrintLateX(mult);
    EXPECT_EQ("(7.000000 * 4.000000)", mult->stringify());
    EXPECT_EQ(28, mult->evaluate());
    EXPECT_EQ("${({7.000000}\\cdot{4.000000})}$", latex);
}

TEST(Iterator, Sub) {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* sub = new Sub(seven, four);

    concreteVisitor* v = new concreteVisitor();
    string latex = v->PrintLateX(sub);
    EXPECT_EQ("(7.000000 - 4.000000)", sub->stringify());
    EXPECT_EQ(3, sub->evaluate());
    EXPECT_EQ("${({7.000000}-{4.000000})}$", latex);
}

TEST(Iterator, Div) {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* div = new Div(four, two);

    concreteVisitor* v = new concreteVisitor();
    string latex = v->PrintLateX(div);
    EXPECT_EQ("(4.000000 / 2.000000)", div->stringify());
    EXPECT_EQ(2, div->evaluate());
    EXPECT_EQ("${\\frac{4.000000}{2.000000}}$", latex);
}

TEST(Iterator, Pow) {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* pow = new Pow(seven, four);

    concreteVisitor* v = new concreteVisitor();
    string latex = v->PrintLateX(pow);
    EXPECT_EQ("(7.000000 ** 4.000000)", pow->stringify());
    EXPECT_EQ(2401, pow->evaluate());
    EXPECT_EQ("${({7.000000}^{4.000000})}$", latex);
}

TEST(Iterator, CombinedFunctions) {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    concreteVisitor* v = new concreteVisitor();
    string latex = v->PrintLateX(minus);
    EXPECT_EQ("((3.000000 + (7.000000 * 4.000000)) - 2.000000)", minus->stringify());
    EXPECT_EQ(29, minus->evaluate());
    EXPECT_EQ("${({({3.000000}+{({7.000000}\\cdot{4.000000})})}-{2.000000})}$", latex);
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
    EXPECT_EQ(add->stringify(), "(5.000000 + (1.000000 ** 2.000000))");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
