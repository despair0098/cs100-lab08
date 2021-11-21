#ifndef POW_HPP
#define POW_HPP


#include "base.hpp"
#include <string>
#include "math.h"

using namespace std;

class Pow: public Base{
	private:
		double value;
		Base* left;
		Base* right;
	public:
		Pow(Base* a, Base* b){value = pow(a->evaluate(),b->evaluate()); this->left = a; this->right = b;}
		virtual double evaluate() {return value;}
		virtual string stringify() {return "(" + left->stringify() + "**" +  right->stringify() + ")";}
};

#endif
