#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "visitor.hpp"
#include "concreteVisitor.hpp"
#include "iterator.hpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    concreteVisitor* v = new concreteVisitor();
    string latex = v->PrintLateX(mult);

    std::cout << mult->stringify() << " = " << mult->evaluate() << std::endl;
    std::cout << latex << std::endl;
    return 0;
}
