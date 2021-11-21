#ifndef MULT_HPP
#define MULT_HPP


#include "base.hpp"
#include <string>

using namespace std;

class Mult: public Base{
	private:
		double value;
		Base* left;
		Base* right;
	public:
		Mult(Base* a, Base* b){value = a->evaluate() * b->evaluate(); this->left = a; this->right = b;}
		virtual double evaluate() {return value;}
		virtual string stringify() {return "(" + left->stringify() + "*" +  right->stringify() + ")";}
};

#endif
