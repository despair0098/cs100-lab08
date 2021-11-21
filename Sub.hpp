#ifndef SUB_HPP
#define SUB_HPP


#include "base.hpp"
#include <string>

using namespace std;

class Sub: public Base{
	private:
		double value;
		Base* left;
		Base* right;
	public:
		Sub(Base* a, Base* b){value = a->evaluate() - b->evaluate(); this->left = a; this->right = b;}
		virtual double evaluate() {return value;}
		virtual string stringify() {return "(" + left->stringify() + "-" +  right->stringify() + ")";}
};

#endif
